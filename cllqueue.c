#include <stdio.h>
#define SIZE 5

int queue[SIZE], front = -1, rear = -1;

int isFull() {
    return (front == (rear + 1) % SIZE);
}

int isEmpty() {
    return (front == -1);
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty()) {
        front = 0;
    }
    rear = (rear + 1) % SIZE;
    queue[rear] = value;
    printf("Inserted: %d\n", value);
}


int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return -1;
    }
    int value = queue[front];
    if (front == rear) { 
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
    return value;
}


void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    int i;
    for (i = front; i != rear; i = (i + 1) % SIZE) {
        printf("%d ", queue[i]);
    }
    printf("%d\n", queue[rear]); 
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    
    display();
    
    printf("Dequeued: %d\n", dequeue());
    
    display();
    
    enqueue(40);
    
    display();
    
    return 0;
}

