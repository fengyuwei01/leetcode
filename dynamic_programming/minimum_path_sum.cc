// https://leetcode.com/problems/minimum-path-sum/description/
// D[i][j] = min{ D[i-1][j],D[i][j-1] }
// D[i][0] = 0
// D[0][i] = 0
#include <algorithm>
#include "../array_util.hpp"

class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        int m = grid.size()+1;
        int n = grid[0].size()+1;

        printf("m:%d,n:%d\n",m,n);

        printArray(grid,m,n);

        vector< vector<int> > D(m,vector<int>(n,0)); 

        for(int i=1;i<m;i++) {
            for(int j=1;j<n;j++) {
                D[i][j] = min(D[i][j-1],D[i-1][j]) + grid[i-1][j-1];
            }
        }

        return D[m][n];
    }
};

int main() {
    vector< vector<int> > grid(3,vector<int>(3));

    int row1[] = {1,3,1};
    grid[0].assign(row1,row1+3);
    int row2[] = {1,5,1};
    grid[0].assign(row2,row2+3);
    int row3[] = {4,2,1};
    grid[0].assign(row3,row3+3);

    Solution solve;
    solve.minPathSum(grid);
}
