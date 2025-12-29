/*

  LAB PROGRAM 4

  WAP to Implement Singly Linked List with following
  operations
  a) Create a linked list.
  b) Insertion of a node at first position, at any position and
  at end of list.
  Display the contents of the linked list.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

Node *create_node(int data) {
  Node *new_node = malloc(sizeof(Node));
  if (!new_node) {
    printf("Memory Allocation Failed!");
    return NULL;
  }
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

typedef struct {
  Node *head;
} List;

void insert_at_beg(List *list, int data) {
  Node *new_node = create_node(data);
  new_node->next = list->head;
  list->head = new_node;
}

void insert_at_end(List *list, int data) {
  Node *new_node = create_node(data);

  if (!list->head) {
    list->head = new_node;
    return;
  }

  Node *curr = list->head;
  while (curr->next != NULL) {
    curr = curr->next;
  }
  curr->next = new_node;
}

void insert_at_index(List *list, int data, int index) {
  if (index < 0) {
    printf("Index out of range.\n");
    return;
  }

  Node *new_node = create_node(data);

  if (index == 0) {
    new_node->next = list->head;
    list->head = new_node;
    return;
  }

  Node *curr = list->head;
  int count = 0;
  while (curr != NULL && count < index - 1) {
    curr = curr->next;
    count++;
  }

  if (curr == NULL) {
    printf("Index out of range.\n");
    free(new_node);
    return;
  }

  new_node->next = curr->next;
  curr->next = new_node;
}

void display_nodes(List *list) {
  if (!list->head) {
    printf("Empty list.\n");
    return;
  }

  Node *current = list->head;
  while (current != NULL) {
    printf("%d -> ", current->data);
    current = current->next;
  }
  printf("NULL\n");
}

int main() {
  List list;
  list.head = NULL;
  int choice, value, index;

  while (1) {
    printf("1. insert at beginning\t2. insert at index\t3. insert at end\t4. "
           "display\t5. exit\n");
    printf("Enter Choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("Enter Value: ");
      scanf("%d", &value);
      insert_at_beg(&list, value);
      break;
    case 2:
      printf("Enter Value: ");
      scanf("%d", &value);
      printf("Enter Index: ");
      scanf("%d", &index);
      insert_at_index(&list, value, index);
      break;
    case 3:
      printf("Enter Value: ");
      scanf("%d", &value);
      insert_at_end(&list, value);
      break;
    case 4:
      display_nodes(&list);
      break;
    case 5:
      exit(0);
    }
  }
  return 0;
}

/*

  OUTPUT

  1. insert at beginning  2. insert at index      3. insert at end       4.
  display      5. exit Enter Choice: 1 Enter Value: 10
  1. insert at beginning  2. insert at index      3. insert at end        4.
  display      5. exit Enter Choice: 3 Enter Value: 20
  1. insert at beginning  2. insert at index      3. insert at end        4.
  display      5. exit Enter Choice: 2 Enter Value: 15 Enter Index: 1
  1. insert at beginning  2. insert at index      3. insert at end        4.
  display      5. exit Enter Choice: 4 10 -> 15 -> 20 -> NULL
  1. insert at beginning  2. insert at index      3. insert at end        4.
  display      5. exit Enter Choice:

*/
