#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert node at the beginning
void insertAtStart(struct Node **head, int data) {
    struct Node *newNode = createNode(data);

    newNode->next = *head;
    *head = newNode;
}

// Insert node at the end
void insertAtEnd(struct Node **head, int data) {
    struct Node *newNode = createNode(data);
    struct Node *temp;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    temp = *head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Print the linked list
void display(struct Node *head) {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Linked list: ");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;

    insertAtStart(&head, 05);
    insertAtStart(&head, 10);
    insertAtEnd(&head, 22);
    insertAtEnd(&head, 80);

    display(head);

    return 0;
}