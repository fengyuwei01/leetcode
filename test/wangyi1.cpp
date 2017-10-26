// 回溯 & 剪枝可以实现
// 回溯法搜索全排列树  
  
#include<stdio.h>  
#include<string>
#include<set>
using namespace std;
  
set<string> string_set;
void swap(char *a, char *b)//交换a,b  
{  
    char t;  
    t = *a;  
    *a = *b;  
    *b = t;  
}  

bool is_perfect(char *str,int size) {
    int i = 0;
    int cnt = 0;
    while ( i < size-1 ) {
       if (str[i] != str[i+1]) {
           cnt++;
       }
       if (cnt > 1) {
           return false;
       }

       i++;
    }

    return true;
}
  
void backtrack(char *str,int len,int cur)  
{  
    int i;  
    if (!is_perfect(str,cur)) {
        return;
    }
    if(cur == len)// 找到 输出全排列  
    {  
        string_set.insert(string(str));
    }  
    else  
    {  
         // 将集合中的所有元素分别与第一个交换，这样就总是在  
        // 处理剩下元素的全排列(即用递归)  
        for(i=cur; i<len; i++)  
        {  
            swap(&str[cur], &str[i]);  
            backtrack(str,len,cur+1);  
            swap(&str[cur], &str[i]);//回溯  
        }  
    }  
}  
  
  
int main()  
{  
    char a[] = {'A','B','A','B'};
    backtrack(a,4,0);  
    printf("string_set_size:%d\n",string_set.size());
    return 0;  
}  
