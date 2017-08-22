// https://leetcode.com/problems/generate-parentheses/description/
#include <string>
#include <vector>
#include <stack>
#include <list>

using namespace std;

vector<string> g_pars;
vector<char> g_par;
list<char> g_stack;

int _is_valid(char c,int n) {
    if (c == '(') {
        int c = 0;
        for(list<char>::iterator i = g_stack.begin();i != g_stack.end();i++) {
            if (*i == '(') {
                c = c+1;
            }
        }
        return c < n;
    } else {
        if (g_stack.empty()) {
            return false;
        }
    }
    return true;
}

void _gen_parenthesis(int level,int n) {
    if (level >= n*2) {
        if (g_stack.empty()) {
            string tmp(g_par.begin(),g_par.end());
            g_pars.push_back(tmp);
        }
        return;
    } else {
        if (_is_valid('(',n)) {
            g_stack.push_front('(');
            g_par.push_back('(');
            _gen_parenthesis(level+1,n); 
            g_par.pop_back();
            g_stack.pop_front();
        }

        if (_is_valid(')',n)) {
            g_stack.pop_front();
            g_par.push_back(')');
            _gen_parenthesis(level+1,n); 
            g_par.pop_back();
            g_stack.push_front('(');
        }
    }
}

vector<string> generateParenthesis(int n) {
    g_stack.clear();
    g_pars.clear();
    g_par.clear();

    _gen_parenthesis(0,n);

    return g_pars;
}

int main() {
}
