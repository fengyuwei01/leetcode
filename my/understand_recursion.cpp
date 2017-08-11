#include<stdio.h>
#include "string.h"

// 理解递归(recursion)


void far(int sum) {
    
}

void simple_recursion(int val,int *door) {
    if (val <= 0) {
       return; 
    } else {
        // 在这里做了什么工作
        val -= 1;

        // 记下开了几次门
        *door += 1;
        simple_recursion(val,door);
    }
}

// 递归实现回文串判定
// 1. 将回文字符串问题转化为子回文字符串的问题与剩余部分的求解
// 2. 找到简单条件
bool is_palindereme(const char *str,int len) {
    if (len == 1 || len == 0) {
        return true;
    } else {
        printf("%c --------- %c\n",*str,*(str + len -1));
        bool isPal = *str == *(str + len - 1);
        isPal = isPal && is_palindereme(str+1,len-2);
        return isPal;
    }
}

// 二分查找递归实现
bool binary_search(const int *nums,int len,int key) {
    if (len == 1) {
        return *nums == key;
    } else {
        int mid = len / 2;
        int start;
        if (nums[mid] == key) {
            return true;
        } else if (nums[mid] > key) {
            start = 0;
            len = mid;
        } else {
            start = mid + 1;
            len = len - mid;
        }

        return binary_search(nums + start, len ,key);
    }
}

int main() {
    int i=0;
    simple_recursion(9,&i);
    printf("door:%d\n",i);

    char str[] = "level"; 
    bool isPal = is_palindereme(str,strlen(str));
    printf("is_pal:%d\n",isPal);

    int nums[] = {1,2,3,4,5,6,7,8,9,10};

    bool isIn = binary_search(nums,10,5);

    printf("is_in:%d\n",isIn);
}
