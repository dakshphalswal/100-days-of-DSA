#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insert(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

struct Node* merge(struct Node* a, struct Node* b) {
    struct Node* head = NULL;
    struct Node* tail = NULL;

    while (a != NULL && b != NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

        if (a->data <= b->data) {
            newNode->data = a->data;
            a = a->next;
        } else {
            newNode->data = b->data;
            b = b->next;
        }
        newNode->next = NULL;

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    while (a != NULL) {
        head = insert(head, a->data);
        a = a->next;
    }
    while (b != NULL) {
        head = insert(head, b->data);
        b = b->next;
    }

    return head;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, m, x;
    struct Node *list1 = NULL, *list2 = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        list1 = insert(list1, x);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        list2 = insert(list2, x);
    }

    struct Node* merged = merge(list1, list2);
    printList(merged);

    return 0;
}