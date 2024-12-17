#include<stdio.h>
#include<stdlib.h>
#include <string.h>
void getnext(char sub[], int n, int *next) {
    int i =0, j = -1;
    next[0] = -1;
    while(i < n) {
        if (j == -1 || sub[i] == sub[j]) {
            i++;j++;
            next[i] = j; 
        }else {
            j = next[j];
        }
    }
}
// void computeNext(char *pattern, int *next, int patternLength) {
//     int i = 0, j = -1;
//     next[0] = -1;
//     while (i < patternLength) {
//         if (j == -1 || pattern[i] == pattern[j]) {
//             i++;
//             j++;
//             next[i] = j;
//         } else {
//             j = next[j];
//         }
//     }
// }

void getnextval(char sub[], int n, int *next) {
    int i =0, j = -1;
    next[0] = -1;
    while(i < n) {
        if (j == -1 || sub[i] == sub[j]) {
            i++;j++;
            if (sub[i] != sub[j]) {
                next[i] = j; 
            }else {
                next[i] = next[j];
            }
            
        }else {
            j = next[j];
        }
    }
}
// abaabcaba


// int main() {
//     char pattern[] = "aacaab";
//     int patternLength = strlen(pattern);
//     int next[patternLength];
//     computeNext(pattern, next, patternLength);
//     for (int i = 0; i < patternLength; i++) {
//         printf("%d ", next[i]);
//     }
//     printf("\n");
//     return 0;
// }
int main(){
    char str[] = "abaabdabacsadabaabcabakjsdfaabaabcabaasdsad";
    // abaabcaba
    char sub[] = "ababcabab";
    int next[strlen(sub)];
    getnext(sub, sizeof(sub) - 1, next);
    for(int i = 0; i < sizeof(sub) - 1; i++)
        printf("%d ", next[i]);

}

