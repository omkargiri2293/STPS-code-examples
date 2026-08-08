//Question 3: Count the Number of Nodes

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

// Function to count and print the number of nodes
void count_no_node(struct node *head) {
    int count = 0;
    if (head == NULL) {
        printf("Linked List is empty\n");
        return;
    }
    struct node *ptr = head;
    while (ptr != NULL) {
        count++;
        ptr = ptr->link;
    }
    printf("Total number of nodes: %d\n", count);
}

int main() {
    int num_nodes, val;
    struct node *head = NULL;
    struct node *ptr = NULL;

    printf("Enter the number of nodes: ");
    if (scanf("%d", &num_nodes) != 1 || num_nodes < 0) {
        printf("Invalid input.\n");
        return 1;
    }

    for (int i = 0; i < num_nodes; i++) {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &val);

        newnode->data = val;
        newnode->link = NULL;

        if (head == NULL) {
            head = newnode;
            ptr = head;
        } else {
            ptr->link = newnode;
            ptr = ptr->link;
        }
    }

    count_no_node(head);

    return 0;
}