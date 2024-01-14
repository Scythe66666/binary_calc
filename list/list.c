#include "list.h"


void list_init(list* head)
{
    *head = NULL;
}

int list_add_data(list *head, int data)
{
    node * temp = (node *)malloc(sizeof(node));
    if(!temp)
        return INT_MIN;
    temp->data = data;
    temp->next = NULL;
    
    if(*head == NULL)
    {
        *head = temp;
        return 1;
    }

    node * traverse = *head;
    while(traverse->next) traverse = traverse ->next;
    
    traverse->next = temp; 
    return 1;
}

int list_remove_data(list *head)
{
    if(*head == NULL)
        return INT_MIN;
    
    if((*head)->next == NULL)
    {
        int temp = (*head)->data;
        free(*head);
        *head = NULL;
        return temp;
    }

    node * traverse = *head;
    while((traverse->next)->next) traverse = traverse ->next;
    
    int temp = (traverse->next)->data;
    free(traverse->next);
    traverse->next = NULL;
    return temp;
}

void list_data(list l)
{
    printf("[ ");
    while(l)
    {
        printf("%d, ", l->data);
        l = l->next;
    }
    printf("]\n");
}

void list_concat(list *l, list b)
{
    while(b)
    {
        list_add_data(l, b->data);
        b = b->next;
    }
}

node * lsit_search(list l, int data)
{
    while(l)
    {
        if(l->data == data)
            return l;
        l = l->next;
    }
    return NULL;
}

void list_reverse(list *head)
{
    if(*head == NULL || (*head)->next == NULL)
        return ;

    node *curr = *head;
    node *prev = NULL;
    
    while(curr)
    {
        node * temp = curr->next;
        curr ->next = prev;
        prev = curr;
        curr = temp; 
    }

    *head = prev;
}
//give pos as 1 to enter at the begining of the list
//     int insert_iteratively(list *head, int pos, int val)
//     {
//     if(pos <= 1)
//     {
//         node *temp = (node *)malloc(sizeof(node));
//         if(!temp)
//             return INT_MIN;
//
//         temp->data = val;
//         temp->next = *head;
//         *head = temp; 
//         return 1;
//     }
//
//     if(*head == NULL)
//         return INT_MIN;
//
//     node *traverse = *head;
//     int count = 1;
//     while(count++ < pos - 1)
//     {
//         if(traverse == NULL)
//             return INT_MIN;
//         traverse = traverse->next;       
//     }
//     
//     node *temp = (node *)malloc(sizeof(node));
//     if(!temp)
//         return INT_MIN;
//
//     temp->data = val;
//     temp->next = traverse->next;
//     traverse->next = temp; 
//     return 1;
// }


int list_insert_iteratively(list *head, int pos, int val)
{
    list *traverse = head;
    while(pos != 1)
    {
        if(*traverse == NULL)
            return INT_MIN;
        traverse = &((*traverse) -> next);
        pos--;
    }
    node *temp = (node *)malloc(sizeof(node));
    temp->next = *traverse;
    temp->data = val;
    *traverse = temp;
    return 1;
}

void insert_recursively(list *l, int pos, int val)
{
    if(*l == NULL)
    {
        return ;
    }
    if(pos == 1)
    {
        node *temp = (node *)malloc(sizeof(node));
        temp->next = *l;
        temp->data = val;
        *l = temp;
        return ;
    }
    
    insert_recursively(&((*l) -> next), pos -1, val);
}
