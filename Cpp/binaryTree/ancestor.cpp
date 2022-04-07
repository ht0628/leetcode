#include "ancestor.h"

TreeNode* Ancestor::lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
    if(root == nullptr){
        return root;
    }
    if(p->val > root->val && q->val > root->val){
        return lowestCommonAncestor(root->right, p, q);
    }
    if(p->val < root->val && q->val < root->val){
        return lowestCommonAncestor(root->left, p, q);
    }
    return root;
}

TreeNode* Ancestor::lowestCommonAncestorII(TreeNode* root, TreeNode* p, TreeNode* q){
    if(root == nullptr || root == p || root == q){
        return root;
    }

    TreeNode* left = lowestCommonAncestorII(root->left, p, q);
    TreeNode* right = lowestCommonAncestorII(root->right, p, q);
    if(left == nullptr) return right;
    if(right == nullptr) return left;
    return root; 

}