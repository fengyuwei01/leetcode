// https://leetcode.com/problems/burst-balloons/description/

#include <iostream>
#include <vector>

using namespace std;

// 盲搜
int _max_coins_ori(vector<int>& nums) {
    if (nums.size() == 1) {
        return nums[0];
    } else {
        int max = -1;
        for (int i=0;i<nums.size();i++) {
            int mu;
            if (i == 0) {
                mu = nums[i]*nums[i+1];
            } else if (i==nums.size()-1) {
                mu = nums[i-1]*nums[i];
            } else {
                mu = nums[i-1]*nums[i]*nums[i+1];
            }

            // 创建
            vector<int> vec;
            vec.assign(nums.begin(),nums.end());
            vec.erase(vec.begin()+i);

            int t = mu + _max_coins_ori(vec);
            if (t > max) {
                max = t;
            }
        }

        return max;
    }
}

int maxCoins(vector<int> &nums) {
    return _max_coins_ori(nums);
}

int main(int argc,char **argv) {
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(5);
    nums.push_back(8);

    int i = maxCoins(nums);
    cout << "result:" << i << endl;
}
