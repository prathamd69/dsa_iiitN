#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int n,k;

    printf("Enter length of array: ");
    scanf("%d",&n);
    
    printf("Enter the freq: ");
    scanf("%d",&k);
    
    int arr[n];
    
    for (int i = 0; i < n; i++) {
    arr[i] = rand() % (10) + 1;
    }
    
    for (int i = 0; i < n; i++) {
    printf("%d ",arr[i]);
    }
    

    int i;
    int j;
    int temp = 1;
    
    for(int j = 1;j<k;j++){
        float tot = 0;
    for(i = 0;i<j;i++){
        tot += arr[i];
        
    }
    printf("\n%0.2f ",tot/j);
        }
        

    for (int j = 0;j<n-k+1;j++){
        float tot = 0;
        for(i = j;i<k+j;i++){
        tot += arr[i];
    }
    
    printf("\n%0.2f ",tot/k);
    
    }

    return 0;
}
