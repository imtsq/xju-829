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
void dijkstra(int v) {
    int dist[V];//最小距离
    int s[V];//表示加入
    int Min;
    int Path[V];//路径
    for(int i = 0; i < n; i++) {
        dist[i] = graph[v][i];
        s[i] = 0; //判断算法加入
        if(graph[v][i] < 999) {
            Path[i] = v;
        }else {
            Path[i] = -1;
        }
    }
    int k;
    for(int i = 1; i < n; i++) {
        Min = 999;
        for(int j = 0; j < n; j++)
        if (s[j] == 0 && Min > dist[j]) {
            Min = dist[j];
            k = j;
        }
        s[k] = 1;//想到与加入这个集合
        // 新加入得边再和未加入的边比较找几个A到集合B的最短距离
        for(int j = 0; j < n; j++) {
            if(s[j] == 0)
                //和prime不一样的是prime只是找集合到另一个几个最小，这里是源点到另一个点距离最小dist[k] + graph[k][j] < dist[j]
                if(graph[k][j] < 999 && dist[k] + graph[k][j] < dist[j]) {
                    dist[j] = dist[k] + graph[k][j];
                    Path[j] = k;
                }
        }
    }

}

int main () {
    dijkstra(0);
}