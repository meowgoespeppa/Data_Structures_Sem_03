/*

  LAB PROGRAM 1

  Write a program to simulate the working of stack using an
  array with the following:
  a) Push
  b) Pop
  c) Display
  The program should print appropriate messages for stack
  overflow, stack underflow

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *collection;
  int capacity;
  int top;
} Stack;

Stack *create_stack(int capacity) {
  Stack *stack = malloc(sizeof(Stack));
  if (!stack)
    return NULL;
  stack->collection = malloc(sizeof(int) * capacity);
  if (!stack->collection) {
    free(stack);
    return NULL;
  }
  stack->capacity = capacity;
  stack->top = -1;
  return stack;
}

int is_full(Stack *stack) { return stack->top == stack->capacity - 1; }

int is_empty(Stack *stack) { return stack->top == -1; }

int push(Stack *stack, int item) {
  if (is_full(stack)) {
    printf("Stack Overflow\n");
    return 0;
  }
  stack->collection[++stack->top] = item;
  return 1;
}

int pop(Stack *stack, int *item) {
  if (is_empty(stack)) {
    printf("Stack Underflow\n");
    return 0;
  }
  *item = stack->collection[stack->top--];
  return 1;
}

void display(Stack *stack) {
  if (is_empty(stack)) {
    printf("Stack is Empty\n");
    return;
  }
  for (int i = stack->top; i >= 0; i--)
    printf("%d ", stack->collection[i]);
  printf("\n");
}

int main() {
  int capacity, choice, value;
  Stack *stack;

  printf("Enter capacity: ");
  scanf("%d", &capacity);
  stack = create_stack(capacity);

  while (1) {
    printf("1. Push\t2.Pop\t3.Display\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      scanf("%d", &value);
      push(stack, value);
      break;
    case 2:
      pop(stack, &value);
      break;
    case 3:
      display(stack);
      break;
    case 4:
      exit(0);
    }
  }
  return 0;
}

/*

  OUTPUT

  Enter capacity: 5
  1. Push 2.Pop   3.Display
  Enter choice: 1
  10
  1. Push 2.Pop   3.Display
  Enter choice: 1
  20
  1. Push 2.Pop   3.Display
  Enter choice: 1
  30
  1. Push 2.Pop   3.Display
  Enter choice: 3
  30 20 10
  1. Push 2.Pop   3.Display
  Enter choice: 2
  1. Push 2.Pop   3.Display
  Enter choice: 3
  20 10
  1. Push 2.Pop   3.Display
  Enter choice: 4

*/
