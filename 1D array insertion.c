#include <stdio.h>

void insertElement(int arr[], int *size, int capacity, int element, int index) {
    if (*size >= capacity) {
        printf("Error: Array capacity reached. Insertion failed.\n");
        return;
    }
    
    if (index < 0 || index > *size) {
        printf("Error: Invalid index.\n");
        return;
    }
    for (int i = *size; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = element;
    (*size)++;
}

int main() {
    int arr[10] = {10, 20, 30, 40, 50};
    int size = 5;            
    int element = 25;           
    int index = 2;               

    printf("Original array: ");
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");
    insertElement(arr, &size, 10, element, index);

    printf("Array after insertion: ");
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
