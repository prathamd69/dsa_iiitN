#include <stdio.h>

#include <stdlib.h>

int main() {

    int n;
    printf("Enter the value of n (odd) - ");
    scanf("%d",&n);
    
    int k;
    printf("Enter the value of k (odd) - ");
    scanf("%d",&k);
    
    int i, j;
    int temp = k;
    
    int arr[n][n];
    int final[n][n];

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            arr[i][j] = rand() % (5) + 1;
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            final[i][j] = arr[i][j];
        }
    }

    printf("Array is -\n\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf(" %d ", arr[i][j]);
        }
        printf("\n");
    }

    int sum;
    int beta = 0;
    i = 0;
    int count = 1;

    while (temp < n + 1) {
        i = beta;
        // printf("\ntemp = %d, beta = %d, i = %d\n",temp,beta,i);
        int q = k;
        int alpha = 0;
        while (q < n + 1) {

            sum = 0;
            j = alpha;
            //  printf("\nk = %d, alpha = %d, j = %d\n",k,alpha,j);

            for (i = beta; i < temp; i++) {
                for (j = alpha; j < q; j++) {
                    sum += arr[i][j];
                }
            }

            // printf("\n%d = sum", sum);
            final[count][(alpha + q) / 2] = sum / (k*k);

            q++;
            alpha++;

        }



        beta++;
        temp++;
        count++;
    }



    printf("\n\nNew Final Array is -\n\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            // printf("\n%d %d\n",i,j);
            printf(" %d ", final[i][j]);
        }
        printf("\n");
    }
    // printf("\n");

    return 0;
}
