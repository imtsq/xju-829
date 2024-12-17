#include<stdio.h>
#include<string.h>
void getnext(char *s, int n, int next[]){
    int k = -1, i = 0;
    next[i] = -1;
    while(i < n) {
        if (k == -1 || s[k] == s[i]) {
            k++;
            i++;
            next[i] = k;
        }
        else {
            k = next[k];
        }
    }
}
void getnextval(char *s, int n, int nextval[]){
    int k = -1, i = 0;
    nextval[i] = -1;
    while(i < n) {
        if (k == -1 || s[k] == s[i]) {
            k++;
            i++;
            if(s[i] == s[k])
               nextval[i] = nextval[k]; 
            else
            nextval[i] = k;
        }
        else {
            k = nextval[k];
        }
    }
}

int main(){
    char str[] = "abaabdabacsadabaabcabakjsdfaabaabcabaasdsad";
    // abaabcaba
    char sub[] = "ababaaab";
    int next[strlen(sub)];
    getnextval(sub, sizeof(sub) - 1, next);
    for(int i = 0; i < sizeof(sub) - 1; i++)
        printf("%d ", next[i]);

}
