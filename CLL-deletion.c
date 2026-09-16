#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* deleteFromBeginning(struct Node* last) {
    if (last == NULL) return NULL;

    struct Node* head = last->next;
    if (last == head) {
        free(last);
        return NULL;
    }

    last->next = head->next;
    free(head);
    return last;
}

struct Node* deleteFromEnd(struct Node* last) {
    if (last == NULL) return NULL;

    struct Node* head = last->next;
    if (last == head) {
        free(last);
        return NULL;
    }

    struct Node* temp = head;
    while (temp->next != last) {
        temp = temp->next;
    }

    temp->next = last->next;
    free(last);
    return temp;
}

struct Node* deleteSpecificNode(struct Node* last, int key) {
    if (last == NULL) return NULL;

    struct Node *curr = last->next, *prev = last;

    if (curr == last && curr->data == key) {
        free(curr);
        return NULL;
    }

    if (curr->data == key) {
        return deleteFromBeginning(last);
    }

    while (curr != last && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    if (curr->data == key) {
        prev->next = curr->next;
        if (curr == last) {
            last = prev;
        }
        free(curr);
    }

    return last;
}