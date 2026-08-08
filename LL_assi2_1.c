//Question 1: Concatenate Two Linked Lists

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

// Function to concatenate list 'b' to the end of list 'a'
struct node* concatenate(struct node *a, struct node *b) {
    if (a == NULL) return b;
    
    struct node *ptr = a;
    while (ptr->link != NULL) {
        ptr = ptr->link;
    }
    ptr->link = b;
    return a;
}

int main() {
    struct node *head1 = NULL;
    struct node *head2 = NULL;

    // Creating List 1: 5 -> 4 -> 3
    struct node *newnode1 = (struct node*)malloc(sizeof(struct node));
    newnode1->data = 5;
    newnode1->link = NULL;
    head1 = newnode1;

    struct node *newnode2 = (struct node*)malloc(sizeof(struct node));
    newnode2->data = 4;
    newnode2->link = NULL;
    newnode1->link = newnode2;

    struct node *newnode3 = (struct node*)malloc(sizeof(struct node));
    newnode3->data = 3;
    newnode3->link = NULL;
    newnode2->link = newnode3;

    // Creating List 2: 2 -> 1
    struct node *newnode4 = (struct node*)malloc(sizeof(struct node));
    newnode4->data = 2;
    newnode4->link = NULL;
    head2 = newnode4;

    struct node *newnode5 = (struct node*)malloc(sizeof(struct node));
    newnode5->data = 1;
    newnode5->link = NULL;
    newnode4->link = newnode5;

    // Concatenate the lists
    head1 = concatenate(head1, head2);

    // Print the merged list
    printf("Merged List: ");
    struct node *ptr = head1;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");

    return 0;
}