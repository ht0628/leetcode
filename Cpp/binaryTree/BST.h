#pragma once
#ifndef _BST_H
#define _BST_H
#include "common.h"

class BST
{
    public:
        /* 98.验证二叉搜索树 */
        /* 中序遍历+vector */
        bool isValidBST_inorderVec(TreeNode* root);
        /* 中序遍历 */
        bool isValidBST_inorder(TreeNode* root, TreeNode* pre = nullptr);
        /* 迭代遍历 */
        bool isValidBST_iter(TreeNode* root);
        /* 99.恢复二叉搜索树 */
        void recoverTree(TreeNode* root);
        /* 230.二叉搜索树中第K小的元素 */ 
        int kthSmallest(TreeNode* root, int k);

        /* 96.不同的二叉搜索树*/
        int numTrees(int n);
        /* 95.不同的二叉搜索树II */
        vector<TreeNode*> generateTrees(int n);
        /* 108.将有序数组转换为二叉搜索树 */
        TreeNode* sortedArrayToBST(vector<int>& nums);
        /* 109.将有序链表转换为二叉搜索树 */
        TreeNode* sortedListToBST(ListNode* head);

        /* 114.二叉树展开为链表 */
        void flatten(TreeNode* root);
        /* 剑指 Offer 36. 二叉搜索树与双向链表 */
        TreeNode* treeToDoublyList(TreeNode* root);
};

/* 173.二叉搜索树迭代器 */
class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        while (root != nullptr){
            st.push(root);
            root = root->left;
        }   
    }
    
    int next() {
        TreeNode* root = st.top();
        st.pop();
        TreeNode* node = root->right;
        while(node != nullptr){
            st.push(node);
            node = node->left;
        }

        return root->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};
class BSTIterator1 {
public:
    stack<TreeNode*> st;
    TreeNode* cur;
    BSTIterator1(TreeNode* root): cur(root){};

    int next() {
        while (cur != nullptr){
            st.push(cur);
            cur = cur->left;
        }
        cur = st.top();
        st.pop();
        int val = cur->val;
        cur = cur->right;
        return val;
    }
    
    bool hasNext() {
        return !st.empty() || cur != nullptr;
    }
};
#endif