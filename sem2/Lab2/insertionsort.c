#include <stdio.h>

#include <stdlib.h>

int main()
{
    int n, i, j, temp;

    printf("Enter number of elements: ");
    scanf("%d", & n);
    
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (10) + 1;
    }

    printf("Array : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    int count = 0;

    for (i = 1; i < n; i++)
    {
        j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--;
            count++;
        }
    }

    printf("\n\nSorted array :\n");
    
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\nNo of changes : %d", count);

    return 0;
}
