#include <stdlib.h>

typedef struct list_item
{
    void *data;
    struct list_item *next;
} list_item;

list_item *list_append(list_item *, void *);
list_item *list_get(list_item *, unsigned int);
list_item *list_remove(list_item *, list_item *);
list_item *list_remove_by_index(list_item *, unsigned int);
list_item *list_remove_by_value(list_item *, void *);
unsigned int list_size(list_item *);