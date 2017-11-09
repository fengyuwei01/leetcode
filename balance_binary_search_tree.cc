// 平衡二叉搜索树
#include <algorithm>
#include "stdlib.h"
using namespace std;

typedef struct binary_tree {
    int data;
    binary_tree *left;
    binary_tree *right;
} tree;

int _is_balance_bst(tree *root,int *d /*深度*/) ;

int is_balance_bst(tree *root) {
    int d;
    return _is_balance_bst(root,&d);
}

int _is_balance_bst(tree *root,int *d /*深度*/) {
    if (root->left == NULL && root->right == NULL) {
        *d = 1;
        return 1;
    } else {
        int left_len = 0,right_len = 0;
        int left_bol = 1,right_bol = 1;
        if (NULL != root->left) {
            left_bol = _is_balance_bst(root->left,&left_len);
        }
        if (NULL != root->right) {
            right_bol = _is_balance_bst(root->right,&right_len);
        }

        // 获取最大值
        *d = max(left_len,right_len) + 1;
        return left_bol && right_bol && abs(left_len-right_len) <= 1;
    }
}
/* vim: set ts=4 sw=4 tw=0 et :*/
