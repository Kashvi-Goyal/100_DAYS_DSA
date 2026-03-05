#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}
   
void display(struct Node* head) 
{
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) 
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() 
{
    struct Node* head = NULL;
    struct Node* current = NULL;
    int value;
    int position;

    for(int i = 1; i <= 5; i++) 
    {
        printf("Enter value for node %d: ", i);
        scanf("%d", &value);
        
        if(i == 1) 
        {
            head = createNode(value);
            current = head;
        } 
        else 
        {
            current->next = createNode(value);
            current = current->next;
        }
    }

    printf("\n");
    display(head);

    return 0;
}




