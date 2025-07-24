#include <stdio.h>

int insertion(int arr[], int n)
{
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    return 0;
}


int main()
{
    int arr[] = { 10,11,2,13,4,7,18,9,6,3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("unsorted array : \n");
    for (int i = 0; i < n; ++i){
        printf("%d ", arr[i]);}
    printf("\n\n");

    insertion(arr, n);
    printf("Sorted array : \n");
    for (int i = 0; i < n; ++i){
        printf("%d ", arr[i]);}
    printf("\n");
    return 0;
}
