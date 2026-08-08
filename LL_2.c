// creating a single linked list 

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data ;
    struct node *next;

}*header;

void createList(int n);

int main(){
    int n;
    printf("enter the total no of nodes ");
    scanf("%d ",&n);
    createList(n);
    return 0;
}

void createList(int n){
    struct node *newNode , *temp;
    int data ,i;

    newNode =(struct node*)malloc(sizeof(struct node));

    if(newNode==NULL){
        printf("unable to allocate memory");

    }
    else{
        printf("printf the data of node n1: ");
        scanf("%d",&data);

        newNode->data=data;
        newNode->next=NULL;
        header=newNode;
        temp=newNode;


    }

    for(i=2;i<=n;i++){
            newNode =(struct node*)malloc(sizeof(struct node));

             if(newNode==NULL){
        printf("unable to allocate memory");

        break;
    }
    else{
        printf("printf the data of node %d: ",i);
       scanf("%d",&data);

        newNode->data=data;
        newNode->next=NULL;
        temp->next=newNode;
        newNode= temp->next;
            }
        
        }
    }
