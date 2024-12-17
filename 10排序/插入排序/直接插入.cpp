#include <stdio.h>
// 直接插入排序每次选择一个再前面找到合适位置

void sort(int *arr, int n) {
    int i,j;
    for(i = 1; i < n; i++) { //对1和n - 1的位置和前面比较
        int temp = arr[i];
        for(j = i - 1; j >= 0; j--) {
            if(arr[j] > temp) {
                arr[j + 1] = arr[j];
            }else {
                break;
            }
        }
        arr[j + 1] = temp;
    }
    
}
int main() {
    int arr[] = {6,8,7,9,0,1,3,2,4,5};
    int n = sizeof(arr)/sizeof(int);
    sort(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
}