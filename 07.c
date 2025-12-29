/*

  LAB PROGRAM 7

  WAP to Implement doubly link list with primitive
  operations
  a) Create a doubly linked list.
  b) Insert a new node to the left of the node.
  c) Delete the node based on a specific value
  d) Display the contents of the list

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next, *prev;
} Node;

Node *create_node(int data) {
  Node *new_node = malloc(sizeof(Node));
  if (!new_node) {
    printf("Memory Allocation Failed!");
    return NULL;
  }
  new_node->data = data;
  new_node->next = NULL;
  new_node->prev = NULL;
  return new_node;
}

typedef struct {
  Node *head;
} List;

void insert_at_beg(List *list, int data) {
  Node *new_node = create_node(data);
  new_node->next = list->head;

  if (list->head) {
    list->head->prev = new_node;
  }

  list->head = new_node;
}

void delete_data(List *list, int data) {
  if (!list->head) {
    printf("Empty list.\n");
    return;
  }

  if (list->head->data == data) {
    Node *temp = list->head;
    list->head = list->head->next;
    free(temp);
    if (list->head)
      list->head->prev = NULL;
    return;
  }

  Node *current = list->head;
  while (current->next != NULL && current->next->data != data) {
    current = current->next;
  }
  if (current->next == NULL) {
    printf("Data not found\n");
    return;
  }

  Node *temp = current->next;
  current->next = temp->next;
  if (current->next)
    current->next->prev = current;
  free(temp);
}

void display_nodes(List *list) {
  if (!list->head) {
    printf("Empty list.\n");
    return;
  }

  printf("NULL ");
  Node *current = list->head;
  while (current != NULL) {
    printf("<- %d -> ", current->data);
    current = current->next;
  }
  printf("NULL\n");
}

int main() {
  List list;
  list.head = NULL;
  int choice, value;

  while (1) {
    printf("1. Insert\t2. Delete Data\t3. Display\t4. Exit\n");
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
      delete_data(&list, value);
      break;
    case 3:
      display_nodes(&list);
      break;
    case 4:
      exit(0);
    }
  }
  return 0;
}

/*

  OUTPUT

  1. Insert       2. Delete Data  3. Display      4. Exit
  Enter Choice: 1
  Enter Value: 10
  1. Insert       2. Delete Data  3. Display      4. Exit
  Enter Choice: 1
  Enter Value: 20
  1. Insert       2. Delete Data  3. Display      4. Exit
  Enter Choice: 1
  Enter Value: 30
  1. Insert       2. Delete Data  3. Display      4. Exit
  Enter Choice: 3
  NULL <- 30 -> <- 20 -> <- 10 -> NULL
  1. Insert       2. Delete Data  3. Display      4. Exit
  Enter Choice: 2
  Enter Value: 20
  1. Insert       2. Delete Data  3. Display      4. Exit
  Enter Choice: 3
  NULL <- 30 -> <- 10 -> NULL
  1. Insert       2. Delete Data  3. Display      4. Exit
  Enter Choice: 4

*/
