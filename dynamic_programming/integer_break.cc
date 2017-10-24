// https://leetcode.com/problems/integer-break/description/

#include <vector>
using namespace std;

int _max(int a,int b) {
    return a > b ? a : b;
}

int integerBreak(int n) {
    vector<int> D(n+1,0);
    D[1] = 1;

    for(int i=2;i<=n;i++) {
        int max = i-1;
        for (int j=1;j<i;j++) {
            int tmp = 
            max = _max(max,_max(j,D[j])*_max(i-j,D[i-j]));
        }
        D[i] = max;
    }

    return D[n];
}

int main(int argc, char **argv) {
    int n = 4;
    int max = integerBreak(n);

    printf("%i\n",max);
}


