#include <stdio.h>

int main() {

    int n;

    printf("Enter the length of Array: ");
    scanf("%d", & n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        printf("Enter element %d : ", i + 1);
        scanf("%d", & arr[i]);
    }

    printf("\nThe array is : ");

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    int x, i;
    int idx;
    int temp;


    while (1) {

        printf("\n\nSelect the serial number of operation to perform :");

        printf("\nSort all even indices - 1");
        printf("\nSort all odd indices  - 2");
        printf("\nNone - 3");

        printf("\n\nEnter: ");
        scanf("%d", & x);
        printf("\n\n");


        if (x == 1) {


            for (i = 0; i < n - 1; i += 2) {
                int swapped = 0;
                for (int j = 0; j < n - 1 - i; j += 2) {
                    if (arr[j] > arr[j + 2]) {
                        temp = arr[j];
                        arr[j] = arr[j + 2];
                        arr[j + 2] = temp;
                        swapped = 1;
                    }
                }

                if (swapped == 0) {
                    break;
                }
            }

            printf("\n\nSorted array by even indices - \n");
            for (i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }




        }

        if (x == 2) {



            for (i = 1; i < n - 1; i += 2) {
                int swapped = 0;
                for (int j = 1; j < n - 1 - i; j += 2) {
                    if (arr[j] > arr[j + 2]) {
                        temp = arr[j];
                        arr[j] = arr[j + 2];
                        arr[j + 2] = temp;
                        swapped = 1;
                    }
                }

                if (swapped == 0) {
                    break;
                }
            }

            printf("\n\nSorted array by odd indices- \n");
            for (i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }


        }

        else if (x == 3) {
            break;
        }

    }
    return 0;
}
