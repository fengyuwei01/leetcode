// https://leetcode.com/problems/burst-balloons/description
#include <vector>
#include <iostream>
#include <iterator>
#include <stdio.h>
using namespace std;

using std::vector;

int _max_coins(vector<int> &nums) {
    if (nums.size() == 0) {
        return 0;
    } else {
        vector<int>::iterator it;
        int tmp = 1;
        int tmp1 = 0;
        int max = 0;
        for(it = nums.begin();it != nums.end();it++) {
            tmp = 1;
            tmp1 = *it;

            if (nums.size() == 1) {
                tmp = *it;
            }
            else if (it == nums.begin()) {
                tmp = (*it) * (*(it+1));
            } else if (it == nums.end()) {
                tmp = (*it) * (*(it-1));
            } else {
                tmp = (*it) * (*(it-1)) * (*(it+1));
            }
            
            nums.erase(it);
            cout << "tmp:" << tmp << endl;
            // 打印
            copy (nums.begin(), nums.end(), ostream_iterator<int> (cout, " ")); 
            cout << endl;
            cout << endl;

            tmp = tmp + _max_coins(nums);

            // 回溯
            nums.insert(it,tmp1);
            cout << "backtracking:";
            copy (nums.begin(), nums.end(), ostream_iterator<int> (cout, " ")); 
            cout << endl;

            if (max < tmp) {
                max = tmp;
            }
            
            cout << "max:" << max << endl;
        }

        return max;
    }
}

int maxCoins(vector<int>& nums) {
   return _max_coins(nums); 
}

int main() {
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(8);

    int result = maxCoins(nums);

    std::cout << "result:" << result << std::endl;
}
