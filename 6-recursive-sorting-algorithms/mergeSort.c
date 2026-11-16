#include <stdio.h>
void merge(int arr[],int left, int mid, int right, int target[]){
    int i = left;
    int j = mid + 1;
    int k=0;
    while(i<=mid && j<=right){
        if(arr[i]<arr[j]){
            target[k++]=arr[i++];
            
        } else {
            target[k++]=arr[j++];
        }
    }
    while(i<=mid){
        target[k++]=arr[i++];
    }
    while(j<=right){
        target[k++]=arr[j++];
    }

    for(int l=0;l<=right;l++){
        arr[l]=target[l];
    }
}

void mergeSort(int arr[], int target[], int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = (left + right)/2;
    mergeSort(arr, target, left, mid);
    mergeSort(arr, target, mid+1, right);
    merge(arr, left, mid, right, target);
}

int main(void) {

  int arr1[10] = {1, 9, 6, 3, 4, 2, 8, 7, 5, 10};
  int n = 10;
  int target[10];

  int left = 0;
  int right = n - 1;

  mergeSort(arr1, target, left, right);

  for (int i = 0; i < n; i++) {
    printf("%d ", arr1[i]);
  }
  printf("\n");

  return 0;
}