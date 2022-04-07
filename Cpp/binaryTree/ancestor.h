#pragma once
#ifndef _ANCESTOR_H
#define _ANCESTOR_H
#include "common.h"

class Ancestor
{
    public:
        /* 235.二叉搜索树的最近公共祖先 */
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);
        /* 236.二叉树的最近公共祖先 */
        TreeNode* lowestCommonAncestorII(TreeNode* root, TreeNode* p, TreeNode* q);

};

#endif