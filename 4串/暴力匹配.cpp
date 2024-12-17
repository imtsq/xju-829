#include<stdio.h>
int BF(char arr[], int n, char sub[], int len) {
    int i = 0, j = 0;
    while(i<n && j < len) {
        if (arr[i] == sub[j]) {
            printf("%c %c\n", arr[i], sub[j]);
            i++;j++; 
        }else {
            i = i - j + 1;
            j = 0;
            
        }
        
    }
    if (j == len) {
        printf("%d", j);
        return i - j;
    }
    return 0; //失败
}
int main(){
    char arr[] = "abcdeefscsdfjskldf";
    char sub[] = "scsdfj";

    int n = BF(arr, sizeof(arr) - 1, sub, sizeof(sub) - 1);
    printf("%d", n);
}