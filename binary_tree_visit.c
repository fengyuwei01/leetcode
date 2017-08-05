// 二叉树搜索
#include<stdio.h>
#include<stdlib.h>

// Definition for a binary tree node.

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode* tree_node_t;
void create_tree_node(tree_node_t node,int *nums,int len,int idx);

// 创建二叉树
tree_node_t create_tree(int *nums,int size) {
    tree_node_t root;
    
    // 递归创建根节点
    create_tree_node(root,nums,size,0);
    if (root == NULL) {
        printf("fail to create root.");
    }

    return root;
}

void create_tree_node(tree_node_t node,int *nums,int len,int idx) {
    if (idx >= len) {
        return;
    }
    if (nums[idx] != -1) {
        node = malloc(sizeof(*node));
        node->val = nums[idx];
        node->right = NULL;
        node->left = NULL;

        printf("node:%d\n",node->val);

        // 创建左节点
        create_tree_node(node->left,nums,len,2*idx+1);
        // 创建右节点
        create_tree_node(node->right,nums,len,2*idx+2);
    }
}

// 打印二叉树
void print_tree(tree_node_t root) {
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
    free_tree(root);
}
