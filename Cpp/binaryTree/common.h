#pragma once
#ifndef _COMMON_H
#define _COMMON_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int n): val(n), next(nullptr) {};
    ListNode(int n, ListNode* next) :val(n), next(next) {}; 
};

class Tree 
{
    public:
        /* 创建树 */
        TreeNode* buildTree(vector<string> &vec);
        /* 打印树 */
        void printTree(TreeNode* root);
};
class List
{
    public:
        /* 创建链表 */
        ListNode* buildList(vector<int> &vec);
        /* 打印链表 */
        void printList(ListNode* list);
};

template<typename Contrainer>
void printContrainer(const Contrainer& c)
{
    if (c.empty()){
        return;
    }
    else{
        cout << '[';
        for(auto i = c.begin(); i != c.end(); i++){
            if(i != c.end() - 1){
                cout << *i << ' ';
            }
            else{
                cout << *i;
            }
        }
        cout << ']' << endl;
        // typename Contrainer::const_iterator itr = c.begin();
        // cout << " [ " << *itr++;
        // while (itr != c.end()){
        //     cout << ", " << *itr++;
        // }
        // cout << " ]" << endl;
    } 
}


#endif