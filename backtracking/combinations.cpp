// https://leetcode.com/problems/combinations/description/

#include<vector>

using std::vector;

vector<vector<int>> g_combines;
vector<int> g_combine;

void _combine(int n,int k,int current) {
    if (g_combine.size() >= k) {
        g_combines.push_back(g_combine);
        return;
    } else {
        int i;
        for (i = current+1;i<=n;i++) {
            g_combine.push_back(i);
            _combine(n,k,i);
            g_combine.pop_back();
        }
    }
}

vector<vector<int>> combine(int n, int k) {
   g_combines.clear();
   g_combine.clear();

   _combine(n,k,0);

   return g_combines;
}

int main() {
}
