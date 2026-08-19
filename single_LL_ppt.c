//EX-2 : C-program to store 10 values on a linked list 
//      reading the data from keyboard.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data; 		      //Data part
    struct node *next;        //Address part
}*header;
 
void createList(int n);		/* Functions to create a list*/
 
int main()
{
    int n; 
    printf("Enter the total number of nodes: ");
    scanf("%d", &n); 
    createList(n); 
    return 0;
}
void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;

    /* A node is created by allocating memory to a structure */
    newNode = (struct node *)malloc(sizeof(struct node));

    /* If unable to allocate memory for head node */
    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        printf("Enter the data of node 1: ");
        scanf("%d", &data);
 
        newNode->data = data; //Links the data field with data
        newNode->next = NULL; //Links the address field to NULL
        header = newNode;     //Header points to the first node
        temp = newNode;       //First node is the current node
        
for(i=2; i<= n; i++)
    {
      /* A newNode is created by allocating memory */
      newNode = (struct node *)malloc(sizeof(struct node));
 
      if(newNode == NULL)
      {
         printf("Unable to allocate memory.");
         break;
      }
      else
      {
         printf("Enter the data of node %d: ", i);
         scanf("%d", &data);
 
         newNode->data = data; //Links the data field of newNode with data
         newNode->next = NULL; //Links the address field of newNode with NULL
 
         temp->next = newNode; //Links previous node i.e. temp to the newNode
         temp = temp->next; 
       }
     }
   }
} 