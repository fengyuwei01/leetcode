// https://leetcode.com/problems/gray-code/description/

#include <vector>
#include <iostream>
#include "stdlib.h"

using std::vector;
using std::cout;
using std::endl;

int *g_slot;
vector<int> g_graycode;

void _cal_code(int *code,int n) {
   int i;
   int sum = 0;
   for(i=0;i<n;i++) {
       sum = sum * 2 + code[i];
   }
   
   g_graycode.push_back(sum);
}

void _gray_code(int n,int level) {
    if (level >= n) {
        cout << "ok" << endl;
        _cal_code(g_slot,n);
    } else {
        g_slot[level] = 1;
        _gray_code(n,level+1);
        g_slot[level] = 0;
        _gray_code(n,level+1);
    }
}

vector<int> grayCode(int n) {
    g_slot = (int *)malloc(n*sizeof(int));

    memset(g_slot,0,n*sizeof(int));
    g_graycode.clear();

    _gray_code(n,0);

    free(g_slot);
    g_slot = NULL;

    return g_graycode;
}
int main() {
    grayCode(2);
}
