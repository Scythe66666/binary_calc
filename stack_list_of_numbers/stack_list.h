#include "../list/list.h"
#include <stdio.h>
#include <stdlib.h>
struct stack_list_node
{
    int sign ;
    list l;
    struct stack_list_node *next;
};
#define POSITIVE 1
#define NEGATIVE -1

typedef struct stack_list_node stack_list_node;
typedef stack_list_node *stack_list;

void stack_list_init(stack_list *s1);
void stack_list_push(stack_list *s1, list data);
list stack_list_pop(stack_list *s1);
int stack_list_isEmpty(stack_list s1);
void stack_list_printStack(stack_list *s1);
void stack_list_display(stack_list s1);
void stack_list_change_sign(stack_list *s1);
