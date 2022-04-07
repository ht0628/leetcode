#include "fillPtr.h"


Node* FillPtr::connect(Node* root){
    if(root == nullptr || root->left == nullptr){
        return root;
    }
    root->left->next = root->right;
    if(root->next != nullptr){
        root->right->next = root->next->left;
    }

    connect(root->left);
    connect(root->right);
    return root;
}

Node* connectII(Node* root){
    Node* fcur = root;
    while(fcur != nullptr){
        Node* dummy = new Node(-1);
        Node* scur = dummy;
        while(fcur != nullptr){
            if(fcur->left){
                scur->next = fcur->left;
                scur = scur->next;
            }
            if(fcur->right){
                scur->next = fcur->right;
                scur = scur->next;
            }
            fcur = fcur->next;
        }
        fcur = dummy->next;
    }
    return root;
}