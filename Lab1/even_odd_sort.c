// Took Help from Internet 
// this file is not completely done by myself, reference and help is used.


#include <stdio.h>
#include <stdlib.h>

int sort_even(int arr[], int n) {

    int *evens = (int *)malloc(n * sizeof(int));

    int evencount = 0;
    int oddcount = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            evens[evencount] = arr[i];
            evencount++;
        }

    }


    for (int i = 0; i < evencount - 1; i++) {
        for (int j = i + 1; j < evencount; j++) {
            if (evens[i] > evens[j]) {
                int temp = evens[i];
                evens[i] = evens[j];
                evens[j] = temp;
            }
        }
    }
    
    

    int l = 0;



    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            arr[i] = evens[l];
            l++;
        }
    }
    


    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    

    free(evens);

    return 0;
}

int sort_odd(int arr[], int n) {

    int *odds = (int *)malloc(n * sizeof(int));


    int oddcount = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
            odds[oddcount] = arr[i];
            oddcount++;
        }
    }


    for (int i = 0; i < oddcount - 1; i++) {
        for (int j = i + 1; j < oddcount; j++) {
            if (odds[i] > odds[j]) {
                int temp = odds[i];
                odds[i] = odds[j];
                odds[j] = temp;
            }
        }
    }

    int k = 0;


    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
            arr[i] = odds[k];
            k++;
        }
    }


    
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(odds);
    return 0;
}

int main() {
    int N = 10;
    int arr[] = {12, 17, 18, 11, 15, 0,10,23, 67, 98};
    sort_even(arr, N);
    sort_odd(arr,N);
    return 0;
}

