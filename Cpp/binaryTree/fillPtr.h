#pragma once
#ifndef _FILL_PTR_H
#define _FILL_PTR_H
#include "common.h"
struct Node {
    int val;
    Node *left;
    Node *right;
    Node *next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
class FillPtr
{
    public:
        /* 116. 填充每个节点的下一个右侧节点指针 */
        Node* connect(Node* root);
        /* 117. 填充每个节点的下一个右侧节点 */
        Node* connectII(Node* root);
};


#endif