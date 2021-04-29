#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

typedef struct ll_node ll_node_t;
struct ll_node {
    int value;
    struct ll_node *next;
};

struct linked_list {
    size_t length;
    ll_node_t *head;
    ll_node_t *tail;
};

ll_node_t *create_node(int value)
{
    ll_node_t *result = malloc(sizeof(ll_node_t));
    result->value = value;
    result->next = NULL;

    return result;
}

linked_list_t *ll_create()
{
    linked_list_t *new_list = malloc(sizeof(linked_list_t));
    new_list->length = 0;
    new_list->head = NULL;
    new_list->tail = NULL;

    return new_list;
}

size_t ll_length(linked_list_t *list)
{
    return list->length;
}

void ll_push(linked_list_t *list, int value)
{
    ll_node_t *new_node = create_node(value);

    if (list->head == NULL && list->length == 0) {
        list->head = new_node;
        list->tail = new_node;
        list->length++;
    } else {
        new_node->next = list->head;
        list->head = new_node;
        list->length++;
    }
}

void ll_push_back(linked_list_t *list, int value)
{
    ll_node_t *node = create_node(value);
    ll_node_t *tail = list->tail;

    if (tail)
        tail->next = node;
    else
        list->head = node;

    list->tail = node;
    list->length++;
}

void ll_print(linked_list_t *list)
{
    ll_node_t *tmp = list->head;

    while (tmp != NULL) {
        printf("%d\n", tmp->value);
        tmp = tmp->next;
    }
}
