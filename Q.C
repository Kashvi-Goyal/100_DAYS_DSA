#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Append at end
struct Node* append(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Get length
int getLength(struct Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

// Find intersection node
struct Node* findIntersection(struct Node* h1, struct Node* h2) {
    int len1 = getLength(h1);
    int len2 = getLength(h2);

    int diff = abs(len1 - len2);

    // Move pointer of longer list
    if (len1 > len2) {
        for (int i = 0; i < diff; i++)
            h1 = h1->next;
    } else {
        for (int i = 0; i < diff; i++)
            h2 = h2->next;
    }

    // Traverse together
    while (h1 && h2) {
        if (h1 == h2)
            return h1;
        h1 = h1->next;
        h2 = h2->next;
    }

    return NULL;
}

int main() {
    int n, m, x;
    struct Node *list1 = NULL, *list2 = NULL;

    // First list
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        list1 = append(list1, x);
    }

    // Second list
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        list2 = append(list2, x);
    }

    // NOTE:
    // No intersection is formed automatically from input.
    // For testing, you can manually connect:
    // Example: list2's last node -> some node in list1

    struct Node* inter = findIntersection(list1, list2);

    if (inter)
        printf("%d", inter->data);
    else
        printf("No Intersection");

    return 0;
}