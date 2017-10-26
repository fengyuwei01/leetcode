// Longest Palindromic Subsequence
// https://leetcode.com/problems/longest-palindromic-subsequence/description/
// 典型区间模型
// D[i][j] 表示i~j子串最长回文串
// D[i][j] = max{D[i+1][j],D[i][j-1]} && s[i] != s[j]
// D[i][j] = D[i+1][j-1] + 2
//
// D[i][j] = 1 && i=j
// D[i][j] = 0 && i>j

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int longestPalindromeSubseq(string s) {
    int len = s.length();
    vector< vector<int> > D(len,vector<int>(len,0));
    for (int i=0;i<len;i++) {
        D[i][i] = 1;
    }

    for(int l=1;l<len;l++) {
       for(int i=0;i+l<len;i++) {
           int j = i+l;
           if (s[i] == s[j]) {
               D[i][j] = D[i+1][j-1] + 2;
           } else {
               D[i][j] = max(D[i+1][j],D[i][j-1]);
           }
       }
    }

    return D[0][len-1];
}

int main(int argc,char **argv) {
}
