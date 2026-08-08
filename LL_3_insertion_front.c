//Inserting a node at the beginning of a linked list

/*Algorithm
1. Declare a head pointer and make it as NULL.
2. Create a new node with the given data.
3. Make the new node points to the head node.
4. Finally, make the new node as the head node.
*/
#include<stdio.h>
#include<stdlib.h>

//1
struct node{
    int data;
    struct node *next;
};

struct node *head = NULL ;


void add_first_node( struct node **head ,int value){
//2
    struct node *newNode = malloc (sizeof(struct node));
    newNode->data=value;

//3
newNode->next = *head;

//4

*head = newNode;

}
void printList(struct node *head)
{
    struct node *temp = head;

    //iterate the entire linked list and print the data
    while(temp != NULL)
    {
         printf("%d->", temp->data);
         temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
     struct node *head = NULL;

     addFirst(&head,10);
     addFirst(&head,20);
     addFirst(&head,30);

     printList(head);

     return 0;
}

