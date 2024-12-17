#include <stdio.h>

void sort(int *arr, int n) {
    int i,j,low, high, mid, temp;
    for(i = 1; i < n; i++) { //对1和n - 1的位置和前面比较
        if (arr[i - 1] > arr[i]){
            int temp = arr[i];
            low = 0; high = i - 1;
            while(low <= high) {
                mid = (high +  low) / 2;
                if (temp < arr[mid]) {
                    high = mid - 1;
                }else {
                    low = mid + 1;
                }
            }
            for(j = i - 1; j >= high + 1; j--) {
                arr[j + 1] = arr[j];
            }     
             arr[high + 1] = temp;
        }
          
       
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