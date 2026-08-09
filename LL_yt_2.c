//creating a single linked list 

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

int main(){
    struct node *head =malloc(sizeof(struct node));
    head->data=22;
head->link=NULL;

struct node *next1=malloc(sizeof(struct node));
next1->data=23;
next1->link=NULL;
head->link=next1;

/*
Specific pointer
int *       → "I point to an int"
char *      → "I point to a char"
struct node * → "I point to a node"

Generic pointer
void *      → "I point to something. I don't care about its type right now."
               
*/
printf("data- %d  link- %p\n",head->data,(void *)head->link);//%p prints a pointer/address.
printf("data- %d  link- %p",next1->data,(void *)next1->link);//(void *) converts the pointer to a generic pointer.
}