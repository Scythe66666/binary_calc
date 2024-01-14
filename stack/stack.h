#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
typedef struct stack
{
    int *arr;
    int top, size;
} stack;

void init(stack *s1);
void push(stack *s1, int data);
int pop(stack *s1);
int isEmpty(stack *s1);
int isFull(stack *s1);
void printStack(stack *s1);
