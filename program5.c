#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;


int isFull() {
    return (rear == SIZE - 1);
}


int isEmpty() {
    return (front == -1 || front > rear);
}


void enqueue(int value) {
    if (isFull()) {
        printf("Queue is FULL!\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = value;
    printf("%d enqueued into queue.\n", value);
}


int dequeue() {
    if (isEmpty()) {
        printf("Queue is EMPTY!\n");
        return -1;
    }

    int value = queue[front];
    front++;


    if (front > rear) {
        front = rear = -1;
    }

    return value;
}


void display() {
    if (isEmpty()) {
        printf("Queue is EMPTY!\n");
        return;
    }

    printf("Queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    printf("Dequeued: %d\n", dequeue());
    display();

    enqueue(40);
    enqueue(50);
    enqueue(60);

    display();

    return 0;
}
