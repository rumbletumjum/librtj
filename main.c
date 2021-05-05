#include <stdio.h>
#include <assert.h>

#include "linked_list.h"

#define NUM_ELEMENTS 10000

int main(void)
{
    linked_list_t *l1, *l2, *l3;

    l1 = ll_create();

    ll_push(l1, 7);
    ll_push(l1, 42);
    ll_push(l1, 69);

    assert(ll_length(l1) == 3);

    ll_print(l1);
    printf("\n");

    l2 = ll_create();

    ll_push_back(l2, 100);
    ll_push_back(l2, 69);
    ll_push_back(l2, 420);

    assert(ll_length(l2) == 3);
    ll_print(l2);

    l3 = ll_create();
    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        ll_push_back(l3, i);
    }

    assert(ll_length(l3) == NUM_ELEMENTS);

    return 0;
}
