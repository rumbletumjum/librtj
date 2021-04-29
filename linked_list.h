#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct linked_list linked_list_t;

linked_list_t *ll_create();
size_t ll_length(linked_list_t *list);

void ll_push(linked_list_t *list, int value);
void ll_push_back(linked_list_t *list, int value);

void ll_print(linked_list_t *list);

#endif//LINKED_LIST_H
