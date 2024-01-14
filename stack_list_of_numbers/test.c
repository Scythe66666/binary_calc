#include "./stack_list.h"

int main()
{
    list l1, l2, l3, l4;
    list_init(&l1);
    list_init(&l2);
    list_init(&l3);
    list_init(&l4);

    list_add_data(&l1, 1);
    list_add_data(&l1, 2);
    list_add_data(&l1, 3);
    list_add_data(&l1, 4);

    list_add_data(&l2, 1);
    list_add_data(&l2, 2);
    list_add_data(&l2, 3);
    list_add_data(&l2, 4);

    list_add_data(&l3, 7);
    list_add_data(&l3, 8);
    list_add_data(&l3, 9);
    list_add_data(&l3, 0);

    list_add_data(&l4, 1);
    list_add_data(&l4, 2);
    list_add_data(&l4, 3);
    list_add_data(&l4, 4);


    stack_list sl;
    stack_list_init(&sl);
    stack_list_push(&sl, l1);
    stack_list_push(&sl, l2);
    stack_list_push(&sl, l3);
    stack_list_push(&sl, l4);

    l1 = stack_list_pop(&sl);
    display_list(l1);
    l1 = stack_list_pop(&sl);
    display_list(l1);
    l1 = stack_list_pop(&sl);
    display_list(l1);

    stack_list_display(sl); 
    return 0;
}
