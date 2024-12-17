#include<stdio.h>


int sort(int arr[], int s, int e) 
{
    int i = s, j = e, temp = arr[i];
    while ( i < j) {
        while(i < j && arr[j] >= temp) {
            j--;
        }
        arr[i] = arr[j];
        while( i < j && arr[i] < temp) {
            i++;
        }
        arr[j]  = arr[i];
    }
    arr[i] = temp;
    for(int i = 0; i < 11; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return i;
}

void func(int arr[], int i, int j) {
    int mid = (i + j) /2;
    if (i < j) {
        mid = sort(arr, i, j);
        func(arr, i, mid - 1);
        func(arr, mid + 1, j);

    }
}

int main() {
    int arr[] = {6,8,7,9,0,1,3,2,4,5};
    func(arr, 0, 10 - 1);
    for(int i = 0; i < 11; i++) {
        printf("%d ", arr[i]);
    }
}