/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    vector<vector<int>> paths;
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        paths.clear();
        vector<int> path;
        if (NULL == root) {
            return paths;
        }    
        
        path_sum(root,sum,path);

        return paths;
    }

    void path_sum(TreeNode* root, int sum, vector<int> &path) {
        if (root->left == NULL && root->right == NULL) {
            if (sum == root->val) {
                // 符合要求
                path.push_back(root->val);
                paths.push_back(path);
                path.pop_back();
            }
        } else {
            if (root->left) {
                path.push_back(root->val);
                path_sum(root->left,sum - root->val,path);
                path.pop_back();
            }

            if (root->right) {
                path.push_back(root->val);
                path_sum(root->right,sum - root->val,path);
                path.pop_back();
            }
        }
    }
};
