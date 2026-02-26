#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// --- CREATE NODE ---
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("[Error] Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// --- INSERTION ---
struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = head;
    return newNode; 
}

struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) return newNode;
    
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

void insertAtPosition(struct Node* head, int value, int pos) {
    struct Node* newNode = createNode(value);
    struct Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp != NULL) {
        newNode->next = temp->next; 
        temp->next = newNode;     
    } else {
        printf("\n[Error] Position out of bounds!\n");
        free(newNode);
    }
}

// --- DELETION ---
struct Node* deleteAtBeginning(struct Node* head) {
    if (head == NULL) {
        printf("\n[Error] List is empty!\n");
        return NULL;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    printf("\nNode deleted from start.\n");
    return head;
}

struct Node* deleteAtEnd(struct Node* head) {
    if (head == NULL) {
        printf("\n[Error] List is empty!\n");
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    printf("\nNode deleted from end.\n");
    return head;
}

struct Node* deleteByValue(struct Node* head, int val) {
    if (head == NULL) return NULL;
    
    if (head->data == val) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    
    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data != val) {
        temp = temp->next;
    }
    
    if (temp->next == NULL) {
        printf("\n[Error] Value %d not found.\n", val);
    } else {
        struct Node* toDelete = temp->next;
        temp->next = temp->next->next;
        free(toDelete);
        printf("\nValue %d deleted.\n", val);
    }
    return head;
}

struct Node* deleteAtPosition(struct Node* head, int pos) {
    if (head == NULL) return NULL;
    if (pos == 1) return deleteAtBeginning(head);

    struct Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("\n[Error] Position out of bounds!\n");
    } else {
        struct Node* toDelete = temp->next;
        temp->next = temp->next->next;
        free(toDelete);
        printf("\nNode at position %d deleted.\n", pos);
    }
    return head;
}

// --- UTILITIES ---
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void findElement(struct Node* head, int target) {
    struct Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == target) {
            printf("\n[Success] Element %d found at position %d.\n", target, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("\n[Info] Element %d not found.\n", target);
}

void traversal(struct Node* head) {
    struct Node* temp = head;
    printf("\nLINKED LIST: ");
    if (temp == NULL) printf("EMPTY");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// --- MAIN ---
int main() {
    struct Node* head = NULL;
    int choice, value, pos;

    while (1) {
        printf("\n--- Operations ---");
        printf("\n1. Insert Start  2. Insert End    3. Insert Pos");
        printf("\n4. Delete Start  5. Delete End     6. Delete Pos");
        printf("\n7. Delete Value  8. Search Element 9. Count Nodes");
        printf("\n10. Display      11. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: printf("Val: "); scanf("%d", &value); head = insertAtBeginning(head, value); break;
            case 2: printf("Val: "); scanf("%d", &value); head = insertAtEnd(head, value); break;
            case 3: printf("Val: "); scanf("%d", &value); printf("Pos: "); scanf("%d", &pos);
                    if (pos == 1) head = insertAtBeginning(head, value); else insertAtPosition(head, value, pos); break;
            case 4: head = deleteAtBeginning(head); break;
            case 5: head = deleteAtEnd(head); break;
            case 6: printf("Pos: "); scanf("%d", &pos); head = deleteAtPosition(head, pos); break;
            case 7: printf("Val to delete: "); scanf("%d", &value); head = deleteByValue(head, value); break;
            case 8: printf("Search: "); scanf("%d", &value); findElement(head, value); break;
            case 9: printf("\nTotal nodes: %d\n", countNodes(head)); break;
            case 10: traversal(head); break;
            case 11: exit(0);
            default: printf("\nInvalid choice!\n");
        }
    }
    return 0;
}