#include<stdio.h>
struct Node {
    int data;
    struct Node* next;
};
int search(struct Node* head, int key) {
    for (struct Node* temp = head; temp != NULL; temp = temp->next) {
        if (temp->data == key) return 1;
    }
    return 0;
}