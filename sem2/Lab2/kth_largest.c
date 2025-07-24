#include <stdio.h>

#include <stdlib.h>

int main() {

    int n, k;

    printf("Enter length of array: ");
    scanf("%d", & n);

    printf("Enter K: ");
    scanf("%d", & k);

    int arr[n];

    printf("Array is : ");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (10) + 1;
    }

    int min = arr[0];
    int max = arr[0];

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
        if(arr[i]<min){
            min = arr[i];
        }
    }

    int temp;
    int track = min-1 ;
    int count = 0;

  if (k <= n) {
        while(1) {
            max = arr[0];
            for (int j = 0; j < n; j++) {
                if (arr[j] >= max) {
                    max = arr[j];
                    temp = j;
                }
            }
            
            if (track == max){
                count--;
                
            }
            
            track = max;
            arr[temp] = min-1;
            count++;
            
            if(count>=k){
                break;
            }
            else{
                continue;
            }


        }
        if (max>=min){
        printf("\nKth largest value is %d", max);}
        else{
        printf("\nInvalid Input");
    }
    }

    else{
        printf("\nInvalid Input");
    }



    return 0;
}
