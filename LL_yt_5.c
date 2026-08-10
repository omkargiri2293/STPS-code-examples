//inserting the node at end of LL

#include <stdio.h>
#include<stdlib.h>

struct node{

    int data;
    struct node *link;
};

void add_at_end(struct node *head,int data);

int main(){
    struct node *head=malloc(sizeof(struct node));
    head->data=22;
    head->link=NULL;

    struct node *next=malloc(sizeof(struct node));
    next->data=33;
    next->link=NULL;
    head->link=next;

    struct node *next2=malloc(sizeof(struct node));
    next2->data=44;
    next2->link=NULL;
    next->link=next2;

    add_at_end(head,44);

    
}

void add_at_end(struct node *head,int data){
    struct node *ptr,*temp;
    temp=malloc(sizeof(struct node));

    temp->data;
    temp->link;
    while(ptr=!NULL){
     ptr = ptr->link;

    }
    ptr->link=temp;

    
}