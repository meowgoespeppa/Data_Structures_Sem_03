/*

  LAB PROGRAM 6a

  WAP to Implement Single Link List with following
  operations: Sort the linked list, Reverse the linked list,
  Concatenation of two linked lists.

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

void sort(List *list) {
  if (list->head == NULL || list->head->next == NULL)
    return;

  int swapped;
  Node *curr;
  do {
    swapped = 0;
    curr = list->head;
    while (curr->next != NULL) {
      if (curr->data > curr->next->data) {
        int temp = curr->data;
        curr->data = curr->next->data;
        curr->next->data = temp;
        swapped = 1;
      }
      curr = curr->next;
    }
  } while (swapped);
}

void reverse(List *list) {
  if (!list->head) {
    printf("Empty list\n");
    return;
  }

  Node *next, *prev = NULL, *current = list->head;
  while (current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  list->head = prev;
}

List *concatenate(List *list1, List *list2) {
  if (!list1 || !list1->head)
    return list2;
  if (!list2 || !list2->head)
    return list1;

  Node *current = list1->head;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = list2->head;
  return list1;
}

int main() {
  List list1, list2;
  list1.head = NULL;
  list2.head = NULL;
  int choice;
  insert_at_beg(&list1, 30);
  insert_at_beg(&list1, 10);
  insert_at_beg(&list1, 20);
  insert_at_beg(&list2, 40);
  insert_at_beg(&list2, 50);

  while (1) {
    printf("1. Sort\t2. Reverse\t3. Concatenate\t4. Display\t5. Exit\n");
    printf("Enter Choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      sort(&list1);
      break;
    case 2:
      reverse(&list1);
      break;
    case 3:
      list1 = *concatenate(&list1, &list2);
      break;
    case 4:
      display_nodes(&list1);
      break;
    case 5:
      exit(0);
    }
  }
  return 0;
}

/*

  OUTPUT

  1. Sort 2. Reverse      3. Concatenate  4. Display      5. Exit
  Enter Choice: 4
  20 -> 10 -> 30 -> NULL
  1. Sort 2. Reverse      3. Concatenate  4. Display      5. Exit
  Enter Choice: 1
  1. Sort 2. Reverse      3. Concatenate  4. Display      5. Exit
  Enter Choice: 4
  10 -> 20 -> 30 -> NULL
  1. Sort 2. Reverse      3. Concatenate  4. Display      5. Exit
  Enter Choice: 2
  1. Sort 2. Reverse      3. Concatenate  4. Display      5. Exit
  Enter Choice: 4
  30 -> 20 -> 10 -> NULL
  1. Sort 2. Reverse      3. Concatenate  4. Display      5. Exit
  Enter Choice: 3
  1. Sort 2. Reverse      3. Concatenate  4. Display      5. Exit
  Enter Choice: 4
  30 -> 20 -> 10 -> 50 -> 40 -> NULL
  1. Sort 2. Reverse      3. Concatenate  4. Display      5. Exit
  Enter Choice: 5

*/
