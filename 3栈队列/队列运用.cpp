#include<stdio.h>
const int Max = 9;
typedef struct queue {
    int arr[Max];
    int rear, front;
}queue;


int main(){
    queue q;
    q.front = 0;
    q.rear = 0;
    for (int i = 0; i <= 8; i++) {
        q.arr[i] = i;
    }
    q.front = 8;
    while(q.front != q.rear) {
        q.rear = (q.rear + 1) % Max;
        printf("%d ", q.arr[q.rear]);
        q.front = (q.front + 1) % Max;
        if (q.front != q.rear) {
            q.rear = (q.rear + 1) % Max;
            q.arr[q.front] = q.arr[q.rear];
        }
    }
    

}