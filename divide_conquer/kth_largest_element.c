// https://leetcode.com/problems/kth-largest-element-in-an-array/description/

int _partition(int *data,int i,int j) {
    int tmp = data[i];

    while (i<j) {
        while (data[j] >= tmp && i<j) {j--;}
        data[i] = data[j];
        while (data[i] < tmp && i<j) {i++;}
        data[j] = data[i];
    }

    data[i] = tmp;

    return i;
}

int g_len,g_k;

int _find_Kth_largest(int *data,int left,int right) {
    int pivot = _partition(data,left,right);
    if (pivot == g_len - g_k) {
        return data[pivot];
    } else if (pivot > g_len - g_k) {
       return _find_Kth_largest(data,left,pivot-1);
    } else {
       return _find_Kth_largest(data,pivot+1,right);
    }
}

int findKthLargest(int* nums, int numsSize, int k) {
    g_len = numsSize;
    g_k = k;
    return _find_Kth_largest(nums,0,numsSize-1);
}
