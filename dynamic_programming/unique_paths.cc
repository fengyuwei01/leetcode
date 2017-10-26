// https://leetcode.com/problems/unique-paths/description/
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

// D[i][j] = D[i][j-1] + D[i-1][j]

int uniquePaths(int m, int n) {
    vector< vector<int> > D(m,vector<int>(n,0));

    for(int i=0;i<m;i++) {
        D[i][0] = 1;
    }

    for(int i=0;i<n;i++) {
        D[0][i] = 1;
    }
    
    for(int i=1;i<m;i++) {
        for(int j=1;j<n;j++) {
            D[i][j] = D[i][j-1] + D[i-1][j];
        }
    }

    return D[m-1][n-1];
}

int main() {
}
