#include <stdio.h>

void heapsort(int arr[], int low, int high) {
    int i = low, j = 2 * i;
    int temp = arr[i];
    while(j <= high) {
        if (j < high && arr[j] < arr[j + 1]) {
            j++;
        }
        if (temp < arr[j]) {
            arr[i] = arr[j];
            i = j;
            j = 2 * i;
        } else {
            break;
        }
    }
    arr[i] = temp;

}

int main () {
    //从1开始
    int arr[] = {-1,6,8,7,9,0,1,3,2,4,5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // 建立大顶堆
    for (int i = n / 2; i >= 1; i--) {
        heapsort(arr,i, n);
    }
    //排序，每次将待排最值放到arr[i]中，然后重新用heapsort将最大放到arr[1]
    for (int i = n; i >= 2; i--) {
        int temp = arr[1];
        arr[1] = arr[i];
        arr[i] = temp;
        heapsort(arr, 1, i - 1);
    }
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}