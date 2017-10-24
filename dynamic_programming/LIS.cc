// 最长递增子序列(LIS)问题
// D[i] 表示为以a[i]结尾(前i项)序列的LIS长度
//
// d[i] = max{ d[j] | j < i && a[j] < a[i] } + 1
//
// d[i] 表示 f(i) f是最优代价函数，那么这里面的阶段其实是不明显的，用i来表明是处于哪个状态。
// 而转移方程表现出到达某状态的途径有很多条。阶段很不明显。或者可以理解成一个状态一个阶段。

#include <iostream>
#include <vector>
using namespace std;


int LIS(vector<int> a) {
    int i=0,j=0;

    int *D = new int[a.size()];
    D[0] = 0;
    
    for (i=0;i<a.size();i++) {
        int max = 0;
        for (j=0;j<i;j++) {
            if (a[i] > a[j] && D[j] > max) {
               max = D[j]; 
            }
        }

        D[i] = max;
    }
    delete []D;
    return D[a.size()];
}

int main(int argc, char **argv) {
   cout << "hello" << endl; 
}

