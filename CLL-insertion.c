#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertAtBeginning(struct Node* last, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (last == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    newNode->next = last->next;
    last->next = newNode;
    return last;
}

struct Node* insertAtEnd(struct Node* last, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (last == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    newNode->next = last->next;
    last->next = newNode;
    return newNode;
}

void display(struct Node* last) {
    if (last == NULL) return;
    struct Node* temp = last->next;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("(head)\n");
}