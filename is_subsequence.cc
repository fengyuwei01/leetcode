// https://leetcode.com/problems/is-subsequence/description/
// D[i][j] = D[i-1][j-1] && s[i] == t[i]
// D[i][j] = D[i][j-1] && s[i] != t[j]
// D[0][j] = true
// D[i][0] = false && i > 0

#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;

void printArray(vector<vector<int> > &arr,int m,int n) {
    std::cout << std::endl;
    std::cout << "---------------------arr-------------------" << std::endl;
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "------------------------------------------" << std::endl;
    std::cout << std::endl;
}

bool isSubsequence(string s, string t) {
    int m = s.size(),n = t.size();

    // 初始化数组
    vector< vector<int> > D(m+1,vector<int>(n+1));
    for (int i=1;i<=m;i++) {
        D[i][0] = 0;
    }
    for (int j=0;j<=n;j++) {
        D[0][j]=1;
    }

    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            if (s[i-1] == t[j-1]) {
                D[i][j] = D[i-1][j-1];
            } else {
                D[i][j] = D[i][j-1];
            }
        }
    }

    printArray(D,m+1,n+1);
    return D[m][n] == 1 ? true : false;
}


// 滚动数组优化
bool isSubsequence1(string s, string t) {
    int m = s.size(),n = t.size();

    // 初始化数组
    vector< vector<int> > D(2,vector<int>(n+1));
    D[1][0] = 0;
    for (int j=0;j<=n;j++) {
        D[0][j]=1;
    }

    printArray(D,2,n+1);

    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            if (i % 2 == 0) {
                // 偶数行
                if (s[i-1] == t[j-1]) {
                    D[0][j] = D[1][j-1];
                } else {
                    D[0][j] = D[0][j-1];
                }
            } else {
                // 奇数行
                if (s[i-1] == t[j-1]) {
                    D[1][j] = D[0][j-1];
                } else {
                    D[1][j] = D[1][j-1];
                }
            }
        }
        // 重新计算行首元素
        if (D[0][0] == 1) {
            D[0][0] = 0;
        }
        printArray(D,2,n+1);
    }

    printArray(D,2,n+1);

    if (m % 2 == 0) {
        return D[0][n] == 1 ? true : false;
    } else {
        return D[1][n] == 1 ? true : false;
    }
}

// 滚动数组优化
// 采用C数组结构
bool isSubsequence3(string s, string t) {
    int m = s.size(),n = t.size();

    // 初始化数组
    int **D = new int *[2];
    int *data = new int [2*(n+1)];
    for(int i=0;i<2;i++) {
        D[i] = data + i*(n+1);
    }

    D[1][0] = 0;
    for (int j=0;j<=n;j++) {
        D[0][j]=1;
    }

    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            if (i % 2 == 0) {
                // 偶数行
                if (s[i-1] == t[j-1]) {
                    D[0][j] = D[1][j-1];
                } else {
                    D[0][j] = D[0][j-1];
                }
            } else {
                // 奇数行
                if (s[i-1] == t[j-1]) {
                    D[1][j] = D[0][j-1];
                } else {
                    D[1][j] = D[1][j-1];
                }
            }
        }
        // 重新计算行首元素
        if (D[0][0] == 1) {
            D[0][0] = 0;
        }
    }

    int r = 0;
    if (m % 2 == 0) {
       r = D[0][n];
    } else {
       r = D[1][n];
    }

    delete[] D;
    delete[] data;

    return r == 1;
}

int main(int argc,const char **argv) {
    // string s = "abc";
    // string t = "ahbgdc";
    
    string s = "axc";
    string t = "ahbgdc";

    int is = isSubsequence1(s,t);

    std::cout << "r:" <<  is << std::endl;
    return 0;
}
