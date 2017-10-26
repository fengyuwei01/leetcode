// https://leetcode.com/problems/unique-binary-search-trees/description/
// D[i] = sum{D[j]*D[i-j-1]}
// D[1] = 1
// D[0] = 1
#include<vector>
using namespace std;

int numTrees(int n) {
    vector<int> D(n+1,1);
    for (int i=2;i<=n;i++) {
        D[i] = 0;
        for(int j=0;j<=i;j++) {
            D[i] += D[j]*D[i-j-1];
        }
    }

    return D[n];
}
