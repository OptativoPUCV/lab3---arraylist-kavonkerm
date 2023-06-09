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
  void **datos = realloc(l->data, l->capacity * sizeof(*l->data));
  datos[l->size] = data;
  if (l->size == l->capacity){
    l->capacity *= 2;
    l->data = (void**) realloc(l->data,l->capacity * (sizeof(void*)));
  }
  l->size = l->size+1;
}

//o poner push(l,data,l->size)

void push(ArrayList * l, void * data, int i){
  if (i > l->size) return;
  if (l->size == l->capacity){
    l->capacity *= 2;
    l->data = realloc(l->data, sizeof(void*) * l->capacity);
  }
  if (i < l->size){
    int j;
    for (j = l->size; j > i; j--){
      l->data[j] = l->data[j-1];
    }
  }
  l->data[i] = data;
  l->size++;
}

void* pop(ArrayList * l, int i){
  if (i < 0) i += l->size;
  if (i >= l->size || i < 0) return NULL;
  for (int j = i; j < l->size; j++){
    l->data[j] = l->data[j+1];
  }
  l->size--;
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
  for (int i = 0; i < l->capacity; i++){
    l->data[i] = NULL;
  }
  l->size = 0;


}
