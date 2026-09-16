#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }

    struct Node* temp = head;
    head = head->next;
    free(temp);

    return head;
}

struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) {
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

    return head;
}

struct Node* deleteByValue(struct Node* head, int value) {
    if (head == NULL) {
        return NULL;
    }

    if (head->data == value) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data != value) {
        temp = temp->next;
    }

    if (temp->next != NULL) {
        struct Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        free(nodeToDelete);
    }

    return head;
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);
    head = insertAtEnd(head, 50);

    printf("Original List:\n");
    displayList(head);

    head = deleteFromBeginning(head);
    printf("Shuruat se delete karne ke baad:\n");
    displayList(head);

    head = deleteFromEnd(head);
    printf("Aakhir se delete karne ke baad:\n");
    displayList(head);

    head = deleteByValue(head, 30);
    printf("30 ko delete karne ke baad:\n");
    displayList(head);

    return 0;
}