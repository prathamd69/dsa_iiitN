#include <stdio.h>

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int part(int arr[], int si, int ei) {
  
  int pivot = arr[ei];
  
  int i = (si - 1);

  for (int j = si; j < ei; j++) {
    if (arr[j] <= pivot) {

      i++;

      swap(&arr[i], &arr[j]);
    }
  }

  swap(&arr[i + 1], &arr[ei]);
  
  return (i + 1);
}

void qsort(int arr[], int si, int ei) {
  if (si < ei) {

    int pi = part(arr, si, ei);

    qsort(arr, si, pi - 1);

    qsort(arr, pi + 1, ei);
  }
}


int main() {
  int arr[] = {7,5,14,10,2,17,8,6};
  
  int n = sizeof(arr) / sizeof(arr[0]);
  
  printf("Unsorted arr\n");
    for (int i = 0; i < n; ++i) {
    printf("%d  ", arr[i]);
  }
  
  printf("\n");
  printf("\n");

  qsort(arr, 0, n - 1);
  
  printf("Sorted arr in ascending order: \n");
    for (int i = 0; i < n; ++i) {
    printf("%d  ", arr[i]);
  }
  printf("\n");
}
