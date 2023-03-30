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
    l->data = realloc(l->data,l->capacity * (sizeof(void)));
  }
  l->size = l->size+1;
}

void push(ArrayList * l, void * data, int i){
  void **datos = realloc(l->data, sizeof(*l->data));
  if (l->size == l->capacity){
    l->capacity *= 2;
    for (i = 0; i < l->capacity; i++){
      datos[i] = data;
      if (i > l->size) break;
    }
  }
  l->size = l->size+1;
}

void* pop(ArrayList * l, int i){
    return NULL;
}

void* get(ArrayList * l, int i){
    return NULL;
}

int get_size(ArrayList * l){
    return l->size;
}

//remove elements
void clean(ArrayList * l){
    
}
