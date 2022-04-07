#include "BST.h"

void inorderTraverse(TreeNode* root, vector<int>& vec){
    if(root == nullptr) return;
    inorderTraverse(root->left, vec);
    vec.push_back(root->val);
    inorderTraverse(root->right, vec);
}
bool BST::isValidBST_inorderVec(TreeNode* root){
    vector<int> vec;
    inorderTraverse(root, vec);
    for(int i = 0; i < vec.size() - 1; i++){
        if(vec[i] >= vec[i+1]){
            return false;
        }
    }
    return true;
}
bool BST::isValidBST_inorder(TreeNode* root, TreeNode* pre){
    if(root == nullptr){
        return true;
    }
    bool left = isValidBST_inorder(root->left, pre);
    if(pre != nullptr && pre->val >= root->val){
        return false;
    }
    pre = root;
    bool right = isValidBST_inorder(root->right, pre);
    return (left && right);
}
bool BST::isValidBST_iter(TreeNode* root){
    if(root == nullptr){
        return true;
    }
    stack<TreeNode*> st;
    TreeNode* cur = root;
    TreeNode* pre = nullptr;

    while(cur != nullptr || !st.empty()){
        if(cur != nullptr){
            st.push(cur);
            cur = cur->left;
        }
        else{
            cur = st.top();
            st.pop();
            if(pre != nullptr && cur->val <= pre->val){
                return false;
            }
            pre = cur;
            cur = cur->right;
        }
    }
    return true;
}

int BST::numTrees(int n){
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i < n+1; i++){
        for(int j = 0; j < i; j++){
            dp[i] += dp[j] * dp[i-j-1];
        }
    }
    return dp[n];
}
vector<TreeNode*> _generateTress(int start, int end){
    vector<TreeNode*> vec;
    if(start > end){
        vec.push_back(nullptr);
        return vec;
    }
    
    for(int mid = start; mid < end + 1; mid++){
        vector<TreeNode*> leftTrees = _generateTress(start, mid - 1);
        vector<TreeNode*> rightTrees = _generateTress(mid + 1, end);
        for(TreeNode* leftTree:leftTrees){
            for(TreeNode* rightTree:rightTrees){
                TreeNode* root = new TreeNode(mid);
                root->left = leftTree;
                root->right = rightTree;
                vec.push_back(root);
            }
        }
    }

    return vec;
}
vector<TreeNode*> BST::generateTrees(int n){
    if(n < 1){
        return {nullptr};
    }
    vector<TreeNode*> roots = _generateTress(1, n);
    return roots;
}

void inorderFind(TreeNode* root, TreeNode*& node1, TreeNode*& node2, TreeNode*& pre){
    if(root == nullptr){
        return; 
    }
    inorderFind(root->left, node1, node2, pre); 
    if(pre != nullptr && root->val < pre->val){
        if(node1 == nullptr){
            node1 = pre;
        }
        node2 = root;
    }
    pre = root;
    inorderFind(root->right, node1, node2, pre);
}
void BST::recoverTree(TreeNode* root){
    TreeNode *x = nullptr, *y = nullptr, *pre = nullptr;
    inorderFind(root, x, y, pre);
    swap(x->val, y->val);
}

TreeNode* _sortedArrayToBST(vector<int>& nums, int left, int right){
    if(left > right){
        return nullptr ;
    }
    int mid = (left + right) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = _sortedArrayToBST(nums, left, mid - 1);
    root->right = _sortedArrayToBST(nums, mid + 1, right);
    return root;

}
TreeNode* BST::sortedArrayToBST(vector<int>& nums){
    TreeNode* root = _sortedArrayToBST(nums, 0, nums.size() - 1);
    return root;
}

ListNode* findMid(ListNode* head){
    ListNode* fast = head;
    ListNode* slow = head;
    while(fast != nullptr && fast->next != nullptr){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
TreeNode* BST::sortedListToBST(ListNode* head){
    if(head == nullptr){
        return nullptr;
    }
    else if(head->next == nullptr){
        return new TreeNode(head->val);
    }
    ListNode* mid = findMid(head);
    ListNode* right = mid->next;
    TreeNode* root = new TreeNode(mid->val);
    ListNode* prev = head;
    while(prev->next != mid){
        prev = prev->next;
    }
    prev->next = nullptr;
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(right);
    return root; 
}

void _flatten(TreeNode* root, TreeNode*& last){
    if(root == nullptr){
        return;
    }
    _flatten(root->right, last);
    _flatten(root->left, last);
    root->left = nullptr;
    root->right = last;
    last = root;
}
void BST::flatten(TreeNode* root){
    TreeNode* last = nullptr;
    _flatten(root, last);
}

void _treeToDoublyList(TreeNode* root, TreeNode*& head, TreeNode*& pre, TreeNode*& cur){
    if(root == nullptr){
        return;
    }
    _treeToDoublyList(root->left, head, pre, cur);
    cur = root;
    if(pre ==  nullptr){
        head = cur;
    }
    else{
        pre->right = cur;
        cur->left = pre;
    }
    pre = cur;
    _treeToDoublyList(root->right, head, pre, cur);
}
TreeNode* BST::treeToDoublyList(TreeNode* root){
    TreeNode* head = nullptr;
    TreeNode* pre = nullptr;
    TreeNode* cur = nullptr;
    _treeToDoublyList(root, head, pre, cur);
    head->left = cur;
    cur->right = head;
    return head;
}

int BST::kthSmallest(TreeNode* root, int k){
    stack<TreeNode*> st;
    TreeNode* node = root;
    while(node != nullptr || !st.empty()){
        if(node != nullptr){
            st.push(node);
            node = node->left;
        }
        else{
            node = st.top();
            st.pop();
            if(--k == 0){
                return node->val;
            }
            node = node->right;
        }
    }
    return 0;
}

