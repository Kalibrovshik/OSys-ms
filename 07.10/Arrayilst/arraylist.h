#ifndef MS_ARRAYLIST_H
#define MS_ARRAYLIST_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct array_list_t {
    int *array;
    int size;
    int count;
    void (*add)(struct array_list_t *self, int item);
    void (*add_at)(struct array_list_t *self, int index, int item);
    bool (*contains)(struct array_list_t *self, int elem);
    void (*clear)(struct array_list_t *self);
    int (*get)(struct array_list_t *self, int index);
    void (*remove_at)(struct array_list_t *self, int index);
    void (*remove)(struct array_list_t *self, int elem);
}array_list_t;

array_list_t *new_arraylist(const int list_size);
void destroy_arraylist(array_list_t *obj);


#ifdef __cplusplus
}
#endif

#endif
