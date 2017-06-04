#include <string>
#include <iostream>

using namespace std;

void printArray(int arr[],int len) {
    for(int i=0;i<len;i++) {
        cout << arr[i] ;
        if (i+1==len) {
            cout << endl;
        }else {
            cout << ',';
        }
    }
}

class Solution {
public:
    char findTheDifference(string s, string t) {
        int alphabet1[26];
        int alphabet2[26];
        int index = -1;
        for (int i=0;i<26;i++) {
            alphabet1[i]=0;
            alphabet2[i]=0;
        }
        for (int i=0;i<s.length();i++) {
            index = s[i] - 'a';
            cout << s[i] << ',' << index << endl;
            alphabet1[index]++;
            printArray(alphabet1,26);
        }
        printArray(alphabet1,26);
        for (int i=0;i<t.length();i++) {
            index = t[i] - 'a';
            cout << t[i] << ',' << index << endl;
            alphabet2[index]++;
        }
        printArray(alphabet2,26);
        for (int i=0;i<26;i++) {
           if(alphabet1[i] != alphabet2[i]) {
               return 'a'+i;
           } 
        }
        return 0;
    }
};

int main() {
    Solution solution;

    string s="abcd";
    string t="abcde";
    char a=solution.findTheDifference(s,t);

    cout << "a:" << a << endl;
}
