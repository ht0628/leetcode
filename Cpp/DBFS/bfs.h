#pragma once
#ifndef _BFS_H
#define _BFS_H
#include "common.h"
class Node {
    public:
        int val;
        vector<Node*> neighbors;
        Node() {
            val = 0;
            neighbors = vector<Node*>();
        }
        Node(int _val) {
            val = _val;
            neighbors = vector<Node*>();
        }
        Node(int _val, vector<Node*> _neighbors) {
            val = _val;
            neighbors = _neighbors;
        }
};
class BFS
{
    public:
        /* 127.单词接龙 */
        /* 单向BFS */
        int ladderLength(string beginWord, string endWord, vector<string>& wordList);
        /* 双向BFS */
        int ladderLength2(string beginWord, string endWord, vector<string>& wordList);
        /* 126.单词接龙II */
        vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList);
        /* 130.被围绕的区域 */
        void solve(vector<vector<char>>& board);
        /* 133.克隆图 */
        Node* cloneGraph(Node* node);

};

#endif