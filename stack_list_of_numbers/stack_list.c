#include "stack_list.h"
#include <stdio.h>

void stack_list_init(stack_list *s) { 
    *s = NULL;
}

void stack_list_push(stack_list *s1, list l)
{
    stack_list_node *temp = malloc(sizeof(stack_list_node));
    if (!temp)
        return;
    temp->l = l;
    temp->next = *s1;
    *s1 = temp;
}

list stack_list_pop(stack_list * s1)
{
    if (stack_list_isEmpty(*s1))
        return NULL;

    stack_list_node *temp = *s1;
    *s1 = (*s1)->next;
    list l = temp->l;
    return l;
}

int stack_list_isEmpty(stack_list s1)
{
    if (s1 == NULL)
        return 1;
    return 0;
}

void stack_list_display(stack_list s1)
{
    if(s1 == NULL)
        return ;
    stack_list_node* traverse = s1;
    while (traverse) {
        display_list(traverse->l);
        traverse = traverse->next;
        printf("\n");
    }
}
