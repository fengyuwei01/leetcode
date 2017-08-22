// https://leetcode.com/problems/binary-watch/description/
#include<vector>
#include<string>
#include<iostream>
#include "stdio.h"
#include "stdlib.h"
using namespace std;

int g_slot[10];
vector<string> g_times;
int g_count = 0;

void print_arr(int a[],int len) {
    int i = 0;
    cout << "{";
    for (;i<len;i++) {
        cout << " [" << a[i] << "] ";
    }
    cout << "}" << endl;
}

bool _cal_time() {
    int i=0;
    int hour=0,min=0;
    string time;
    // 计算小时
    for(;i<4;i++) {
        hour = hour*2 + g_slot[i];
    }

    // 计算分钟 
    for (i=4;i<10;i++) {
        min = min*2 + g_slot[i];
    }

    if (hour <=11 && min <=59) {
        time.append(to_string(hour));
        time.append(":");
        if (min < 10) {
            time.append("0");
        }
        time.append(to_string(min));
        print_arr(g_slot,10);
        cout << "ok:" << ++g_count << ",time:" << time << endl;
        g_times.push_back(time);
    }

    return true;
}

void _read_binary_watch(int num,int start) {
    if (num <=0) {
        _cal_time();
        return;
    } else {
        int i=0; 
        for (i=start;i<=10-num;i++) {
            // if (g_slot[i] == 0) { // 判断该位置还没有放置
                g_slot[i] = 1;
                _read_binary_watch(num-1,i+1);
                g_slot[i] = 0;
            // }
        }
    }
}

vector<string> readBinaryWatch(int num) { 
    // 初始化
    memset(g_slot,0,sizeof(int)*10);
    g_count = 0;
    g_times.clear(); 
    _read_binary_watch(num,0);
    return g_times;
}

int main() {
    readBinaryWatch(2);
}

