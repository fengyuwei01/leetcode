// https://leetcode.com/problems/palindromic-substrings/description
// D[i][j] = D[i+1][j-1] && s[i] == s[j]
// D[i][i] = 1
#include <string>
#include <iostream>
#include <vector>

using namespace std;

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

int countSubstrings(string s) {
    int m = s.size();

    // 初始化数组
    vector< vector<int> > D(m,vector<int>(m,0));

    int c = 0,n = 0;
    for (int l=1;l<=m;l++) {
        for (int i=0;i+l<=m;i++) {
            int j = i+l-1;
            n++;
            if (s[i] == s[j] && (j - i <= 1 || D[i+1][j-1] == 1)) {
                cout << n << ":" << i << "," << j << endl;
                cout << s[i] << "<->" << s[j] << endl << endl;
                D[i][j] = 1;
                c++;
            }
        }
    }

    cout << "n:" << n << endl;

    printArray(D,m,m);

    return c;
}

int main() {
    //string s = "aaa";
    string s = "fdsklf";
    int c = countSubstrings(s);
    cout << "c:" << c << endl;

    return 0;
}

