#include <stdlib.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>
#include "arraylist.h"

static void add_elem(struct array_list_t *self, int item) {
    if (!self) return;

    if (self->count == self->size) { // time to grow arraylist
        self->size *= 2;
        self->array = (int *)realloc(self->array, self->size * sizeof(int));
        assert(self->array);
    }
    self->array[self->count++] = item;
}

static void add_elem_at(struct array_list_t *self, int index, int item) {
    if (!self) return;

    if (self->count == self->size) { 
        self->size *= 2;
        self->array = (int *)realloc(self->array, self->size * sizeof(int));
        assert(self->array);
    }
    if (index == self->count) {
        self->array[self->count++] = item;
    }
    else {
        for (int i = index; i < self->count; i++) {
            int temp = self->array[i];
            self->array[i] = item;
            item = temp;
        }
        self->array[self->count++] = item;
    }
}

static bool contains(struct array_list_t *self, int elem) {
    if (!self) return false;

    for (int i = 0; i < self->count; i++) {
        if (self->array[i] == elem)
            return true;
    }
    return false;
}

static void clear(struct array_list_t *self) {
    if (!self) return;
    self->count = 0;
}

static int get(struct array_list_t *self, int index) {
    if (!self || index >= self->count) return -1;

    return self->array[index];
}

static void remove_elem_at(struct array_list_t *self, int index) {
    if (!self || index >= self->count) return;

    for (int i = index; i < self->count-1; i++) {
        self->array[i] = self->array[i+1];
    }
    self->count--;
}

static void remove_elem(struct array_list_t *self, int elem) {
    if (!self) return;
    for (int i = 0; i < self->count; i++) {
        if (self->array[i] == elem) {
            for (int j = i; j < self->count-1; j++) {
                self->array[j] = self->array[j+1];
            }
            self->count--;
            return;
        }
    }
}


array_list_t *new_arraylist(const int list_size) {
    if (!list_size) return NULL;

    array_list_t *obj = (array_list_t *)malloc (sizeof(array_list_t));
    assert(obj);
    obj->array = (int *)malloc(list_size * sizeof(int));
    assert(obj->array);

    obj->size     = list_size;
    obj->add      = add_elem;
    obj->add_at   = add_elem_at;
    obj->contains = contains;
    obj->clear    = clear;
    obj->get      = get;
    obj->remove_at= remove_elem_at;
    obj->remove   = remove_elem;

    return obj;
}

void destroy_arraylist(array_list_t *obj) {
    if (!obj) return;
    free(obj->array);
    free(obj);
}
