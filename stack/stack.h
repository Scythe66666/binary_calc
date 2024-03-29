#include <stdio.h>
#include <stdlib.h>
typedef struct stack
{
    int *arr;
    int top, size;
} stack;

void stack_init(stack *s1, int size);
void stack_push(stack *s1, int data);
int stack_pop(stack *s1);
int stack_isEmpty(stack *s1);
int stack_isFull(stack *s1);
void stack_print(stack s1);
