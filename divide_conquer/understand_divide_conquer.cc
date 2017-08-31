/**
 * 分支法
 * 1. 原问题分解成子问题
 * 2. 递归的分解问题直到分解成简单可直接解决的子问题
 * 3. 合并子问题的解从而得出原问题解
 */
#include <iostream>
#include "stdlib.h"

using namespace std;

template <class T>
void _merge(T *num,int start,int mid,int end) {
    T *tmp = (T *)malloc((end-start+1)*sizeof(T));
    int i = start;
    int j = mid+1;
    int k = 0;

    while(i<=mid && j<=end) {
       if (num[i] < num[j]) {
           tmp[k++] = num[i++];
       } else {
           tmp[k++] = num[j++];
       }
    }

    if (i<=mid) {
        for (;i<=mid;i++) {
            tmp[k++] = num[i++];
        }
    } else if (j<=end) {
        for (;j<=end;j++) {
            tmp[k++] = num[j++];
        }
    }

    memcpy(num + start,tmp,sizeof(*tmp));
    free(tmp);

    return;
}

template <class T>
void _merge_sort(T *num,int start,int end) {
    if (start == end) {
        return;
    } else {
        int mid = (start + end) / 2;
        _merge_sort(num,start,mid);
        _merge_sort(num,mid+1,end);

        _merge(num,start,mid,end);
    }
}

template <class T>
void merge_sort(T *num,int len) {
    _merge_sort(num,0,len-1); 
}

int main() {
    int num[] = {7,6,5,4,3,2,1};
    merge_sort(num,7);

    for(int i=0;i<7;i++) {
        cout << *num + i << " ";
    }

    cout << endl;

    int s = getchar();
}
