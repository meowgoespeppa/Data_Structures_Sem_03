/*

  LAB PROGRAM 3a

  WAP to simulate the working of a queue of integers
  using an array. Provide the following operations: Insert,
  Delete, Display
  The program should print appropriate messages for queue
  empty and queue overflow conditions

*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

void insert(int value, int n) {
  if (rear == n - 1) {
    printf("Queue Overflow\n");
    return;
  }
  if (front == -1)
    front = 0;
  queue[++rear] = value;
}

void delete() {
  if (front == -1 || front > rear) {
    printf("Queue Empty\n");
    return;
  }
  front++;
}

void display() {
  if (front == -1 || front > rear) {
    printf("Queue Empty\n");
    return;
  }
  for (int i = front; i <= rear; i++)
    printf("%d ", queue[i]);
  printf("\n");
}

int main() {
  int n, choice, value;

  scanf("%d", &n);

  while (1) {
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      scanf("%d", &value);
      insert(value, n);
      break;
    case 2:
      delete();
      break;
    case 3:
      display();
      break;
    case 4:
      exit(0);
    }
  }
  return 0;
}

/*

  Sample Input:
  5
  1 10
  1 20
  1 30
  3
  2
  3
  4

  Sample Output:
  10 20 30
  20 30

*/
