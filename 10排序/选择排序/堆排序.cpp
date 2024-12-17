#include<stdio.h>


void sort(int arr[], int low, int high) {
    int temp = arr[low];
    int i = low, j = i * 2;
    while (j <= high) {
        if (j < high && arr[j] < arr[j+1]) {
            j++;
        }
        if (temp > arr[j]) break;
        else {
            arr[i] = arr[j];
            i = j;
            j = j * 2;
        }
    }
    arr[i] = temp;
}

void func(int arr[], int n) {
    for(int i = n / 2; i > 0; i--) {
        sort(arr, i, n);
    }
    for (int i = 1; i<=9; i++) {
        printf("%d ", arr[i]);
    }
    for (int i = n; i > 1; i--) {
        int temp = arr[1];
        arr[1] = arr[i];
        arr[i] = temp;
        sort(arr,1, i-1);
    }

}

int main() {
    int arr[] = {0,27,15,19,18,28,34,65,49,25,37};
    int n = sizeof(arr) / sizeof(int);
    func(arr, 10);
    printf("\n");
    for (int i = 1; i<=9; i++) {
        printf("%d ", arr[i]);
    }
}