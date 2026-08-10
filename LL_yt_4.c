// Program to count the number of nodes in a singly linked list

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

// Function declaration (prototype)
//void count_nodes(struct node *head);
void print_data(struct node *head);

int main() {

    // Create first node
    struct node *head = malloc(sizeof(struct node));
    head->data = 22;
    head->link = NULL;

    // Create second node
    struct node *next1 = malloc(sizeof(struct node));
    next1->data = 23;
    next1->link = NULL;

    // Connect first node to second node
    head->link = next1;

    // Pass the address of the first node to the function
    print_data(head);

    // Free memory
    free(next1);
    free(head);

    return 0;
}

void print_data(struct node *head) {

    // If head is NULL, there are no nodes
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    // ptr is used to traverse the linked list.
    // Initially, ptr points to the first node.
    struct node *ptr = head;

   

    // Continue until ptr becomes NULL.
    // NULL means we have reached the end of the list.
    while (ptr != NULL) {
printf("%d ",ptr->data);

        // Move ptr to the next node
        ptr = ptr->link;
    }

}