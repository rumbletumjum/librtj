#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct linked_list linked_list_t;
typedef struct ll_node ll_node_t;

struct ll_node {
    int value;
    struct ll_node *next;
    struct ll_node *prev;
};

struct linked_list {
    size_t length;
    ll_node_t *head;
    ll_node_t *tail;
};

linked_list_t *ll_create();
void ll_init(linked_list_t *list);

size_t ll_length(const linked_list_t *list);

void ll_push(linked_list_t *list, int value);
void ll_push_back(linked_list_t *list, int value);

void ll_print(linked_list_t *list);

//ll_node_t *ll_node_navigate(ll_node_t *node, int index)

#endif//LINKED_LIST_H
