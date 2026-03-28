#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};

// Global top pointer 
struct Node* top = NULL;

// Push: insert at beginning
void push(int a) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) 
    {
        printf("Stack Overflow (Memory Full)\n");
        return;
    }
    newNode->data = a;
    newNode->next = top;
    top = newNode;
}

// Pop: remove from beginning
void pop() 
{
    if (top == NULL) 
    {
        printf("Stack Underflow\n");
        return;
    }
    struct Node* temp = top;
    printf("Popped %d\n", temp->data);
    top = top->next;
    free(temp);
}

// Peek: see top element
void peek() 
{
    if (top == NULL) 
    {
        printf("Empty Stack\n");
        return;
    }
    printf("Peek is %d\n", top->data);
}

// Check if stack is empty
int is_empty() 
{
    return top == NULL;
}

int main() 
{
    int choice, a;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Is Empty\n5. Is Full\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &a);
                push(a);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                if (is_empty())
                    printf("Stack is empty\n");
                else
                    printf("Stack is not empty\n");
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
