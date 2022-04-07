#pragma once
#ifndef _FEATURE_H
#define _FEATURE_H
#include "common.h"

class Feature
{
    public:
        /* 100.相同的树 */
        bool isSameTree(struct TreeNode* p, struct TreeNode* q);
        /* 617.合并二叉树 */
        TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2);

        /* 226.反转二叉树 */
        TreeNode* mirrorTree(TreeNode* root);
        /* 101.对称二叉树 */
        /* 解法一 递归法 */
        bool isSymmetric(TreeNode* root);
        /* 解法二 迭代法 */
        bool isSymmetric_iter(TreeNode* root);

        /* 104.二叉树的最大深度 */
        /* 解法一 递归法*/
        int maxDepth_recur(TreeNode* root);
        /* 解法二 BFS */
        int maxDepth_bfs(TreeNode* root);
        /* 111.二叉树的最小深度 */
        /* 解法一 BFS */
        int minDepth_bfs(TreeNode* root);
        /* 解法二 递归法 */
        int minDepth_recur1(TreeNode* root);
        int minDepth_recur2(TreeNode* root);
        /* 110.平衡二叉树 */
        bool isBalanced(TreeNode* root);


        /* 199.二叉树的右视图 */
        /* 解法一 bfs */
        vector<int> rightSideView(TreeNode* root);
        /* 解法二 dfs */
        vector<int> rightSideView2(TreeNode* root);
        /* 513.找树左下角的值 */
        int findBottomLeftValue(TreeNode* root);
        
        /* 404.左叶子之和 */
        int sumOfLeftLeaves(TreeNode* root);

        /* 222. 完全二叉树的节点个数 */
        int countNodes(TreeNode* root);

};

#endif