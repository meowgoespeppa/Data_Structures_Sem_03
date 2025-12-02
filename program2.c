#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node with given data
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

// Function to display the doubly linked list with pointer addresses
void displayList(struct Node* head) {
    struct Node* temp = head;

    printf("\nDoubly Linked List Structure:\n");
    printf("-------------------------------------------------------------\n");
    printf("| %-14s | %-14s | %-5s | %-14s |\n", "Node Addr", "Prev Addr", "Data", "Next Addr");
    printf("-------------------------------------------------------------\n");

    while (temp != NULL) {
        printf("| %-14p | %-14p | %-5d | %-14p |\n",
               (void*)temp,
               (void*)temp->prev,
               temp->data,
               (void*)temp->next);
        temp = temp->next;
    }

    printf("-------------------------------------------------------------\n");
}

int main() {
    // Step 1: Create 5 independent nodes
    struct Node* N1 = createNode(1);
    struct Node* N2 = createNode(2);
    struct Node* N3 = createNode(3);
    struct Node* N4 = createNode(4);
    struct Node* N5 = createNode(5);

    // Step 2: Link nodes to form the doubly linked list
    N1->next = N2;
    N2->prev = N1;

    N2->next = N3;
    N3->prev = N2;

    N3->next = N4;
    N4->prev = N3;

    N4->next = N5;
    N5->prev = N4;

    // Step 3: Display the list with pointer addresses
    displayList(N1);

    // Step 4: Cleanup - Free allocated memory
    free(N1);
    free(N2);
    free(N3);
    free(N4);
    free(N5);

    return 0;
}
