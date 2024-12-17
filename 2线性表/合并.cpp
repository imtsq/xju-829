#include<stdio.h>

typedef struct list{
    int arr[50];
    int length;
}List;

int main() {
    List A, B;
    A.length = 10;
    for (int i = 0; i < A.length; i++) {
        A.arr[i] = i;
    }
    B = A;
    printf("%d", B.arr[5]);
}