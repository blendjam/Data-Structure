#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node * next;
}node;

void printList(node * head)
{
    node * temp = head;
    while (temp != NULL)
    {
        printf("%d-",temp->data);
        temp = temp->next;
    }
}
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

int main()
{
    node * head = NULL;
    for(int i = 0; i <= 5;i++)
    {
        push(&head,i);
    }
    //Adding at the end
    pushe(&head,30);
    //Adding after nth position
    pushn(&head,1,25);

    //Delete from first
    //pop(&head);
    //Delete from end
    //poplast(&head);
    //Delete of nth position
    //popn(&head,2);

    printList(head);
    printf("The position of 25 is %d",findnode(head,25));
    return 0;
}