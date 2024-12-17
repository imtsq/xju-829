[TOC]

---

# 暴力求解

暴力求解：如果发送不匹配模式串和主串都会回退

```cpp
int BF(char arr[], int n, char sub[], int len) {
    int i = 0, j = 0;
    while(i<n && j < len) {
        if (arr[i] == sub[j]) {
            i++;j++;
        }else {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j == len - 1) {
        return 1;
    }
    return 0; //失败
}
```



# KMP特点

相对暴力求解来说，不用回溯目标串，只是模式串的移动

- 这本书开始节点位置0和1即next[0] = -1,next[1] = 0;
- 难点只要是求next数组

## 为什么KMP能够缩短查询时间

比如串aacaab,其中当查询到b字符时发现模式串和目标串发送不匹配，对于暴力求解方法是将模式串index = 0，但是其实模式串中b前面的都匹配成功了，aacaa只是b点不同，最大前后缀相当于caa中的aa肯定和目标串中的aa匹配，又和模式串aac中的aa匹配所有只需c点和目标串当前位置匹配就行，

```cpp
void next(char sub[], int n) {
    int i =0, j = -1;
    sub[0] = -1;
    while(i < n) {
        if (j = -1 || sub[i] == sub[j]) {
            i++;j++;
            sub[i] = j; 
        }else {
            j = next[j];
        }
    }
}
```

