#include <stdio.h>
void merge(int arr[],int left, int mid, int right, int target[]){
    int i = left;
    int j = mid + 1;
    int k = left;
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

    for(int l=left;l<=right;l++){
        arr[l]=target[l];
    }
}

int main(void) {

  int arr1[10] = {1, 3, 5, 7, 9, 2, 4, 4, 6, 8};
  int n = 10;
  int target[10];

  int left = 0;
  int right = n - 1;
  int mid = (left + right) / 2;

  merge(arr1, left, mid, right, target);

  for (int i = 0; i < n; i++) {
    printf("%d ", arr1[i]);
  }
  printf("\n");

  return 0;
}