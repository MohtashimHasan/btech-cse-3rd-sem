#include<stdio.h>
struct Node{
    int Node;
    struct Node* next;
};
int countNodes(struct Node* head) {
    int count = 0;
    for (struct Node* temp = head; temp != NULL; temp = temp->next) {
        count++;
    }
    return count;
}