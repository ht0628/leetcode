#include "traverse.h"

void _preorderTraversal(TreeNode* root, vector<int>& vec){
    if(root == NULL) return;
    vec.push_back(root->val);
    _preorderTraversal(root->left, vec);
    _preorderTraversal(root->right, vec);
}
vector<int> Traverse::preorderTraversal(TreeNode* root){
    vector<int> record;
    _preorderTraversal(root, record);
    return record;
}
vector<int> Traverse::preorderTraversal_iter(TreeNode* root){
    vector<int> vec;
    stack<TreeNode*> stk;
    if(root == nullptr) return vec;
    stk.push(root);

    while(!stk.empty()){
        TreeNode* node = stk.top();
        stk.pop();
        vec.push_back(node->val);
        if(node->right){
            stk.push(node->right);
        }
        if(node->left){
            stk.push(node->left);
        }
    }

    return vec;
}
vector<int> Traverse::preorderTraversal_template(TreeNode* root){
    vector<int> vec;
    stack<TreeNode*> st;
    if(root != nullptr) st.push(root);
    while(!st.empty()){
        TreeNode* node = st.top();
        if(node != nullptr){
            st.pop();
            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);
            st.push(node);
            st.push(nullptr);
        }
        else{
            st.pop();
            TreeNode* node = st.top();
            st.pop();
            vec.push_back(node->val);
        }
    }
    return vec;
}

void _inorderTraversal(TreeNode* root, vector<int>& vec){
    if(root == NULL) return;
    _inorderTraversal(root->left, vec);
    vec.push_back(root->val);
    _inorderTraversal(root->right, vec);
}
vector<int> Traverse::inorderTraversal(TreeNode* root){
    vector<int> record;
    _inorderTraversal(root, record);
    return record;
}
vector<int> Traverse::inorderTraversal_iter(TreeNode* root){
    vector<int> vec;
    stack<TreeNode*> stk;
    TreeNode* cur = root;

    while(cur != nullptr || !stk.empty()){
        if(cur != nullptr){
            stk.push(cur);
            cur = cur->left;
        }
        else{
            cur = stk.top();
            stk.pop();
            vec.push_back(cur->val);
            cur = cur->right;
        }
    }

    return vec;
}
vector<int> Traverse::inorderTraversal_template(TreeNode* root){
    vector<int> vec;
    stack<TreeNode*> st;
    if(root != nullptr) st.push(root);
    while(!st.empty()){
        TreeNode* node = st.top();
        if(node != nullptr){
            st.pop();
            if(node->right) st.push(node->right);
            st.push(node);
            st.push(nullptr);
            if(node->left) st.push(node->left);
        }
        else{
            st.pop();
            TreeNode* node = st.top();
            st.pop();
            vec.push_back(node->val);
        }
    }
    return vec;
}

void _postorderTraversal(TreeNode* root, vector<int>& vec){
    if(root == NULL) return;
    _postorderTraversal(root->left, vec);
    _postorderTraversal(root->right, vec);
    vec.push_back(root->val);
}
vector<int> Traverse::postorderTraversal(TreeNode* root){
    vector<int> record;
    _postorderTraversal(root, record);
    return record;
}
vector<int> Traverse::postorderTraversal_iter(TreeNode* root){
    vector<int> vec;
    stack<TreeNode*> stk;
    if(root == nullptr) return vec;
    stk.push(root);
    while (!stk.empty()){
        TreeNode* node = stk.top();
        stk.pop();
        vec.push_back(node->val);
        if(node->left) stk.push(node->left);
        if(node->right) stk.push(node->right);
    }
    reverse(vec.begin(),vec.end());
    return vec;
}
vector<int> Traverse::postorderTraversal_template(TreeNode* root){
    vector<int> vec;
    stack<TreeNode*> st;
    if(root != nullptr) st.push(root);
    while(!st.empty()){
        TreeNode* node = st.top();
        if(node != nullptr){
            st.pop();
            st.push(node);
            st.push(nullptr);
            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);
        }
        else{
            st.pop();
            TreeNode* node = st.top();
            st.pop();
            vec.push_back(node->val);
        }
    }
    return vec;
}

