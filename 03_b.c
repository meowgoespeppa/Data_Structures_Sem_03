/*

  LAB PROGRAM 3b

  WAP to simulate the working of a circular queue of
  integers using an array. Provide the following operations:
  Insert, Delete & Display
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
  if ((rear + 1) % n == front) {
    printf("Queue Overflow\n");
    return;
  }
  if (front == -1)
    front = 0;
  rear = (rear + 1) % n;
  queue[rear] = value;
}

void delete() {
  if (front == -1) {
    printf("Queue Empty\n");
    return;
  }
  if (front == rear) {
    front = -1;
    rear = -1;
  } else
    front = (front + 1) % MAX;
}

void display(int n) {
  if (front == -1) {
    printf("Queue Empty\n");
    return;
  }
  int i = front;
  while (1) {
    printf("%d ", queue[i]);
    if (i == rear)
      break;
    i = (i + 1) % n;
  }
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
      display(n);
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
