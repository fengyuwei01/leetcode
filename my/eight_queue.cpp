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
int chess[N][N] = {0};

void chess_visitor() {
    int i=0,j=0;
    for(;i<N;i++) {
        for(j=0;j<N;j++) {
            cout << " " << chess[i][j] << " ";
        }
        cout << endl;
    }
}

// 约束条件
bool queue_constrain(int x,int y) {
    int i,j;

    // 同列
    for (i=0;i<x;i++) {
        if (chess[i][y] > 0) {
            return false;
        }
    }
    
    // 对角线
    for ( i = x-1,j = y-1; i>=0 && j>=0; i--,j--) {
        if (chess[i][j] > 0) {
            return false;
        }
    }

    for ( i=x-1,j=y+1;i>=0 && y<N; i--,j++) {
        if (chess[i][j] > 0) {
            return false;
        }
    }

    if (x==0) {
        printf("x,y [%d,%d]\n",x,y);
    }
    return true;
}

int g_count = 0;
void _eight_queue(int level) {
    if (level >= N) {
        cout << "ok" << ":" << ++g_count << endl;
        // if (g_count > 3) exit(0);
        chess_visitor();
        return;
    } else {
        int i;
        for (i=0;i<N;i++) {
            if ( level == 0 && i > 1) {
                printf("level:%d i:%d\n",level,i);
            }
            chess[level][i] = 1;
            if (queue_constrain(level,i)) {
                _eight_queue(level+1);
            }
            chess[level][i] = 0;
        }
    }
}

void eight_queue() {
    // 初始化
    _eight_queue(0);
}


int main() {
    cout << "--------------------eight_queue-------------" << endl;
    eight_queue();
}
