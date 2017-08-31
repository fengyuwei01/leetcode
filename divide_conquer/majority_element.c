// https://leetcode.com/problems/majority-element/description/
#include "stdlib.h"
#include "stdio.h"

void _print(int *data,int i,int j);

int g_len;

int _partition(int *data,int i,int j) {
    int tmp = data[i];

    int k = 0;

    while (i<j) {
        while (data[j] >= tmp && i<j) {j--;}
        data[i] = data[j];
        while (data[i] < tmp && i<j) {i++;}
        data[j] = data[i];

        printf("i:%d,j:%d\n",i,j);

        while (k++ > 20) {
            exit(0);
        }
    }

    data[i] = tmp;

    return i;
}

int _majority_element(int *data,int left,int right) {
    int pivot = _partition(data,left,right); 
    if (pivot == g_len/2) {
        return data[pivot];
    } else {
        if (pivot > g_len/2) {
            return _majority_element(data,left,pivot-1);
        } else {
            return _majority_element(data,pivot+1,right);
        }
    }
}


int majorityElement(int* nums, int numsSize) {
    g_len = numsSize;
    return _majority_element(nums,0,numsSize-1);
}

void _print(int *data,int i,int j) {
    for (;i<=j;i++) {
        printf("%d ",data[i]);
    }
    printf("\n");
}

int main() {
    // int num[] = {4,1,2,3,5,6,7,8,9};
    int num[] = {2,2};

    int pivot = _partition(num,0,1);
    _print(num,0,1);
    printf("pivot:%d\n",pivot);
}
