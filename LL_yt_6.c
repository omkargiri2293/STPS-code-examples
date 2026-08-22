//inserting node at the end 

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

// Standard implementation: Takes HEAD, finds the end, appends, returns HEAD
struct node *add_at_end(struct node *head, int value) {
    struct node *temp = malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return head;
    }
    temp->data = value;
    temp->link = NULL;

    // Case 1: List is empty
    if (head == NULL) {
        return temp;
    }

    // Case 2: Traverse to the end
    struct node *current = head;
    while (current->link != NULL) {
        current = current->link;
    }

    // Attach new node
    current->link = temp;
    return head;
}

int main() {
    struct node *head = NULL; // Start with empty list

    // Now we can just pass 'head' every time
    head = add_at_end(head, 22);
    head = add_at_end(head, 98);
    head = add_at_end(head, 99);
    head = add_at_end(head, 100);

    // Traversal
    struct node *ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");

    return 0;
}