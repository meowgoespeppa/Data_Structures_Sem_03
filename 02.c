/*

  LAB PROGRAM 2

  WAP to convert a given valid parenthesized infix
  arithmetic expression to postfix expression. The
  expression consists of single character operands and the
  binary operators + (plus), - (minus), * (multiply) and /
  (divide)

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *collection;
  int capacity, top;
} Stack;

Stack *create_stack(int capacity) {
  Stack *stack = malloc(sizeof(Stack));
  if (!stack)
    return NULL;

  stack->collection = malloc(sizeof(char) * capacity);
  if (!stack->collection) {
    free(stack);
    return NULL;
  }

  stack->capacity = capacity;
  stack->top = -1;
  return stack;
}

void delete_stack(Stack *stack) {
  free(stack->collection);
  free(stack);
}

int is_full(Stack *stack) { return stack->top == stack->capacity - 1; }

int is_empty(Stack *stack) { return stack->top == -1; }

int push(Stack *stack, char item) {
  if (is_full(stack)) {
    printf("Overflow\n");
    return 0;
  }
  stack->collection[++stack->top] = item;
  return 1;
}

int pop(Stack *stack, char *item) {
  if (is_empty(stack)) {
    printf("Underflow\n");
    return 0;
  }
  *item = stack->collection[stack->top--];

  return 1;
}

int peek(Stack *stack, char *item) {
  if (is_empty(stack)) {
    printf("Empty Stack\n");
    return 0;
  }
  *item = stack->collection[stack->top];
  return 1;
}

int is_operator(char item) {
  if (item == '+' || item == '-' || item == '*' || item == '/' || item == '^')
    return 1;

  return 0;
}

int precedence(char item) {
  if (item == '+' || item == '-')
    return 1;
  if (item == '*' || item == '/')
    return 2;
  if (item == '^')
    return 3;
  return 0;
}

int main(void) {
  Stack *stack = create_stack(100);
  char str[100], post_str[100], pop_val, peek_val;

  printf("Enter Infix Expression: ");
  fgets(str, 100, stdin);
  int len = strlen(str), k = 0;

  for (int i = 0; i < len; i++) {
    if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
      continue; // skip whitespace characters

    if (is_operator(str[i])) {
      while (!is_empty(stack)) {
        peek(stack, &peek_val);

        if (peek_val == '(')
          break;

        int peek_prec = precedence(peek_val);
        int curr_prec = precedence(str[i]);

        if (peek_prec > curr_prec ||
            (peek_prec == curr_prec && str[i] != '^')) {
          pop(stack, &pop_val);
          post_str[k++] = pop_val;
        } else
          break;
      }
      push(stack, str[i]);
    } else if (str[i] == '(') {
      push(stack, str[i]);
    } else if (str[i] == ')') {
      while (!is_empty(stack)) {
        peek(stack, &peek_val);
        if (peek_val == '(')
          break;
        pop(stack, &pop_val);
        post_str[k++] = pop_val;
      }
      pop(stack, &pop_val);
    } else
      post_str[k++] = str[i];
  }

  while (!is_empty(stack)) {
    pop(stack, &pop_val);
    post_str[k++] = pop_val;
  }

  post_str[k] = '\0';

  printf("Postfix Expression: %s\n", post_str);

  delete_stack(stack);
  return 0;
}

/*

  OUTPUT

  Enter Infix Expression: (a+b)*(c-d)
  Postfix Expression: ab+cd-*

*/
