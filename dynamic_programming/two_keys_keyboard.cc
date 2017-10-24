// https://leetcode.com/problems/2-keys-keyboard/description/
// D[n][m] = min{D[n-m][n-m],D[n-m][m]} 其中 n-m>0
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

void printArray(vector<int> &arr,int m) {
    std::cout << std::endl;
    std::cout << "---------------------arr-------------------" << std::endl;
    for (int i=0;i<m;i++) {
        std::cout << arr[m] << " ";
    }
    std::cout << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << std::endl;
}

int minSteps(int n) {
    int m = n / 2;
    vector< vector<int> > D(n+1,vector<int>(m+1,1000));
    vector<int> MIN(n+1,-1); // 每行最小值

    D[1][0] = 0;
    D[1][1] = 1;
    MIN[1] = 0;
    for (int i=2;i<=n;i++) {
        for (int j=1;j<=i/2;j++) {
            D[i][j] = D[i-j][j]+1;
            if (i == j*2 && MIN[i/2]+1 < D[i-j][j]) {
                D[i][j] = MIN[i/2]+2;
            }

            std::cout << "i:" << i << ",j:" << j << ",D:" << D[i][j] << std::endl;

            if (MIN[i] < 0 || D[i][j] < MIN[i]) { 
                MIN[i] = D[i][j]; 
            }
        }
    }

    printArray(D,n+1,m+1);

    for(int i=0;i<=n;i++) {
        std::cout << MIN[i] << std::endl;
    }

    printArray(MIN,n+1);

    return MIN[n];
}

int main() {
    int n = 4;

    //minSteps(n);
    vector<int> vect(10,2);
}
