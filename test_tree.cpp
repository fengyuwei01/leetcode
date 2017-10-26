/*************************************************************************** 
 * *   @file:      main.cpp 
 * *   @author:    ugly_chen 
 * *   @date:      2015.1.3 
 * *   @remark:    this code is for binary tree with array 
 * *   @note 
 * ****************************************************************************/  
  
#include<iostream>  

using namespace std;  


struct binary_tree_node  
{  
    int data;  
    binary_tree_node* left_child;  
    binary_tree_node* right_child;  
};  

void create_tree(binary_tree_node* &tree, int a[], int len, int index)  
{  
    if (index >= len)  
        return;  
    tree = new binary_tree_node;  
    tree->data = a[index];  
    tree->left_child = NULL;  
    tree->right_child = NULL;  
    create_tree(tree->left_child, a, len, 2 * index + 1);  
    create_tree(tree->right_child, a, len, 2 * index + 2);  
}  

void Print(binary_tree_node* p)  
{  
    if (NULL == p)  
        return;  
    cout << p->data << endl;  
    Print(p->left_child);  
    Print(p->right_child);  
}  

int main()  
{  
    int p[7] = { 0, 1, 2, 3, 4, 5, 6 };  
    binary_tree_node*tree;  
    create_tree(tree, p, 7, 0);  
    Print(tree);  
    return 0;  
}  
