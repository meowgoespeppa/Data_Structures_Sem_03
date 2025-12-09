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
void printList(Node* head) {
    Node* temp = head;
    printf("Linked List: ");
    while (temp!=NULL) {
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }
    printf("NULL\n");
}
void deleteAtStart(Node** head) {
    if (*head == NULL) {
        printf("List is empty!");
        return;
    }
    Node* temp = *head;
    *head = (*head) -> next;
    free(temp);
}
void deleteAtEnd(Node** head) {
    if (*head == NULL) {
        printf("List is empty!");
        return;    
    }
    if ((*head)-> next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp -> next;
    }
    free(temp->next);
    temp->next=NULL;
}
void deleteAtPos(Node** head, int pos) {
    if (*head == NULL) {
        printf("List is empty!");
        return;    
    }
    if (pos<1) {
        printf("Position out of range!");
        return;
    }
    if (pos==1) {
        deleteAtStart(head);
        return;
    } 
    Node* temp = *head;
    for(int i=1; i<pos-1; i++) {
        if (temp == NULL || temp->next == NULL) {
            printf("Position out of range!\n");
            return;
        }
        temp = temp->next;
    }
    struct Node* nodeToDelete = temp->next;
    if (nodeToDelete == NULL) {
        printf("Position out of range!\n");
        return;
    }
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
}
int main() {
    Node* head = NULL;
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);
    printList(head);
    deleteAtStart(&head);
    printList(head);
    deleteAtEnd(&head);
    printList(head);
    deleteAtPos(&head, 2); 
    printList(head);
    return 0;
}