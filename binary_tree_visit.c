// 二叉树搜索
#include<stdio.h>
#include<stdlib.h>

// Definition for a binary tree node.
typedef struct TreeNode* tree_node_t;

struct TreeNode {
    int val;
    tree_node_t left;
    tree_node_t right;

    int left_space,right_space,pre_space;
};

tree_node_t create_tree_node(int *nums,int len,int idx);

// 创建二叉树
tree_node_t create_tree(int *nums,int size) {
    // 递归创建根节点
    tree_node_t root = create_tree_node(nums,size,0);
    if (NULL==root) {
        printf("create tree fail");
    }
    return root;
}

tree_node_t create_tree_node(int *nums,int len,int idx) {
    if (idx >= len) {
        return NULL;
    }
    tree_node_t node = (tree_node_t)malloc(sizeof(*node));
    node->val = nums[idx];

    node->left = create_tree_node(nums,len,2*idx+1);
    node->right = create_tree_node(nums,len,2*idx+2);

    return node;
}

// 打印二叉树
void print_tree(tree_node_t root) {
}

tree_node_t calc_space(tree_node_t node) {
    if (node->left == NULL && node->right == NULL) {
        node->left_space = 0;
        node->right_space = 0;
    } else {
        if (node->right != NULL) {
            node->right->pre_space = 1;
            node->right_space = calc_space(node->right)->left_space 
                + 1 
                + calc_space(node->right)->right_space;
        }
        if (node->left != NULL) {
            node->left->pre_space = node->pre_space;
            node->left_space = calc_space(node->left)->left_space 
                +1
                +calc_space(node->left)->right_space;
        }
    }

    return node;
}

// 释放二叉树
void free_tree(tree_node_t root) {
    if (root) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}

// bfs遍历二叉树
void bfs_visit_tree(tree_node_t root) {
}

// dfs遍历二叉树
void dfs_visit_tree(tree_node_t root) {
    if (root) {
        printf("val:%d\n",root->val);
        dfs_visit_tree(root->left);
        dfs_visit_tree(root->right);
    }
}

int main() {
    int size = 8;
    int *nums = (int *)malloc(size*sizeof(int));
    int i;

    for (i=0;i<size;i++) {
        *(nums+i) = i;
    }

    tree_node_t root = create_tree(nums,size);
    dfs_visit_tree(root);

    free(nums);
    free_tree(root);
}
