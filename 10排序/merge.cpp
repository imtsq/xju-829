#include<stdio.h>

void sort(int arr[], int low, int mid, int high) {
    int i = low, j = mid + 1;
    int list[high - low + 1];
    int k = 0 ;
    while(i <= mid && j <= high) {
        if (arr[i] > arr[j]) {
            list[k++] = arr[i++];
        }else {
            list[k++] = arr[j++];
        }
    }
    while(i <= mid) {
        list[k++] = arr[i++];
    }
    while(j <= high) {
        list[k++] = arr[j++];
    }
    for(i = low, k = 0; i <= high; k++, i++) {
        arr[i] = list[k];
    }
}

void merge(int arr[], int low, int high) {
    int mid;

    if(low < high) {
        
        mid = (low + high) / 2;

        merge(arr, low, mid);
        merge(arr, mid + 1, high);
        sort(arr, low, mid, high); 
    }
}
int main() {
     int arr[] = {6,8,7,9,0,1,3,2,4,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    merge(arr, 0, n - 1);
    
    // 输出排序结果
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
