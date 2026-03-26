#include <stdio.h>
#define ARRAY_SIZE 100
#define MAX_SIZE ARRAY_SIZE

int arr[ARRAY_SIZE];
int top1 = -1;                    
int top2 = ARRAY_SIZE / 2;        

// Stack1: Check overflow FIRST, then push
void push1(int x) {
    if(top1 >= ARRAY_SIZE/2 - 1) {  // CHECK OVERFLOW FIRST
        printf("Stack1 Overflow!\n");
        return;
    }
    arr[++top1] = x;  // THEN PUSH
    printf("Stack1: %d\n", x);
}

// Stack2: Check overflow FIRST, then push
void push2(int x) {
    if(top2 >= MAX_SIZE - 1) {      // CHECK OVERFLOW FIRST
        printf("Stack2 Overflow!\n");
        return;
    }
    arr[++top2] = x;                // THEN PUSH
    printf("Stack2: %d\n", x);
}

int pop1() {
    if(top1 >= 0) return arr[top1--];
    printf("Stack1 Empty!\n");
    return -1;
}

int pop2() {
    if(top2 >= ARRAY_SIZE/2) return arr[top2--];
    printf("Stack2 Empty!\n");
    return -1;
}

int main() {
    push1(10); push1(20); push1(30);
    push2(40); push2(50);
    
    printf("Pop1: %d\n", pop1());  // 30
    printf("Pop2: %d\n", pop2());  // 50
    
    return 0;
}