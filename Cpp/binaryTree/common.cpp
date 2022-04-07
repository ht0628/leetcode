#include "common.h"

TreeNode* Tree::buildTree(vector<string>& vec)
{
    /* 检验初始传参 */
    if(vec.empty()) return nullptr;
    int index = 0;
    TreeNode* root = new TreeNode(stoi(vec[index++]));
    deque<TreeNode*> q;
    q.push_back(root);

    while(!q.empty()){
        TreeNode* node = q.front();
        q.pop_front();
        if(index < vec.size()){
            if(vec[index] != "null"){
                node->left = new TreeNode(stoi(vec[index++]));
                q.push_back(node->left);
            }
            else{
                index++;
            }
        }
        if(index < vec.size()){
            if(vec[index] != "null"){
                node->right = new TreeNode(stoi(vec[index++]));
                q.push_back(node->right);
            }
            else{
                index++;
            }
        }
    }
    return root;
}
void _printTree(TreeNode* node, bool isLeft, string const& indent)
{
    if(node == nullptr) {
        return;
    }
    _printTree(node->right, false, indent + "      ");
    cout << indent;
    cout << (isLeft ? '\\' : '/');
    cout << "-----";
    cout << node->val << endl;
    _printTree(node->left, true, indent + "      ");
}
void Tree::printTree(TreeNode* root)
{
    if (root->right)
    {
        _printTree(root->right, false, "");
    }
    cout << root->val << endl;
    if (root->left)
    {
        _printTree(root->left, true, "");
    }
    cout << endl;
}

ListNode* List::buildList(vector<int>& vec){
    ListNode* head = new ListNode(vec[0]);
    ListNode* cur = head;
    for(int i = 1; i < vec.size(); i++){
        cur->next = new ListNode(vec[i]);
        cur = cur->next;
    }
    return head;
}
void List::printList(ListNode* head){
    ListNode* cur = head;
    while(cur){
        cout << cur->val << "->";
        cur = cur->next;
    }
    cout << "null" << endl;
}

// int main()
// {
//     vector<string> vec = {"1","2","3","4","#","5","6"};
//     Tree tree;
//     TreeNode* root = tree.buildTree(vec);
//     TreeNode* root1 = tree.buildTree1(vec);
//     tree.printTree(root);
//     tree.printTree(root1);
//     return 0;
// }