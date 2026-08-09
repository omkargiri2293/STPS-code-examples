// Creating a node in C

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;

};

int main(){
    struct node *head;
    head=(struct node *)malloc(sizeof(struct node));
    head->data=22;
    head->link=NULL;

    printf("%d\n",head->data);
    printf("%s",head->link);
    return 0;
}