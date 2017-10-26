// https://leetcode.com/problems/target-sum/description/
#include <vector>
using namespace std;

int g_count = 0;
// 先考虑回溯方法
void _findTargetSum_backtracking(vector<int> &nums,int level,int target,int sum) {
    if (level >= nums.size()) {
        if (sum == target) { g_count++; }
    } else {
        _findTargetSum_backtracking(nums,level+1,target,sum+nums[level]);
        _findTargetSum_backtracking(nums,level+1,target,sum-nums[level]);
    }
}

// 用backtracking算法也能ac，但是效率比较低
int findTargetSumWays(vector<int>& nums, int S) {
    g_count = 0;
    _findTargetSum_backtracking(nums,0,S,0); 
    return g_count;
}

int main(int argc,char **argv) {
    vector<int> nums(5,1);
    int count = findTargetSumWays(nums,3);
    printf("count:%d\n",count);
}