vector<vector<int>> Traverse::levelOrder(TreeNode* root){
    vector<vector<int>> res;
    deque<TreeNode*> q;
    if(root != nullptr) q.push_back(root);
    while(!q.empty()){
        vector<int> temp;
        int n = q.size();
        for(int i = 0; i < n; i++){
            TreeNode* node = q.front();
            q.pop_front();
            temp.push_back(node->val);
            if(node->left) q.push_back(node->left);
            if(node->right) q.push_back(node->right);
        }
        res.push_back(temp);
    }
    return res;
}
vector<vector<int>> Traverse::levelOrderBottom(TreeNode* root){
    vector<vector<int>> res;
    deque<TreeNode*> q;
    if(root != nullptr) q.push_back(root);
    while(!q.empty()){
        vector<int> temp;
        int n = q.size();
        for(int i = 0; i < n; i++){
            TreeNode* node = q.front();
            q.pop_front();
            temp.push_back(node->val);
            if(node->left) q.push_back(node->left);
            if(node->right) q.push_back(node->right);
        }
        res.push_back(temp);
    }
    reverse(res.begin(), res.end());
    return res;

}


vector<vector<int>> Traverse::zigzagLevelOrder(TreeNode* root){
    vector<vector<int>> res;
    stack<TreeNode*> st1;
    stack<TreeNode*> st2;
    if(root != nullptr) st1.push(root);

    while(!st1.empty() || !st2.empty()){
        vector<int> tmp;
        if(!st1.empty()){
            while(!st1.empty()){
                TreeNode* node = st1.top();
                st1.pop();
                tmp.push_back(node->val);
                if(node->left) st2.push(node->left);
                if(node->right) st2.push(node->right);
            }
        }
        else{
            while(!st2.empty()){
                TreeNode* node = st2.top();
                st2.pop();
                tmp.push_back(node->val);
                if(node->right) st1.push(node->right);
                if(node->left) st1.push(node->left);
            }
        }
        res.push_back(tmp);
    }

    return res;
}
vector<vector<int>> Traverse::zigzagLevelOrder2(TreeNode* root){
    deque<TreeNode*> q;
    vector<vector<int>> res;
    bool leftOrder = true;
    if(root != nullptr){
        q.push_back(root);
    }
    while(!q.empty()){
        int n = q.size();
        vector<int> tmp;
        for(int i = 0; i < n; i++){
            if(leftOrder){
                TreeNode* node = q.front();
                q.pop_front();
                tmp.push_back(node->val);
                if(node->left){
                    q.push_back(node->left);      
                }
                if(node->right){
                    q.push_back(node->right);
                }
            }
            else{
                TreeNode* node = q.back();
                q.pop_back();
                tmp.push_back(node->val);
                if(node->right){
                    q.push_front(node->right);
                }
                if(node->left){
                    q.push_front(node->left);
                }

            }
        }
        res.push_back(tmp);
        leftOrder = !leftOrder;
    }
    return res;
}

