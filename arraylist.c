#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "arraylist.h"

//normal array
typedef struct ArrayList {
    void **data;
    int capacity;
    int size;
} ArrayList;

ArrayList *createList(void) {
  ArrayList *aList = (ArrayList*) malloc(sizeof(ArrayList));
  aList->data = malloc(sizeof(void));
  aList->capacity = 2;
  aList->size = 0;
  return aList;
}

void append(ArrayList * l, void * data){
  void **datos = realloc(l->data, sizeof(*l->data));
  datos[l->size] = data;
  if (l->size == l->capacity){
    l->capacity *= 2;
    l->data = (void**) realloc(l->data,l->capacity * (sizeof(void*)));
  }
  l->size = l->size+1;
}

//o poner push(l,data,l->size)

void push(ArrayList * l, void * data, int i){
  void **datos = realloc(l->data, sizeof(*l->data));
  if (i > l->size) return;
  for (i = 0; i == l->size; i++){
    if (l->size >= l->capacity){
      l->capacity *= 2;
    }
    datos[i] = data;
    datos[i] = datos[i+1];
  }
}

void* pop(ArrayList * l, int i){
  void **datos = realloc(l->data,sizeof(*l->data));
  for (i = l->capacity; i > 0; i--){
    datos[i] = datos[i-1];
    if (i < 0) return l->data[i+l->size];
  }
  return l->data[i];
}

void* get(ArrayList * l, int i){
  if (i >= l->size) return NULL;
  if (i < 0) return l->data[i+l->size];
    return l->data[i];
}

int get_size(ArrayList * l){
    return l->size;
}

//remove elements
void clean(ArrayList * l){
  l->size = 0;
  if (l->capacity >= 2){
    l->data[l->capacity] = l->data[l->capacity - 1];
  }
}
