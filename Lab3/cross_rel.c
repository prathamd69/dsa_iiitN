#include <stdio.h>

#include <stdlib.h>

int main() {
    
    int n;
    printf("Enter the value of n (odd) - ");
    scanf("%d",&n);
    
    int k;
    printf("Enter the value of k (odd) - ");
    scanf("%d",&k);
    
    int i, j,mul;
    int temp = k;
    
    int arr[n][n];
    int final[n][n];
    int change[k][k];

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
    
    for (i = 0; i < k; i++) {
        for (j = 0; j < k; j++) {
            arr[i][j] = rand() % (5) + 1;
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            change[i][j] = arr[i][j];
        }
    }printf("\n");
    
    printf("Change array is -\n");
    for (i = 0; i < k; i++) {
    for (j = 0; j < k; j++) {
            printf(" %d ", change[i][j]);
        }printf("\n");}
        
     
    printf("\nArray is -\n\n");

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
            int track1 = -1;
            
            for (i = beta; i < temp; i++) {
                track1++;
                int track2 = 0;
                for (j = alpha; j < q; j++) {
                    sum += arr[i][j]*change[track1][track2];
                    track2++;
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



    printf("\n\nNew final Array is -\n\n");

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
