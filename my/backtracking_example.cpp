#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string.h>
using namespace std;

vector<int> sub_set;
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


int main() {
    vector<int> s;
    s.push_back(1);
    s.push_back(2);
    s.push_back(3);

    power_set(s,vector_visitor);
}
