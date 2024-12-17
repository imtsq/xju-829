#include<stdio.h>
#define V 5
int n = V;
int graph[V][V] = {
         {999, 2, 999, 6, 999},
        {2, 999, 3, 8, 5},
        {999, 3, 999, 999, 7},
        {6, 8, 999, 999, 9},
        {999, 5, 7, 9, 999}
    };
void prime(int v) {
    int low[V];
    int join[V];
    int Min;
    for(int i = 0; i < n; i++) {
        low[i] = graph[v][i];
        join[i] = v;
    }
    int k;
    for(int i = 1; i < n; i++) {
        Min = 999;
        for(int j = 0; j < n; j++)
        if (low[j] != 0 && Min > low[j]) {
            Min = low[j];
            k = j;
        }
        printf("%d ->%d distance=%d\n",join[k], k, Min);
        low[k] = 0;//想到与加入这个集合
        // 新加入得边再和未加入的边比较找几个A到集合B的最短距离
        for(int j = 0; j < n; j++) {
            if(low[j] != 0 && graph[k][j] < low[j]) {
                low[j] = graph[k][j];
                join[j] = k;
            }
        }
    }

}

int main () {
    prime(0);
}