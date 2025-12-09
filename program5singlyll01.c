#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
}Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = value;
    newNode -> next = NULL;
    return newNode;
}
void insertAtStart(Node** head, int value) {
    Node* newNode = createNode(value);
    newNode -> next = *head;
    *head = newNode;
}
void insertAtEnd(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp -> next != NULL) {
        temp = temp -> next;
    }
    temp -> next = newNode;
}
void insertAtPos(Node** head, int value, int pos) {
    if (pos<1) {
        printf("Position out of range!");
        return;
    }
    if (pos==1) {
        insertAtStart(head, value);
        return;
    }
    Node* newNode = createNode(value);
    Node* temp = *head;
    for(int i = 1; i < pos-1; i++) {
        if (temp==NULL) {
            printf("Position out of range!\n");
            return;
        }
        temp = temp -> next;
    }
    if (temp==NULL) {
        printf("Position out of range!\n");
        return;
    }
    newNode -> next = temp -> next;
    temp -> next = newNode;
}
void printList(Node* head) {
    Node* temp = head;
    printf("Linked List: ");
    while (temp!=NULL) {
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }
    printf("NULL\n");
}
void main() {
    Node *head = NULL;
    insertAtStart(&head, 20);
    insertAtStart(&head, 25);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 35);
    insertAtPos(&head, 40, 3);

    printList(head);
}
