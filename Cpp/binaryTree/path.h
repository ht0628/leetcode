#pragma once
#ifndef _PATH_H
#define _PATH_H
#include "common.h"

class Path
{
    public:
        /* 112.路径总和 */
        bool hasPathSum(TreeNode* root, int targetSum);
        /* 113.路径总和II */
        vector<vector<int>> pathSum(TreeNode* root, int targetSum);
        /* 437.路径总和 III */
        int pathSumIII(TreeNode* root, int targetSum);
        /* 129. 求根节点到叶节点数字之和 */
        int sumNumbers(TreeNode* root);
        /* 124.二叉树中的最大路径和 */
        int maxPathSum(TreeNode* root);

        /* 257. 二叉树的所有路径 */
        vector<string> binaryTreePaths(TreeNode* root);

};



#endif