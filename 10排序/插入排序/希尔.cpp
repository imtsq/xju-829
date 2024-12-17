#include <stdio.h>
// 直接插入排序每次选择一个再前面找到合适位置

void sort(int *arr, int n) {
    int i,j;
    int d = n / 2;
    //d一般是除二开始
    while(d > 0) {
        for(i = d; i < n; i++) { //对1和n - 1的位置和前面比较
            int temp = arr[i];
            for(j = i - d; j >= 0; j -= d) {
                if(arr[j] > temp) {
                    arr[j + d] = arr[j];
                }else {
                    break;
                }
            }
            arr[j + d] = temp;
        }
        d = d / 2;
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