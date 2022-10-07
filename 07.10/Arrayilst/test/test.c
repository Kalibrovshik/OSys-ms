#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include "arraylist.h"


void print_list(array_list_t *obj) {
  if (!obj) return;

  printf("arraylist at: %p\n", obj);
  printf("obj.size    : %d\n", obj->size);
  printf("obj.count   : %d\n", obj->count);
  printf("obj.array   : %p {\n\t", obj->array);
  for (int i = 0;i < obj->count; i++) {
    printf("%-5d ", obj->get(obj, i));
    if ((i+1) % 8 == 0) printf("\n\t");
  }
  printf("\n}\n\n");
}

int mymain()
{
  array_list_t *obj = new_arraylist(3);
  assert(obj);

  srand(time(0));

  print_list(obj);

  for (int i = 0;i < 3; i++) {
    obj->add_at(obj, i, rand() % 23);
  }

  print_list(obj);

  for (int i = 0;i < 20; i++) {
    obj->add(obj, rand() % 23);
  }

  print_list(obj);

  destroy_arraylist(obj);

  obj = NULL;
  return 0;
}