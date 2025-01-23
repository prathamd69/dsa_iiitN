// This code took my brain on a tour for free

#include <stdio.h>

#include <stdlib.h>

int main() {

    int n;

    printf("Enter length of array: ");
    scanf("%d", & n);

    int arr[n];
    int arr2[n];
    int arr_final[n];
    int unique = 0;
    int freq[n];


    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (5) + 1;
    }

    int max = arr[0];

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int k = max + 1;
    int j = 0;
    for (j; j < n; j++) {

        int m = arr[j];
        int count = 0;

        for (int i = j; i < n; i++) {
            if (arr[i] == m) {
                count++;
                arr[i] = k;
            }

        }

        if (m != k) {
            freq[j] = count;
            arr2[j] = m;
            unique++;
        }
        else {
            freq[j] = 0;
            arr2[j] = 0;
        }

    }




    // for(int i=0;i<n;i++){
    //     printf("%d \n", freq[i]);
    // }

    // for(int i=0;i<n;i++){
    //     printf("%d \n", arr2[i]);
    // }


    int track = 0;
    printf("\n\nSorted by Frequency the array is - \n");

    while (track < n) {
        int max2 = freq[0];

        int temp = 0;


        for (int i = 0; i < n; i++) {
            if (freq[i] != 0) {
                if (freq[i] > max2) {
                    max2 = freq[i];
                    temp = i;
                    // freq[i] = 0;
                }

            }

        }
        freq[temp] = 0;

        // printf("\n%d %d\n",temp,max2);
        for (int j = 0; j < max2; j++) {
            printf("%d ", arr2[temp]);
            arr_final[track] = arr2[temp];
            track++;
            // printf("\n%d\n",track);

        }

    }

    // FINAL ARRAY - arr_final

    return 0;
}
