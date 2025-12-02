#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
void append(Node** head, int data) {
    Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// Search for a value in the list
Node* search(Node* head, int key) {
    Node* temp = head;

    while (temp != NULL) {
        if (temp->data == key)
            return temp;  // found
        temp = temp->next;
    }

    return NULL; // not found
}

// Display list
void display(Node* head) {
    Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    Node* head = NULL;

    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);

    display(head);

    int key = 30;
    Node* result = search(head, key);

    if (result != NULL)
        printf("Found %d in the list.\n", key);
    else
        printf("%d not found in the list.\n", key);

    return 0;
}
