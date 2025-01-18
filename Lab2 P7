#include <stdio.h>

#include <stdlib.h>

int main() {

    int n, k;

    printf("Enter length of array: ");
    scanf("%d", & n);

    printf("Enter K: ");
    scanf("%d", & k);

    int arr[n];

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (100) + 1;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    int temp;
    int max;

    if (k <= n) {
        for (int i = 0; i < k; i++) {
            max = arr[0];
            for (int j = 0; j < n; j++) {
                if (arr[j] > max) {
                    max = arr[j];
                    temp = j;
                }
            }

            arr[temp] = -1;

        }
        printf("\n%d", max);
    }



    return 0;
}