TreeNode* Traverse::constructFromPreIn(vector<int>& preorder, vector<int>& inorder){
    if(preorder.empty()) return nullptr;

    TreeNode* node = new TreeNode(preorder[0]);
    int idx = 0;
    while(inorder[idx] != node->val){
        idx++;
    }
    vector<int> L_pre(preorder.begin() + 1, preorder.begin() + idx + 1);
    vector<int> L_in(inorder.begin(), inorder.begin() + idx);
    node->left = constructFromPreIn(L_pre, L_in);
    vector<int> R_pre(preorder.begin() + idx + 1, preorder.end());
    vector<int> R_in(inorder.begin() + idx + 1, inorder.end());
    node->right = constructFromPreIn(R_pre, R_in);
    return node;
}
TreeNode* Traverse::constructFromPrePost(vector<int>& preorder, vector<int>& postorder){
    if(preorder.empty()) return nullptr;

    TreeNode* node = new TreeNode(preorder[0]);
    if(preorder.size() == 1) return node;
    int idx = 0;
    while(postorder[idx] != preorder[1]){
        idx++;
    }

    vector<int> L_pre(preorder.begin() + 1,  preorder.begin() + idx + 2);
    vector<int> L_post(postorder.begin(), postorder.begin() + idx + 1);
    node->left = constructFromPrePost(L_pre, L_post);

    vector<int> R_pre(preorder.begin() + idx + 2,  preorder.end());
    vector<int> R_post(postorder.begin() + idx + 1, postorder.end() - 1);
    node->right = constructFromPrePost(R_pre, R_post);
    return node;
}
TreeNode* Traverse::constructFromInPost(vector<int>& inorder, vector<int>& postorder){
    int n = postorder.size();
    if(n == 0) return nullptr;

    TreeNode* root = new TreeNode(postorder[n-1]);
    int idx = 0;
    while(inorder[idx] != root->val){
        idx++;
    }
    vector<int> L_In(inorder.begin(), inorder.begin() + idx);
    vector<int> L_Post(postorder.begin(), postorder.begin() + idx);
    root->left = constructFromInPost(L_In, L_Post);
    vector<int> R_In(inorder.begin() + idx + 1, inorder.end());
    vector<int> R_Post(postorder.begin() + idx, postorder.end() - 1);
    root->right = constructFromPreIn(R_In, R_Post);
    
    return root;
}

void _serialize(TreeNode* root, string& s){
    if(root == nullptr){
        s += "null,";
        return;
    }
    s += to_string(root->val) + ",";
    _serialize(root->left, s);
    _serialize(root->right, s);
}
string Traverse::serialize(TreeNode* root) {
    string s;
    _serialize(root, s);
    return s;
}
string Traverse::serialize_layer(TreeNode* root) {
    string s;
    deque<TreeNode*> q;
    if(root != nullptr){
        q.push_back(root);
    }
    while(!q.empty()){
        TreeNode* node = q.front();
        q.pop_front();
        if(node == nullptr){
            s += "null,";
        }
        else{
            s += (to_string(node->val) + ",");
            q.push_back(node->left);
            q.push_back(node->right);
        }
    }
    return s;
}

TreeNode* _deserialize(queue<string>& q){
    string s = q.front();
    q.pop();
    if(s == "null"){
        return nullptr;
    }
    TreeNode* node = new TreeNode(stoi(s));
    node->left = _deserialize(q);
    node->right = _deserialize(q);
    return node;
}
TreeNode* Traverse::deserialize(string data) {
    string s;
    stringstream ss(data);
    queue<string> q;
    while(getline(ss, s, ',')){
        q.push(s);
    }
    TreeNode* root = _deserialize(q);
    return root;
}
TreeNode* Traverse::deserialize_layer(string data){
    string s;
    stringstream ss(data);
    queue<string> q;
    while(getline(ss, s, ',')){
        q.push(s);
    }

    string s1 = q.front();
    if(s1 == "null"){
        return nullptr;
    }
    TreeNode* root = new TreeNode(stoi(s1));
    q.pop();
    
    queue<TreeNode*> q1;
    q1.push(root);
    while(!q1.empty()){
        TreeNode* cur = q1.front();
        q1.pop();

        string tmp1 = q.front();
        q.pop();
        if(tmp1 != "null"){
            cur->left = new TreeNode(stoi(tmp1));
            q1.push(cur->left);
        }
        string tmp2 = q.front();
        q.pop();
        if(tmp2 != "null"){
            cur->right = new TreeNode(stoi(tmp2));
            q1.push(cur->right);
        }
    }
    return root;
}

bool isValidSerialization(string preorder);