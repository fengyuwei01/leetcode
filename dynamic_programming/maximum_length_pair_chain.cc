// https://leetcode.com/problems/maximum-length-of-pair-chain/description/
// 1.按照第一个pair从小到大排序
// 2. D[i] 表示已i项结尾的最大chain值
// D[i] = max{D[j]} + 1 && pair[j][1] < pair[i][0]

#include <iostream>
#include <vector>
#include <algorithm> // sort

using namespace std;

bool _cmp(vector<int> v1,vector<int> v2) {
    return v1[0] < v2[0] || (v1[0] == v2[0] && v1[1] < v2[1]);
}

int findLongestChain(vector<vector<int>>& pairs) {

    int l = pairs.size();
    vector<int> D(l,1);

    // 排序
    sort(pairs.begin(),pairs.end(),_cmp);

    int g_max= 1;
    for(int i=1;i<l;i++) {
        for (int j=0;j<i;j++) {
            int max = D[i];
            if (pairs[j][1] < pairs[i][0] && D[j]+1 > max) {
                max = D[j]+1;
            }
            D[i] = max;

            if (g_max < max) {
                g_max = max;
            }
        }
    }

    return g_max;

}

int main(int argc,const char **argv) {
}
