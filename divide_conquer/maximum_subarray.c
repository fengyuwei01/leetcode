// https://leetcode.com/problems/maximum-subarray/description/
#include "stdio.h"

inline int max(int a,int b) {
    return a > b ? a : b;
}

int _max_sub_array_across_mid(int *nums,int left,int mid,int right) {
    int i = mid,max = nums[mid],tmp = 0;
    for(;i >= left;i--) {
        tmp = tmp + nums[i];
        if (tmp > max) {
            max = tmp;
        }
    }
    tmp = max;
    for (i = mid + 1;i <= right;i++) {
        tmp = tmp + nums[i];
        if (tmp > max) {
            max = tmp;
        }
    }

    return max;
}

int _max_sub_array(int *nums,int left,int right) {
    if (left == right) {
        return nums[left];
    } else {
        int mid = (left + right) / 2;
        int left_max = _max_sub_array(nums,left,mid);
        int right_max = _max_sub_array(nums,mid+1,right);

        // merge
        int across_max = _max_sub_array_across_mid(nums,left,mid,right);

        return max(max(left_max,right_max),across_max);
    }
}

int maxSubArray(int* nums, int numsSize) {
    return _max_sub_array(nums,0,numsSize-1); 
}

int main() {
}
