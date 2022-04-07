#include "path.h"


bool Path::hasPathSum(TreeNode* root, int targetSum){
    if(root == nullptr){
        return false;
    }
    if(root->left == nullptr && root->right == nullptr){
        if(root->val == targetSum){
            return true;
        }
        else{
            return false;
        }
    }
    bool left = hasPathSum(root->left, targetSum - root->val);
    bool right = hasPathSum(root->right, targetSum - root->val);
    return left || right;
}

void _pathSum(TreeNode* root, int targetSum, vector<int>& path, vector<vector<int>>& vec){
    if(root == nullptr){
        return;
    }
    path.push_back(root->val);
    if(root->left == nullptr && root->right == nullptr){
        if(root->val == targetSum){
            vec.push_back(path);
        }
    }
    _pathSum(root->left, targetSum - root->val, path, vec);
    _pathSum(root->right, targetSum - root->val, path, vec);
    path.pop_back();

}
vector<vector<int>> Path::pathSum(TreeNode* root, int targetSum){
    vector<int> tmp;
    vector<vector<int>> res;
    _pathSum(root, targetSum, tmp, res);
    return res;
}

void _pathSumIII(TreeNode* root, int targetSum, long long prefixSum, unordered_map<int,int>& map, int& res) {
    if(root == nullptr){
        return;
    }
    prefixSum += root->val;
    res += map[prefixSum - targetSum];
    map[prefixSum]++;
    _pathSumIII(root->left, targetSum, prefixSum, map, res);
    _pathSumIII(root->right, targetSum, prefixSum, map, res);
    map[prefixSum]--;
    
}
int pathSumIII(TreeNode* root, int targetSum){
    int res = 0;
    unordered_map<int, int> map;
    map[0] = 1;
    _pathSumIII(root, targetSum, 0, map, res);
    return res;
}

int _maxPathSum(TreeNode* root, int& res){
    if(root == nullptr){
        return 0;
    }
    int left = max(0, _maxPathSum(root->left, res));
    int right = max(0, _maxPathSum(root->right, res));
    res = max(res, root->val + left + right);
    return max(left, right) + root->val;
}
int Path::maxPathSum(TreeNode* root){
    int res = INT_MIN;
    int tmp = _maxPathSum(root, res);
    return res;
}

void _sumNumbers(TreeNode* root, int sum, int& res){
    if(root == nullptr){
        return;
    }
    int tmp = 10 * sum + root->val;
    if(root->left == nullptr && root->right == nullptr){
        res += tmp;
    }
    _sumNumbers(root->left, tmp, res);
    _sumNumbers(root->right, tmp, res);
}
int Path::sumNumbers(TreeNode* root){
    int res = 0;
    _sumNumbers(root, 0, res);
    return res;    
}

void _binaryTreePaths(TreeNode* root, string path, vector<string>& res){
    if(root == nullptr){
        return;
    }
    path += to_string(root->val);
    if(root->left == nullptr && root->right == nullptr){
        res.push_back(path);
        return;
    }
    _binaryTreePaths(root->left, path + "->", res);
    _binaryTreePaths(root->right, path + "->", res);

}
vector<string> Path::binaryTreePaths(TreeNode* root){
    string path = "";
    vector<string> res;
    _binaryTreePaths(root, path, res);
    return res;
}