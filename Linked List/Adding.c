#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node * next;
}node;




//Function to add on top of stack
void push(node **pHead, int data)
{
    node * temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = *pHead;
    *pHead = temp;
}



//Function to add after nth position
void pushn(node **pHead,int pos,int data)
{
    node * newnode = (node*)malloc(sizeof(node));
    node * temp = *pHead;
    for(int i = 0; i < pos; i++)
    {
        temp = temp->next;
    }
    newnode->data = data;
    newnode->next = temp->next;
    temp->next = newnode;
}



//Function to add at the end
void pushe(node ** head,int data)
{
    node * newdata = (node*)malloc(sizeof(node));
    node * temp = *head;
    newdata->data = data;
    newdata->next = NULL;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newdata;
}

//Fuction to find a value
int findnode(node * head,int value)
{
    node * temp = head;
    int count = 0;
    while(temp->data != value)
    {
        temp = temp->next;
        count++;
    }
    return count;
}
