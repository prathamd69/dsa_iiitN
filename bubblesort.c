#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    printf("Enter length of array: ");
    scanf("%d", & n);

    int arr[n];
    int temp, i, j;

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (10) + 1;
    }

    printf("Original Array - \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    for (i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }

        if (swapped == 0) {
            break;
        }
    }

    printf("\n\nSorted array using Bubble sort - \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
