#include <stdio.h>
#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int x) {
    if(rear >= MAX_SIZE - 1) {  // OVERFLOW
        printf("Queue Overflow!\n");
        return;
    }
    queue   [++rear] = x;          // THEN ADD
    printf("Enqueued: %d\n", x);
}

int dequeue() {
    if(front == -1 || front > rear) {  // CHECK UNDERFLOW
        printf("Queue Empty!\n");
        return -1;
    }
    return queue[front++];      // THEN DELETE
}

int main() {
    enqueue(10); enqueue(20); enqueue(30);
    printf("Dequeued: %d\n", dequeue());  
    printf("Dequeued: %d\n", dequeue());  
    
    enqueue(40);
    printf("Dequeued: %d\n", dequeue());  
    
    return 0;
}