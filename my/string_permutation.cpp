// 字符串全排列
#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> g_strings;
int g_count = 0;

inline void swap_char(char *a,char *b) {
    if (*a == *b) return;
    char c = *a;
    *a = *b;
    *b = c;
}

// level = 0 其实是在选择第一层
void _string_permutation(char *ch,int len,int level) {
   if (level >= len) {
       string str = string(ch,len);
       // cout << "level:" << level << endl;
       // cout << ++g_count << ":" << ch << endl;
       g_strings.push_back(str);
   } else {
       for (int i=level;i<len;i++) {
           // 选择前level个字母
           swap_char(&ch[level],&ch[i]);
           _string_permutation(ch,len,level+1);
           // 恢复到父节点状态
           swap_char(&ch[level],&ch[i]);
       }
   }
}

void string_permutation(string str) {
    int len = str.size();
    // string => char *
    char *ch = (char *)malloc(len*sizeof(char));
    str.copy(ch,len,0);
    _string_permutation(ch,len,0);
    free(ch);
}

int main() {
    string str = "ABC";
    string_permutation(str);

    vector<string>::iterator iter; 
    for(iter = g_strings.begin();iter !=g_strings.end();iter++) {
        cout << *iter << endl;
    }
}



