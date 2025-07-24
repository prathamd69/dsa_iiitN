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
        printf("\n\nInsertion - 1");
        printf("\nDeletion - 2");
        printf("\nSearch - 3");
        printf("\nSort - 4");
        printf("\nNone - 5");

        printf("\n\nEnter: ");
        scanf("%d", & x);
        printf("\n\n");


        if (x == 1) {

            int ary[n + 1];

            printf("Enter the index of insertion (0 to %d)- ", n);
            scanf("%d", & idx);

            printf("Enter the element to be inserted - ");
            scanf("%d", & temp);

            if (idx >= 0 && idx <= n) {
                for (i = 0; i < n + 1; i++) {
                    if (i < idx) {
                        ary[i] = arr[i];
                    }
                    else if (i > idx) {
                        ary[i] = arr[i - 1];
                    }
                    else {
                        ary[i] = temp;
                    }
                }

                printf("\nNew array is : ");

                for (int i = 0; i < n + 1; i++) {
                    printf("%d ", ary[i]);
                }
            }

            else {
                printf("Invalid Input");
            }




        }

        if (x == 2) {


            int ary[n - 1];

            printf("Enter the index of deletion (0 to %d)- ", n);
            scanf("%d", & idx);


            if (idx >= 0 && idx <= n - 1) {
                for (i = 0; i < n - 1; i++) {
                    if (i < idx) {
                        ary[i] = arr[i];
                    }
                    else if (i >= idx) {
                        ary[i] = arr[i + 1];
                    }

                }

                printf("\nNew array is : ");

                for (int i = 0; i < n - 1; i++) {
                    printf("%d ", ary[i]);


                }

            }

            else {
                printf("Invalid Input");
            }


        }

        if (x == 3) {


            printf("Enter the element to search - ");
            scanf("%d", & temp);
            int flag = 0;

            for (i = 0; i < n; i++) {

                if (arr[i] == temp) {
                    printf("\nThe elements lies at index = %d", i);
                    flag = 1;
                }
            }

            if (flag == 0) {
                printf("Element is not present in array.");
            }



        }

        if (x == 4) {

            for (i = 0; i < n - 1; i++) {
                int swapped = 0;
                for (int j = 0; j < n - 1 - i; j++) {
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

            printf("\n\nSorted array - \n");
            for (i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }


        }

        if (x == 5) {
            break;
        }

        else if (x > 5 || x < 1) {
            printf("\nInvalid Input");
        }

    }
    return 0;
}
