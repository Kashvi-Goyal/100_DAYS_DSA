#include <stdio.h>
#define MAX_SIZE 100

int stack1[MAX_SIZE];  // Input stack (enqueue)
int stack2[MAX_SIZE];  // Output stack (dequeue)
int top1 = -1;
int top2 = -1;

void enqueue(int x) {
    if(top1 >= MAX_SIZE - 1) {
        printf("Queue Overflow!\n");
        return;
    }
    stack1[++top1] = x;  // Store in first stack
    printf("Enqueued: %d\n", x);
}

void dequeue() {
    if(top1 == -1 && top2 == -1) {
        printf("Queue Empty!\n");
        return;
    }
    
    if(top2 == -1) {
        while(top1 >= 0) {
            stack2[++top2] = stack1[top1--];  // Pop1 → Push2
        }
    }
    
    // Pop in second
    printf("Dequeued: %d\n", stack2[top2]);
    top2--;
    
    printf("Queue now: ");
    for(int i = top2; i >= 0; i--) {
        printf("%d ", stack2[i]);
    }   
    printf("\n");
}

int main() {
    enqueue(10); enqueue(20); enqueue(30);
    dequeue();  // 10
    enqueue(40);
    dequeue();  // 20
    
    return 0;
}
  
