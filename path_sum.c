// https://leetcode.com/problems/path-sum/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool is_path_sum(struct TreeNode* root, int sum) {
    if (root->left == NULL && root->right == NULL) {
        return sum == root->val;
    } else {
        bool bol = false;
        if (root->left) {
            bol = bol || is_path_sum(root->left,sum - root->val);
        }
        if (root->right) {
            bol = bol || is_path_sum(root->right,sum - root->val);
        }
        
        return bol;
    }
}

bool hasPathSum(struct TreeNode* root, int sum) {
    if (root == NULL) {
        return false;
    }
    return is_path_sum(root,sum);
}
