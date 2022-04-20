#pragma once
#ifndef _TRAVERSE_H
#define _TRAVERSE_H
#include "common.h"

class Traverse 
{
    public:
        /* 144. 二叉树的前序遍历 */
        vector<int> preorderTraversal(TreeNode* root);
        vector<int> preorderTraversal_iter(TreeNode* root);
        vector<int> preorderTraversal_template(TreeNode* root);
        /* 94. 二叉树的中序遍历 */
        vector<int> inorderTraversal(TreeNode* root);
        vector<int> inorderTraversal_iter(TreeNode* root);
        vector<int> inorderTraversal_template(TreeNode* root);
        /* 145. 二叉树的后序遍历 */
        vector<int> postorderTraversal(TreeNode* root);
        vector<int> postorderTraversal_iter(TreeNode* root);
        vector<int> postorderTraversal_template(TreeNode* root);
        /* 102. 二叉树的层序遍历 */
        vector<vector<int>> levelOrder(TreeNode* root);
        /* 107.二叉树的层序遍历 II */
        vector<vector<int>> levelOrderBottom(TreeNode* root);
        /* 103. 二叉树的锯齿形层序遍历 */
        vector<vector<int>> zigzagLevelOrder(TreeNode* root);
        vector<vector<int>> zigzagLevelOrder2(TreeNode* root);


        /* 105. 从前序与中序遍历序列构造二叉树 */
        TreeNode* constructFromPreIn(vector<int>& preorder, vector<int>& inorder);
        /* 889. 根据前序和后序遍历构造二叉树 */
        TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder);
        /* 106. 从中序与后序遍历序列构造二叉树 */
        TreeNode* constructFromInPost(vector<int>& inorder, vector<int>& postorder);


        /* 297. 二叉树的序列化与反序列化*/
        string serialize(TreeNode* root);
        string serialize_layer(TreeNode* root);
        TreeNode* deserialize(string data);
        TreeNode* deserialize_layer(string data);
        /* 331. 验证二叉树的前序序列化 */
        bool isValidSerialization(string preorder);
        /* 449. 序列化和反序列化二叉搜索树 */
        string serializeII(TreeNode* root);
        TreeNode* deserializeII(string data);
        
};

#endif