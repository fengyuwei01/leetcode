// https://leetcode.com/problems/partition-equal-subset-sum/description/
//
// D[n][j] = D[n-1][j] || D[n-1][j - v[n-1]]
// D[i][0] = 1 
// D[0][i] = 0
// 背包模型
//
// 好开心，居然自己想到了这个办法！
#include<vector>
#include "../array_util.hpp"
using namespace std;

class Solution {
    public:
        bool canPartition(vector<int>& nums) {
            int sum = 0, len = nums.size();
            for(int i=0;i<len;i++) {
                sum += nums[i];
            }

            if (sum % 2 != 0) {
                // 总和为奇数
                return false;
            }

            vector< vector<int> > D(len+1,vector<int>(sum/2+1,0));
            for(int i=0;i<=len;i++) {D[i][0] = 1;}

            for (int i=1;i<=len;i++) {
                for (int j=1;j<=sum/2;j++) {
                    // printf("i:%d,j:%d\n",i,j);
                    if (j >= nums[i-1]) {
                        if (D[i-1][j] == 1 || D[i-1][j-nums[i-1]] == 1) {
                            D[i][j] = 1;
                        }
                        // D[i][j] = D[i-1][j] + D[i-1][j-nums[j-1]];
                    } else {
                        D[i][j] = D[i-1][j];
                    }
                }
                printArray(D,len+1,sum/2+1);
            }

            printArray(D,len+1,sum/2+1);

            return D[len][sum/2] > 0;
        }
};

int main() {
    int a[] = {2,1,1,1,1};

    vector<int> nums(a,a+5);
    
    Solution solve;
    printf("%d\n",solve.canPartition(nums));
}
