#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int x) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    
    if(rear == NULL) 
    {
        front = rear = newNode;
    } 
    else 
    {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Enqueued: %d\n", x);
}

void dequeue() 
{
    if(front == NULL) 
    {
        printf("Queue Empty!\n");
        return;
    }
    
    struct Node* temp = front;
    front = front->next;
    free(temp);
    
    printf("Queue after dequeue: ");
    display();
}

void display() 
{
    struct Node* temp = front;  
    if(temp == NULL) 
    {
        printf("Empty\n");
        return;
    }
    while(temp != NULL) 
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() 
{
    enqueue(10); enqueue(20); enqueue(30);
    dequeue(); dequeue();
    enqueue(40);
    dequeue();
    
    return 0;
}