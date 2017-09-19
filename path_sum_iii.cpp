// https://leetcode.com/problems/path-sum-iii/discuss/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void path_sum(struct TreeNode* root,int sum,int *count) {
    if (root == NULL) {
        return;
    }
    
    if (sum == 0) {
        (*count) ++;
    }
    
    path_sum(root->left,sum - root->val,count);
    path_sum(root->left,sum,count);
    path_sum(root->right,sum - root->val,count);
    path_sum(root->right,sum,count);
}

int pathSum(struct TreeNode* root, int sum) {
    int count = 0;
    if (root == NULL) {
        return 0;
    }
    
    path_sum(root,sum,&count);
    
    return count;
}





