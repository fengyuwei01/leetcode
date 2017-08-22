// https://leetcode.com/problems/combination-sum-iii/description/

#include <vector>
using namespace std;

int sum;
vector<int> g_sum;
vector<vector<int>> g_sum_list;

void _combination_sum3(int k,int n,int current,int level) {
    if (sum > n || level >= k) {
        if (level == k && sum == n) {
            g_sum_list.push_back(g_sum);
        }
        return;
    } else {
        for(int i=current;i<=9;i++) {
            g_sum.push_back(i);
            sum = sum + i;
            _combination_sum3(k,n,i+1,level+1);
            sum = sum - i;
            g_sum.pop_back();
        }
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    sum = 0;
    g_sum.clear();
    g_sum_list.clear();

    _combination_sum3(k,n,1,0);

    return g_sum_list;
}


