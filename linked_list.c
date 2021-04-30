#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"


ll_node_t *create_node(int value)
{
    ll_node_t *result = malloc(sizeof(ll_node_t));
    result->value = value;
    result->next = NULL;
    result->prev = NULL;

    return result;
}

linked_list_t *ll_create()
{
    linked_list_t *new_list = malloc(sizeof(linked_list_t));
    ll_init(new_list);

    return new_list;
}

void ll_init(linked_list_t *list)
{
    list->length = 0;
    list->head = NULL;
    list->tail = NULL;
}

size_t ll_length(const linked_list_t *list)
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

ll_node_t *ll_node_navigate(ll_node_t *node, int index)
{
    int i = 0;
    while (i < index) {
        node = node->next;
        i++;
    }
    return node;
}

void ll_print(linked_list_t *list)
{
    ll_node_t *tmp = list->head;

    while (tmp != NULL) {
        printf("%d\n", tmp->value);
        tmp = tmp->next;
    }
}
