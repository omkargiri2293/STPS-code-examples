// Simple singly linked list example using student records.

#include <stdio.h>

// Structure definition for a node in the linked list.
struct stud {
    int roll;          // Student roll number
    char name[30];     // Student name
    int age;           // Student age
    struct stud *next; // Pointer to the next node in the list
};

int main();

main() {
    // Create three student nodes.
    struct stud n1, n2, n3;
    struct stud *p; // Pointer used to traverse the linked list.

    // Read data for the three students.
    scanf("%d %s %d", &n1.roll, n1.name, &n1.age);
    scanf("%d %s %d", &n2.roll, n2.name, &n2.age);
    scanf("%d %s %d", &n3.roll, n3.name, &n3.age);

    // Link the nodes to form a chain: n1 -> n2 -> n3 -> NULL
    n1.next = &n2;
    n2.next = &n3;
    n3.next = NULL;

    // Start traversal from the first node.
    p = &n1;

    // Print all student records until the end of the list is reached.
    while (p != NULL) {
        printf("\n roll=%d name=%s age=%d", p->roll, p->name, p->age);
        p = p->next;
    }
}
