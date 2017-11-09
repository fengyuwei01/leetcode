// https://leetcode.com/problems/wiggle-subsequence/description/

#include "../array_util.hpp"
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int len = nums.size();
        printArray(nums,len);

        vector<int> DES(len,1);
        vector<int> INC(len,1);

        int g_max = 0;

        for (int i=0;i<len;i++) {
            for (int j=0;j<i;j++) {
                printf("i:%d,j:%d\n",i,j);
                if (nums[i] > nums[j]) {
                    cout << "INC" << endl;
                    if (INC[i] < DES[j]+1) {
                        INC[i] = DES[j] + 1;
                    }
                }
                if (nums[i] < nums[j]) {
                    cout << "DES" << endl;
                    if (DES[i] < INC[j]+1) {
                        DES[i] = INC[j] + 1;
                    }
                }
                std::cout << "\nINC" << endl;
                printArray(INC,len);
                std::cout << "\nDES" << endl;
                printArray(DES,len);
            }

            if (INC[i] > g_max) {g_max = INC[i];}
            if (DES[i] > g_max) {g_max = DES[i];}
        }

        std::cout << "\nINC" << endl;
        printArray(INC,len);
        std::cout << "\nDES" << endl;
        printArray(DES,len);

        return g_max;
    }
};

int main() {
    // int a[] = {1,7,4,9,2,5};

    // vector<int> nums(a,a+6);
    vector<int>nums(1,84);

    Solution solve;
    int result = solve.wiggleMaxLength(nums);

    printf("\n\nresult:%d\n",result);
}

