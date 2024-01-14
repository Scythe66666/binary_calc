#include "stack.h"
#include <stdio.h>

void init(stack *s)
{
    s->size = SIZE;
    s->arr = (int *)malloc(sizeof(int) * s->size);
    s->top = -1;
}

void push(stack *s1, int data)
{
    if (isFull(s1))
    {
        return;
    }
    s1->arr[s1->top + 1] = data;
    s1->top = s1->top + 1;
}

int pop(stack *s1)
{
    if (isEmpty(s1))
    {
        return -1;
    }
    s1->top--;
    return s1->arr[s1->top + 1];
}

int isEmpty(stack *s1)
{
    if (s1->top == -1)
        return 1;
    return 0;
}

int isFull(stack *s1)
{
    if (s1->top == s1->size - 1)
        return 1;
    return 0;
}

void printStack(stack *s1)
{
    for (int i = 0; i < s1->top; i++)
        printf("%d\t", s1->arr[i]);
    printf("\n");
}
