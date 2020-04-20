#include <stdio.h>
#include <stdlib.h>
//Update for git hub
typedef struct node {
    int data ;
    struct node * next;
}node;


//Function to print the list
void printList(node * head)
{
    node * temp = head;
    while(temp != NULL)
    {
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

//Function to push the data
void push(node ** phead, int data)
{
    node * temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = *phead;
    *phead = temp;
}
//Function to push to the end
void pushe(node ** pHead, int data)
{
    node * newdata = (node*)malloc(sizeof(node));
    node * temp = *pHead;
    newdata->data = data;
    newdata->next = NULL;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newdata;
}
//Function to add afte nth position
void pushn(node ** phead,int data,int pos)
{
    node * temp = *phead;
    node * newdata = (node*)malloc(sizeof(node));
    newdata->data = data;
    for(int i = 0; i < pos; i++)
    {
        temp = temp->next;
    }
    newdata->next = temp->next;
    temp->next = newdata;
}
//Function to delete from first
void pop(node ** head)
{
    *head = (*head)->next;
}
//Function to delete element of last
void pope(node ** head)
{
    node *temp = *head;
    node * previous = (node*)malloc(sizeof(node));
    while(temp->next != NULL)
    {
        previous = temp;
        temp = temp->next;
    }
    previous->next = NULL;
    free(temp);
}
//Function to delete element of nth position
void popn(node ** head,int pos)
{
    node * temp = *head;
    node * previous = (node*)malloc(sizeof(node));
    for(int i = 0; i < pos; i++ )
    {
        previous = temp;
        temp = temp->next;
    }
    previous->next = temp->next;
}
//Function to count the elements in the list
int count(node ** head)
{
    int count = 0;
    node * temp = *head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    

}
void bubblesort(node * head)
{

}
int main()
{
    node * head = NULL;
    for(int i = 0; i < 5; i++)
    {
        push(&head,i);
    }
    pushn(&head,25,1);
    printf("The reverse is : \n");
    printList(head);
    pop(&head);
    printf("After Popping : \n");
    printList(head);
    pope(&head);
    printf("After popping from end : \n");
    printList(head);
    popn(&head,1);
    printf("After popping from 1st position\n");
    printList(head);
}