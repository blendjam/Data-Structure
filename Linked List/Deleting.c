#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node * next;
}node;



//Function to pop
void pop(node ** phead)
{
    (*phead) = (*phead)->next;
}



//Delete from last
void poplast(node ** head)
{
    node *temp = *head;
    node *previous;
    while(temp->next != NULL)
    {
        previous = temp;
        temp = temp->next;
    }
    if(temp == head)
        *head = NULL;
    else
        previous->next = NULL;
}




//Delete element of nth position
void popn(node ** head,int x)
{
    node * temp = *head;
    node * previous;
    for(int i = 0; i < x; i++)
    {
        previous = temp;
        temp = temp->next;
    }
    previous->next = temp->next;
}