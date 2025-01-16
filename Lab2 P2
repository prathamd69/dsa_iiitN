#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int n;

    printf("Enter length of array: ");
    scanf("%d",&n);
    
    int arr[n];
    
    for (int i = 0; i < n; i++) {
    arr[i] = rand() % (5) + 1;
    }
    
    for (int i = 0; i < n; i++) {
    printf("%d ",arr[i]);
    }
    int k = -1;
    int j = 0;
    for (j;j<n;j++){
        
    int m = arr[j];
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] == m){
        count++;
            arr[i] = k;
        }

    }
    
    if (m!=k){
    printf("\n'%d' : %d times",m,count);}
        
    }}
