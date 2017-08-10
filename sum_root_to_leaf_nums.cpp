// https://leetcode.com/problems/sum-root-to-leaf-numbers/description/


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        int sumNumbers(TreeNode* root) {
            return sum_dfs(root,0);
        }

        // 递归解法
        int sum_dfs(TreeNode* root,int sum) {
            if (NULL == root) {
                return 0;
            }
            if (root->left == NULL && root->right == NULL) {
                return sum*10 + root->val;
            } else {
                return sum_dfs(root->left,sum*10+root->val)
                    +sum_dfs(root->right,sum*10+root->val);
            }
        }

        // 非递归解法(将递归解法改成人工栈实现)
        int sum_no_recursion(TreeNode* root) {
            stack<TreeNode *> stack;
            TreeNode *node;

            stack.push(root);
            while(!stack.empty()) {
                node = stack.top();
                stack.pop();

                visit(node);

                if (node->right) {
                    stack.push(node->right);
                }

                if (node->left) {
                    stack.push(node->left);
                }
            }
        }
};
