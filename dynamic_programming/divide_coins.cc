/**
 * 现在有一袋硬币，里面最多有100个硬币，面值区间为[1, 500]，
 * 要分给两个人，并使得他们所获得的金钱总额之差最小，并给出
 * 这个最小差值。
 *
 */

#include <iostream>
#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

// 最小差值
int g_min_diff = -1;

// side 表示其中一个人的选择结果
void _solve_by_brute_force(vector<int> &icons,int level,int side,int sum) {
    if (level >= icons.size()) {
        int diff = sum - side;
        if (diff > side) {
            diff = diff - side;
        } else {
            diff = side - diff;
        }

        if (g_min_diff > diff) {
            g_min_diff = diff;
        }

        return;
    } else {
        _solve_by_brute_force(icons,level+1,side+icons[level],sum);
        _solve_by_brute_force(icons,level+1,side,sum);
    }
}

int solve_by_brute_force(vector<int> &icons) {
    int sum = 0;
    for (int i=0;i<icons.size();i++) {
        sum += icons[i];
    }
    g_min_diff = sum;

    _solve_by_brute_force(icons,0,0,sum);

    return g_min_diff;
}

int main(int argc,char **argv) {
    vector<int> icons;
    icons.push_back(2);
    icons.push_back(3);
    icons.push_back(5);

    int result = solve_by_brute_force(icons);

    cout << "result:" << result << endl;
}

