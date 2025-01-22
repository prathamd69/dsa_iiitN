#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 15;

    int arr[n];
    int temp, i, j;
    int arr2[n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (10) + 1;
    }

    printf("Original Array - \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }



    int k = arr[0];


    for (j = 0; j < n; j++) {

        int m = arr[j];
        for (i = j; i < n; i++) {
            arr2[i] = arr[i];
            if (arr[i] == m) {
                arr[i] = k;
            }
        }

    }


    printf("\n\nArray without duplicates - \n");
    printf("%d ", arr[0]);
    for (i = 1; i < n; i++) {
        if (arr2[i] != arr[0])
            printf("%d ", arr2[i]);
    }

    return 0;
}
