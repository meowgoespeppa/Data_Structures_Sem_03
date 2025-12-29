/*

  LAB PROGRAM 5

  WAP to Implement Singly Linked List with following
  operations
  a) Create a linked list.
  b) Deletion of first element, specified element and last
  element in the list.
  c) Display the contents of the linked list

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

void delete_at_beg(List *list) {
  if (!list->head) {
    printf("Empty list.\n");
    return;
  }

  Node *temp = list->head;
  list->head = temp->next;
  free(temp);
}

void delete_at_end(List *list) {
  if (!list->head) {
    printf("Empty list.\n");
    return;
  }
  if (!list->head->next) {
    free(list->head);
    list->head = NULL;
    return;
  }

  Node *curr = list->head;
  while (curr->next->next != NULL) {
    curr = curr->next;
  }
  Node *temp = curr->next;
  curr->next = NULL;
  free(temp);
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
  free(temp);
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
  int choice, value;

  while (1) {
    printf("1. insert\t2. delete at beggining\t3. delete data\t4. delete at "
           "end\t5. display\t6. exit\n");
    printf("Enter Choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("Enter Value: ");
      scanf("%d", &value);
      insert_at_beg(&list, value);
      break;
    case 2:
      delete_at_beg(&list);
      break;
    case 3:
      printf("Enter Value: ");
      scanf("%d", &value);
      delete_data(&list, value);
      break;
    case 4:
      delete_at_end(&list);
      break;
    case 5:
      display_nodes(&list);
      break;
    case 6:
      exit(0);
    }
  }
  return 0;
}

/*

  OUTPUT

  1. insert       2. delete at beggining  3. delete data  4. delete at end 5.
  display  6. exit Enter Choice: 1 Enter Value: 10
  1. insert       2. delete at beggining  3. delete data  4. delete at end 5.
  display  6. exit Enter Choice: 1 Enter Value: 20
  1. insert       2. delete at beggining  3. delete data  4. delete at end 5.
  display  6. exit Enter Choice: 1 Enter Value: 30
  1. insert       2. delete at beggining  3. delete data  4. delete at end 5.
  display  6. exit Enter Choice: 5 30 -> 20 -> 10 -> NULL
  1. insert       2. delete at beggining  3. delete data  4. delete at end 5.
  display  6. exit Enter Choice: 3 Enter Value: 20
  1. insert       2. delete at beggining  3. delete data  4. delete at end 5.
  display  6. exit Enter Choice: 4
  1. insert       2. delete at beggining  3. delete data  4. delete at end 5.
  display  6. exit Enter Choice: 2
  1. insert       2. delete at beggining  3. delete data  4. delete at end 5.
  display  6. exit Enter Choice: 6

*/
