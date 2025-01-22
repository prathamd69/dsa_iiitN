#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 15;

    int arr[n];
    int unique;
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

    for (i = 1; i < n; i++) {
        if (arr2[i] != arr[0])
            unique++;
    }

    int final_arr[unique+1];
    
    final_arr[0] = arr[0];
    int track = 1;
    
    for(i=1;i<n;i++){
        if (arr2[i] != arr[0]){
        final_arr[track] = arr2[i];
            track++;
            }}
            
    for(i=0;i<unique+1;i++){
        printf("%d ", final_arr[i]);
    }
        
    return 0;
}
