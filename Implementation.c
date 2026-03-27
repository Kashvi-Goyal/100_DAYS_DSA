#include<stdio.h>
#define MAX 5

int top = -1;
int stack[MAX];

void push(int a) 
{
    if(top == MAX-1) 
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = a;
}

void pop() 
{
    if(top == -1) 
    {
        printf("Stack Underflow\n");
        return;
    }
    top --;
}

void peek() 
{
    if(top == -1) 
    {
        printf("Empty Stack\n");
        return;
    }
    printf("Peek is %d\n", stack[top]);
}

int is_empty() 
{
    return top == -1;
}

int is_full() 
{
    return top == MAX-1;
}

int main() 
{
    int choice, a;
    
    while(1) 
    {  
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Is Empty\n5. Is Full\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch(choice) 
        {
            case 1: 
                printf("Enter value: ");
                scanf("%d", &a);
                push(a);
                break;

            case 2: pop(); break;

            case 3: peek(); break;

            case 4: 
                if(is_empty()) printf("Stack is empty\n");
                else printf("Stack is not empty\n");
                break;

            case 5: 
                if(is_full()) printf("Stack is full\n");
                else printf("Stack is not full\n");
                break;

            case 6: return 0;
            
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
