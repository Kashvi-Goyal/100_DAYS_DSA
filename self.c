#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* createNode(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode -> data = value;
    newNode -> next = NULL;

    return newNode;
}
void traversal(struct Node* head)
      {
        struct Node* temp = head;
        while(temp!=NULL)
        {
            printf(" %d -> ",temp -> data);
            temp = temp ->next;
        }
        printf("NULL\n");
      }
int main()
{
    struct Node* head= NULL;
    struct Node* tail= NULL;
    int value;
    char choice;

    do
    {
      printf("Enter the value=");
      scanf("%d",&value);

      struct Node* newNode = createNode(value);

      if(head == NULL)
      {
        head=newNode;
        tail=newNode;
      }

      else
      {
        tail -> next = newNode;
        tail = newNode;
      }

      printf("Do you want to create another node=");
      scanf(" %c",&choice);

      if(choice != 'y' && choice !='Y' && choice != 'N' && choice !='n')
      {
        printf("Invalid choice\n");
      }
    }
      while(choice == 'y' || choice =='Y');
      traversal(head);

      return 0;

    }


