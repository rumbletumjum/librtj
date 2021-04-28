#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>

#define new(type, n) ((type *) new_it_up((n) * sizeof(type)))

//typedef uint

typedef struct ll_node ll_node_t;
struct ll_node {
    int value;
    struct ll_node *next;
};

typedef struct linked_list linked_list_t;
struct linked_list {
    size_t length;
    ll_node_t *head;
};

void die(const char *msg)
{
    if (errno) {
        perror(msg);
    } else {
        fprintf(stderr, "ERROR: %s\n", msg);
    }
    exit(1);
}

void *new_it_up(size_t sz)
{
    void *result = malloc(sz);
    if (!result) {
        die("new_it_up: allocation error");
    }
    return result;
}

ll_node_t *create_node(int value)
{
    ll_node_t *result;

    //result = malloc(sizeof(ll_node_t));
    result = new(ll_node_t, 1);
    result->value = value;
    result->next = NULL;

    return result;
}

void linked_list_init(linked_list_t *ll)
{
    ll->length = 0;
    ll->head = NULL;
}

linked_list_t *ll_create()
{
    linked_list_t *new_list = new(linked_list_t, 1);
    linked_list_init(new_list);
    return new_list;
}

void ll_push(linked_list_t *list, int value)
{
    ll_node_t *new_node = create_node(value);

    if (list->head == NULL && list->length == 0) {
        list->head = new_node;
        list->length++;
    } else {
        new_node->next = list->head;
        list->head = new_node;
        list->length++;
    }
}

void print_list(linked_list_t *list)
{
    ll_node_t *tmp = list->head;

    while (tmp != NULL) {
        printf("%d\n", tmp->value);
        tmp = tmp->next;
    }
}

int main(void)
{
    ll_node_t n1, n2, n3;
    linked_list_t stack_allocated_list;
    linked_list_t *list;

    list = ll_create();

    ll_push(list, 7);
    ll_push(list, 42);
    ll_push(list, 69);

    assert(list->length == 3);

    linked_list_init(&stack_allocated_list);

    ll_push(&stack_allocated_list, 100);
    ll_push(&stack_allocated_list, 69);
    ll_push(&stack_allocated_list, 420);

    assert(stack_allocated_list.length == 3);

    print_list(&stack_allocated_list);
    
    return 0;
}
