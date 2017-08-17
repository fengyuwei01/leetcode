#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string.h>
using namespace std;
// ---------------------------------------
// 八皇后问题
// 8X8格的国际象棋上摆放八个皇后，使其不能互相攻击，
// 即任意两个皇后都不能处于同一行、同一列或同一斜线上。
#define N 8
int g_chess[N][N];

void chess_visitor() {
    int i=0,j=0;
    for(;i<N;i++) {
        for(j=0;j<N;j++) {
            cout << " " << g_chess[i][j] << " ";
        }
        cout << endl;
    }
}

// 约束条件
bool queen_constrain(int x,int y) {
    int i,j;
    if (x == 0)
    {
        return true;
    }

    // 同列
    for (i=0;i<x;i++) {
        if (g_chess[i][y] == 1) {
            return false;
        }
    }
    
    // 对角线
    for ( i = x-1,j = y-1; i>=0 && j>=0; i--,j--) {
        if (g_chess[i][j] == 1) {
            return false;
        }
    }

    for ( i=x-1,j=y+1;i>=0 && j<N; i--,j++) {
        if (g_chess[i][j] == 1) {
            return false;
        }
    }

    return true;
}

int g_count = 0;
void _eight_queen(int level) {
    if (level >= 8) {
        cout << "ok" << ":" << ++g_count << endl;
        // if (g_count > 3) exit(0);
        chess_visitor();
        return;
    } else {
        int i;
        for (i=0;i<N;i++) {
            if (queen_constrain(level,i)) {
                g_chess[level][i] = 1;
                _eight_queen(level+1);
                g_chess[level][i] = 0;
            }
        }
    }
}

void eight_queue() {
    // 初始化
    memset(g_chess,0,sizeof(g_chess));
    _eight_queen(0);
}


int main() {
    cout << "--------------------eight_queue-------------" << endl;
    eight_queue();
}
