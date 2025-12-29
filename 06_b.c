/*

  LAB PROGRAM 6b

  WAP to Implement Single Link List to simulate Stack &
  Queue Operations.

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

void push(List *list, int data) {
  Node *new_node = create_node(data);
  new_node->next = list->head;
  list->head = new_node;
}

void pop(List *list) {
  if (!list->head) {
    printf("Empty stack.\n");
    return;
  }

  Node *temp = list->head;
  list->head = list->head->next;
  free(temp);
}

void enqueue(List *list, int data) {
  Node *new_node = create_node(data);

  if (!list->head) {
    list->head = new_node;
    return;
  }

  Node *temp = list->head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = new_node;
  new_node->next = NULL;
}

void dequeue(List *list) {
  if (!list->head) {
    printf("Empty queue.\n");
    return;
  }

  Node *temp = list->head;
  list->head = temp->next;
  free(temp);
}

void display_nodes(List *list) {
  if (!list->head)
    return;

  Node *current = list->head;
  while (current != NULL) {
    printf("%d -> ", current->data);
    current = current->next;
  }
  printf("NULL\n");
}

int main() {
  List stack, queue;
  stack.head = NULL;
  queue.head = NULL;
  int choice, value;

  while (1) {
    printf("Stack: 1. Push\t2. Pop\t3. Display\t7. Exit\n");
    printf("Queue: 4. Enqueue\t5. Dequeue\t6. Display\t7. Exit\n");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      scanf("%d", &value);
      push(&stack, value);
      break;
    case 2:
      pop(&stack);
      break;
    case 3:
      display_nodes(&stack);
      break;
    case 4:
      scanf("%d", &value);
      enqueue(&queue, value);
      break;
    case 5:
      dequeue(&queue);
      break;
    case 6:
      display_nodes(&queue);
      break;
    case 7:
      exit(0);
    }
  }
  return 0;
}

/*

  OUTPUT

  Stack: 1. Push  2. Pop  3. Display      7. Exit
  Queue: 4. Enqueue       5. Dequeue      6. Display      7. Exit
  1
  10
  Stack: 1. Push  2. Pop  3. Display      7. Exit
  Queue: 4. Enqueue       5. Dequeue      6. Display      7. Exit
  1
  20
  Stack: 1. Push  2. Pop  3. Display      7. Exit
  Queue: 4. Enqueue       5. Dequeue      6. Display      7. Exit
  1
  30
  Stack: 1. Push  2. Pop  3. Display      7. Exit
  Queue: 4. Enqueue       5. Dequeue      6. Display      7. Exit
  3
  30 -> 20 -> 10 -> NULL
  Stack: 1. Push  2. Pop  3. Display      7. Exit
  Queue: 4. Enqueue       5. Dequeue      6. Display      7. Exit
  2
  Stack: 1. Push  2. Pop  3. Display      7. Exit
  Queue: 4. Enqueue       5. Dequeue      6. Display      7. Exit
  3
  20 -> 10 -> NULL
  Stack: 1. Push  2. Pop  3. Display      7. Exit
  Queue: 4. Enqueue       5. Dequeue      6. Display      7. Exit
  4
  40
  Stack: 1. Push  2. Pop  3. Display      7. Exit
  Queue: 4. Enqueue       5. Dequeue      6. Display      7. Exit
  4
  50
  Stack: 1. Push  2. Pop  3. Display      7. Exit
  Queue: 4. Enqueue       5. Dequeue      6. Display      7. Exit
  4
  60
  Stack: 1. Push  2. Pop  3. Display      7. Exit
  Queue: 4. Enqueue       5. Dequeue      6. Display      7. Exit
  6
  40 -> 50 -> 60 -> NULL
  Stack: 1. Push  2. Pop  3. Display      7. Exit
  Queue: 4. Enqueue       5. Dequeue      6. Display      7. Exit
  5
  Stack: 1. Push  2. Pop  3. Display      7. Exit
  Queue: 4. Enqueue       5. Dequeue      6. Display      7. Exit
  6
  50 -> 60 -> NULL
  Stack: 1. Push  2. Pop  3. Display      7. Exit
  Queue: 4. Enqueue       5. Dequeue      6. Display      7. Exit
  7

*/
