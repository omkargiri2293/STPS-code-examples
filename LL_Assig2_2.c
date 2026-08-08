//Question 2: Compare Two Linked Lists (Same Data, Different Order)


#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

// Function to check if two lists have the same data elements
int compare_lists(struct node *a, struct node *b) {
    struct node *ptr1, *ptr2;
    int count1 = 0, count2 = 0;
    int found;

    // Count nodes in list A
    ptr1 = a;
    while (ptr1 != NULL) {
        count1++;
        ptr1 = ptr1->link;
    }

    // Count nodes in list B
    ptr2 = b;
    while (ptr2 != NULL) {
        count2++;
        ptr2 = ptr2->link;
    }

    // If lengths differ, they can't be the same
    if (count1 != count2) {
        return 0;
    }

    // Check if every element in A exists in B
    ptr1 = a;
    while (ptr1 != NULL) {
        found = 0;
        ptr2 = b;
        while (ptr2 != NULL) {
            if (ptr1->data == ptr2->data) {
                found = 1;
                break;
            }
            ptr2 = ptr2->link;
        }
        if (!found) return 0; // Element from A not found in B
        ptr1 = ptr1->link;
    }

    return 1;
}

int main() {
    struct node *head1 = NULL;
    struct node *head2 = NULL;

    // List 1: 5 -> 4 -> 3 -> 2 -> 1
    struct node *n1 = (struct node*)malloc(sizeof(struct node)); n1->data = 5; n1->link = NULL; head1 = n1;
    struct node *n2 = (struct node*)malloc(sizeof(struct node)); n2->data = 4; n2->link = NULL; n1->link = n2;
    struct node *n3 = (struct node*)malloc(sizeof(struct node)); n3->data = 3; n3->link = NULL; n2->link = n3;
    struct node *n4 = (struct node*)malloc(sizeof(struct node)); n4->data = 2; n4->link = NULL; n3->link = n4;
    struct node *n5 = (struct node*)malloc(sizeof(struct node)); n5->data = 1; n5->link = NULL; n4->link = n5;

    // List 2: 1 -> 2 -> 3 -> 4 -> 5 (Same data, different order)
    struct node *n6 = (struct node*)malloc(sizeof(struct node)); n6->data = 1; n6->link = NULL; head2 = n6;
    struct node *n7 = (struct node*)malloc(sizeof(struct node)); n7->data = 2; n7->link = NULL; n6->link = n7;
    struct node *n8 = (struct node*)malloc(sizeof(struct node)); n8->data = 3; n8->link = NULL; n7->link = n8;
    struct node *n9 = (struct node*)malloc(sizeof(struct node)); n9->data = 4; n9->link = NULL; n8->link = n9;
    struct node *n10 = (struct node*)malloc(sizeof(struct node)); n10->data = 5; n10->link = NULL; n9->link = n10;

    if (compare_lists(head1, head2)) {
        printf("Lists have same data\n");
    } else {
        printf("Lists have different data\n");
    }

    return 0;
}