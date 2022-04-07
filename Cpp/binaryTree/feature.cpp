#include "feature.h"

bool _isSymmetric(TreeNode* left, TreeNode* right){
    if(left == nullptr && right != nullptr) 
        return false;
    else if(left != nullptr && right == nullptr) 
        return false;
    else if(left == nullptr && right == nullptr){
        return true;
    }
    else if(left->val != right->val){
        return false;
    }
    else{
        bool outside = _isSymmetric(left->left, right->right);
        bool inside = _isSymmetric(left->right, right->left);
        return outside && inside;
    }
}
bool Feature::isSymmetric(TreeNode* root){
    if(root == nullptr) return true;
    return _isSymmetric(root->left, root->right);
}
bool Feature::isSymmetric_iter(TreeNode* root){
    if(root == nullptr) 
        return true;
    queue<TreeNode*> q;
    q.push(root->left);
    q.push(root->right);
    while(!q.empty()){
        TreeNode* node1 = q.front();
        q.pop();
        TreeNode* node2 = q.front();
        q.pop();
        if(node1 == nullptr && node2 == nullptr)
            continue;
        else if(node1 == nullptr || node2 == nullptr)
            return false;
        else if(node1->val != node2->val)
            return false;
        else{
            q.push(node1->left);
            q.push(node2->right);
            q.push(node1->right);
            q.push(node2->left);
        }
    }
    return true;
}

int Feature::maxDepth_recur(TreeNode* root){
    if(root == nullptr)
        return 0;
    int left = maxDepth_recur(root->left);
    int right = maxDepth_recur(root->right);
    int depth = max(left,right) + 1;
    return depth;
}
int Feature::maxDepth_bfs(TreeNode* root){
    if(root == nullptr) 
        return 0;
    int depth = 0;
    deque<TreeNode*> q;
    q.push_back(root);
    while (!q.empty()){
        depth++;
        int n = q.size();
        for(int i = 0; i < n; i++){
            TreeNode* node = q.front();
            q.pop_front();
            if(node->left != nullptr)
                q.push_back(node->left);
            if(node->right != nullptr)
                q.push_back(node->right);
        }
    }
    return depth;
}

int Feature::minDepth_bfs(TreeNode* root){
    if(root == nullptr)
        return 0;
    deque<TreeNode*> q;
    q.push_back(root);
    int minDepth = 0;
    while (!q.empty()){
        minDepth++;
        int n = q.size();
        for(int i = 0; i < n; i++){
            TreeNode* node = q.front();
            q.pop_front();
            if(node->left == nullptr && node->right == nullptr)
                return minDepth;
            if(node->left != nullptr)
                q.push_back(node->left);
            if(node->right != nullptr)
                q.push_back(node->right);
        }
    }
    return minDepth;
}
int Feature::minDepth_recur1(TreeNode* root){
    if(root == nullptr)
        return 0;
    if(root->left == nullptr && root->right == nullptr)
        return 1;
    else if(root->left == nullptr)
        return minDepth_recur1(root->right) + 1;
    else if(root->right == nullptr)
        return minDepth_recur1(root->left) + 1;
    else
        return min(minDepth_recur1(root->left), minDepth_recur1(root->right)) + 1;
}
int Feature::minDepth_recur2(TreeNode* root){
    if(root == nullptr)
        return 0;
    int left = minDepth_recur2(root->left);
    int right = minDepth_recur2(root->right);
    return (left && right) ? min(left,right) + 1 : 1 + left + right;
}

TreeNode* Feature::mergeTrees(TreeNode* root1, TreeNode* root2){
    if(root1 == nullptr)
        return root2;
    if(root2 == nullptr)
        return root1;
    TreeNode* root = new TreeNode(root1->val + root2->val);
    root->left = mergeTrees(root1->left, root2->left);
    root->right = mergeTrees(root1->right, root2->right);
    return root;
}

TreeNode* Feature::mirrorTree(TreeNode* root){
    if(root == nullptr){
        return nullptr;
    }
    TreeNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    mirrorTree(root->left);
    mirrorTree(root->right);
    return root;
}

bool Feature::isSameTree(struct TreeNode* p, struct TreeNode* q){
    if(p == nullptr && q == nullptr){
        return true;
    }
    if(p == nullptr || q == nullptr){
        return false;
    }
    if(p->val != q->val){
        return false;
    }

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int height(TreeNode* root){
    if(root == nullptr){
        return 0;
    }
    int left = height(root->left);
    if(left == -1){
        return -1;
    }
    int right = height(root->right);
    if(right == -1){
        return -1;
    }
    int diff = abs(left - right);
    if(diff > 1){
        return -1;
    }

    return max(left,right) + 1;

}
bool Feature::isBalanced(TreeNode* root){
    bool ret = (height(root) == -1) ? false : true;
    return ret;
}

vector<int> Feature::rightSideView(TreeNode* root){
    deque<TreeNode*> q;
    vector<int> res;
    if(root != nullptr){
        q.push_back(root);       
    }
    while(!q.empty()){
        int n = q.size();
        for(int i = 0; i < n; i++){
            TreeNode* node = q.front();
            q.pop_front();
            if(i == n - 1){
                res.push_back(node->val);
            }
            if(node->left != nullptr){
                q.push_back(node->left);
            }
            if(node->right != nullptr){
                q.push_back(node->right);
            }
        }
    }
    return res;
}
void rightSideView2_dfs(TreeNode* root, vector<int>& vec, int depth){
    if(root == nullptr){
        return;
    }
    if(depth == vec.size()){
        vec.push_back(root->val);
    }
    rightSideView2_dfs(root->right, vec, depth + 1);
    rightSideView2_dfs(root->left, vec, depth + 1);
}
vector<int> Feature::rightSideView2(TreeNode* root){
    vector<int> res;
    rightSideView2_dfs(root, res, 0);
    return res;
}

void _findBottomLeftValue(TreeNode* root, int depth, int& maxdepth, int& res){
    if(root == nullptr){
        return;
    }
    if(depth > maxdepth){
        maxdepth = depth;
        res = root->val;
    }
    _findBottomLeftValue(root->left, depth + 1, maxdepth, res);
    _findBottomLeftValue(root->right, depth + 1, maxdepth, res);
}
int Feature::findBottomLeftValue(TreeNode* root){
    int res = 0;
    int maxdepth = -1;
    _findBottomLeftValue(root, 1, maxdepth, res);
    return res;
}

void _sumOfLeftLeaves(TreeNode* root, int& res){
    if(root == nullptr){
        return;
    }
    if(root->left && root->left->left == nullptr && root->left->right == nullptr){
        res += root->left->val;
    }
    _sumOfLeftLeaves(root->left, res);
    _sumOfLeftLeaves(root->right, res);
}
int Feature::sumOfLeftLeaves(TreeNode* root) {
    int res = 0;
    _sumOfLeftLeaves(root, res);
    return res;
}

int _countHeight(TreeNode* root){
    int height = 0;
    while(root != nullptr){
        height++;
        root = root->left;
    }
    return height;
}
int Feature::countNodes(TreeNode* root){
    if(root == nullptr){
        return 0;
    }
    int left = _countHeight(root->left);
    int right = _countHeight(root->right);
    if(left == right){
        return countNodes(root->right) + (1 << left);
    }
    else{
        return countNodes(root->left) + (1 << right);
    }
    
}