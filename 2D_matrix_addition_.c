#include <stdio.h>

int main() {
    int arr1[100], arr2[100], merged[200];
    int size1, size2, totalSize;

    printf("Enter number of elements in first array: ");
    scanf("%d", &size1);

    printf("Enter %d elements for first array:\n", size1);
    for (int i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter number of elements in second array: ");
    scanf("%d", &size2);

    printf("Enter %d elements for second array:\n", size2);
    for (int i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }

    for (int i = 0; i < size1; i++) {
        merged[i] = arr1[i];
    }

    for (int i = 0; i < size2; i++) {
        merged[size1 + i] = arr2[i];
    }

    totalSize = size1 + size2;

    printf("Merged array elements are:\n");
    for (int i = 0; i < totalSize; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}