// https://leetcode.com/problems/combination-sum/description/
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> g_sum_list;

// 存储当前选择
vector<int> g_sum;
int sum;

void _combination_sum(const vector<int>& candidates,int current,int target) {
    if (sum > target) {
        return;
    } else if (sum == target) {
        g_sum_list.push_back(g_sum);
        return;
    } else {
       for (int i=current;i<candidates.size();i++) {
           // 选择节点
           g_sum.push_back(candidates[i]);
           sum = sum + candidates[i];
           _combination_sum(candidates,i,target);
           // 回退
           sum = sum - candidates[i];
           g_sum.pop_back();
       }
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    // 排序
    sort(candidates.begin(),candidates.end());

    // 初始化
    sum = 0;
    g_sum.clear();
    g_sum_list.clear();
    
    _combination_sum(candidates,0,target);

    return g_sum_list;
}
