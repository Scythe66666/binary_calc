#ifndef LIST

#define LIST
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node node;
typedef node* list;

void list_init(list* head);

int list_add_data(list *head, int data);

int remove_data(list *head);

void display_list(list l);

void concat(list *l, list n);

node *search(list l, int data);

void list_reverse(list *head);
int insert_iteratively(list *head, int pos, int val);


void insert_recursively(list *l, int pos, int val);

#endif // !LIST
