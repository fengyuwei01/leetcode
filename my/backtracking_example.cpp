#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string.h>
using namespace std;

// 幂集问题回溯法求解
void vector_visitor(vector<int> &vec) {
    int i = 0;
    cout << "vec:";
    for (;i<vec.size();i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}
void _power_set(const vector<int> &s,int level,vector<int> &buf,void (*visitor)(vector<int> &vec)) {
    if (level >= s.size()) {
        visitor(buf);
        return;
    } else {
        int i = 0;
        // 解空间树为二叉树
        for(;i<2;i++) {
            bool is_sel = i==0;
            if (is_sel) {
                buf.push_back(s[level]);
            }
            _power_set(s,level+1,buf,visitor);
            if (is_sel) {
                buf.pop_back();
            }
        }
    }
}

// 幂集
void power_set(const vector<int> &s,void(*visitor)(vector<int> &vec)) {
    vector<int> buf;
    _power_set(s,0,buf,visitor);
}

// ---------------------------------------
// 八皇后问题
// 8X8格的国际象棋上摆放八个皇后，使其不能互相攻击，
// 即任意两个皇后都不能处于同一行、同一列或同一斜线上。
#define N 8
int chess[N][N] = {0};

void chess_visitor() {
    int i=0,j=0,k=0;
    for(;i<N;i++) {
        for(j=0;j<N;j++) {
            cout << chess[i][j] << " ";
        }
        cout << endl;
    }
}

// 约束条件
bool queue_constrain(int x,int y) {
    if (chess[x][y] > 0) {
        return false;
    }
    // 同行
    int i=0;
    for (;i<N;i++) {
        if (chess[x][i] > 0) {
            return false;
        }
    }
    // 同列
    for (i=0;i<N;i++) {
        if (chess[i][y] > 0) {
            return false;
        }
    }
    // 对角线
    i = 0;
    int j = 0;
    int x0,y0;
    
    for(;i<N;i++) {
        for(j=0;j<N;j++) {
            x0 = x + i - N/2;
            y0 = y + i - N/2;
            if (0<=x0 && x0<N && 0<=y0 && y0<N) {
                if (chess[x0][y0] > 0) {
                    return false;
                }
            }
            x0 = x + i - N/2;
            y0 = y - i + N/2;
            if (0<=x0 && x0<N && 0<=y0 && y0<N) {
                if (chess[x0][y0] > 0) {
                    return false;
                }
            }
        }
    }

    return true;
}

int g_count = 0;
void _eight_queue(int level) {
    if (level >= N) {
        cout << "ok" << " " << ++g_count << endl;
        // if (g_count > 3) exit(0);
        chess_visitor();
        return;
    } else {
        int i,j;    
        for (i=0;i<N;i++) {
            //if (level == 0) {
            // cout << "leve:" << level <<  ",i:" << i << ",j:" << j << endl;
            //}
            if (queue_constrain(level,i)) {
                chess[level][i] = 1;
                _eight_queue(level+1);
                chess[level][i] = 0;
            }
        }
    }
}

void eight_queue() {
    // 初始化
    _eight_queue(0);
}


int main() {
    vector<int> s;
    s.push_back(1);
    s.push_back(2);
    s.push_back(3);

    power_set(s,vector_visitor);
    cout << "--------------------eight_queue-------------" << endl;
    eight_queue();
}
