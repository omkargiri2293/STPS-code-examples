#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Insert at beginning
void insertAtBeginning(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Insert at end
void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
}

// Delete node by key
void deleteNode(struct Node** head_ref, int key) {
    struct Node *temp = *head_ref, *prev;

    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

// Search for a node
int searchNode(struct Node** head_ref, int key) {
    struct Node* current = *head_ref;
    while (current != NULL) {
        if (current->data == key) return 1;
        current = current->next;
    }
    return 0;
}

// Print the list
void printList(struct Node* node) {
    while (node != NULL) {
        printf(" %d ", node->data);
        node = node->next;
    }
}

int main() {
    struct Node* head = NULL;

    // Operations
    insertAtEnd(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);
    insertAtEnd(&head, 4);

    printf("Linked list: ");
    printList(head);

    deleteNode(&head, 3);
    printf("\nAfter deleting 3: ");
    printList(head);

    if (searchNode(&head, 4))
        printf("\n4 is found");   