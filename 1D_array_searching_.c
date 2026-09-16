#include <stdio.h>

int main() {
    int arr[100];
    int size, element, found = 0;

    printf("Enter number of elements in array: ");
    scanf("%d", &size);

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &element);

    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            printf("Element found at position %d (index %d)\n", i + 1, i);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Element not found in array\n");
    }

    return 0;
}