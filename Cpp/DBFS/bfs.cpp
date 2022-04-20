#include "bfs.h"

int BFS::ladderLength(string beginWord, string endWord, vector<string>& wordList){
    unordered_set<string> set(wordList.begin(), wordList.end());
    if(set.find(endWord) == set.end()){
        return 0;
    }
    if(set.find(beginWord) != set.end()){
        set.erase(beginWord);
    }
    int res = 0;
    queue<string> q;
    q.push(beginWord);
    while (!q.empty()){
        res++;
        int n = q.size();
        for(int i = 0; i < n; i++){
            string word = q.front();
            q.pop();
            if(word == endWord){
                return res;
            }
            for(int j = 0; j < word.size(); j++){
                for(char c = 'a'; c <= 'z'; c++){
                    string newWord(word);
                    newWord[j] = c;
                    if(set.find(newWord) != set.end()){
                        q.push(newWord);
                        set.erase(newWord);
                    }
                }
            }
        }
    }
    return 0;
}
int BFS::ladderLength2(string beginWord, string endWord, vector<string>& wordList){
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    if(wordSet.find(endWord) == wordSet.end())
        return 0;
    int res = 0;
    unordered_set<string> beginSet{beginWord};
    unordered_set<string> endSet{endWord};
    wordSet.erase(beginWord);
    while(!beginSet.empty() && !endSet.empty()){
        res++;
        if(beginSet.size() > endSet.size()){
            swap(beginSet, endSet);
        }
        unordered_set<string> nextBeginSet;
        for(string word : beginSet){
            for(int i = 0; i < word.size(); i++){
                for(int j = 'a'; j <= 'z'; j++){
                    string tmp = word;
                    tmp[i] = j;
                    if(endSet.find(tmp) != endSet.end()){
                        return res + 1;
                    }
                    if(wordSet.find(tmp) != wordSet.end()){
                        nextBeginSet.insert(tmp);
                        wordSet.erase(tmp);
                    }

                }
            }
        }
        beginSet = nextBeginSet;
    }
    return 0;
}

vector<vector<string>> BFS::findLadders(string beginWord, string endWord, vector<string>& wordList){
    vector<vector<string>> res;
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    if(wordSet.find(endWord) == wordSet.end())  
        return res;

    queue<string> q1;
    queue<vector<string>> q2;
    vector<string> begin = {beginWord};
    q1.push(beginWord);
    q2.push(begin);
    while(!q1.empty()){
        int n = q1.size();
        for(int i = 0; i < n; i++){
            string word = q1.front();
            vector<string> path = q2.front();
            q1.pop();
            q2.pop();
            wordSet.erase(word);
            if(word == endWord){
                res.push_back(path);
            }
            for(int i = 0; i < word.size(); i++){
                for(char c = 'a'; c <= 'z'; c++){
                    string tmp = word;
                    tmp[i] = c;
                    if(wordSet.find(tmp) != wordSet.end()){
                        q1.push(tmp);
                        vector<string> newPath = path;
                        newPath.push_back(tmp);
                        q2.push(newPath);
                    }
                }
            }
        }
        if(res.size() != 0){
            return res;
        }
    }
    return res;
}

void _solve_bfs(vector<vector<char>>& board, int row, int col){
    queue<pair<int, int>> q;
    q.push({row,col});

    while(!q.empty()){
        int n = q.size();
        for(int i = 0; i < n; i++){
            pair<int, int> p = q.front();
            q.pop();
            int r = p.first;
            int c = p.second;
            if(r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] != 'O'){
                continue;
            }
            board[r][c] = 'A';
            q.push({r + 1, c});
            q.push({r - 1, c});
            q.push({r, c + 1});
            q.push({r, c - 1});
        }
    }
}
void BFS::solve(vector<vector<char>>& board){
    int m = board.size();
    int n = board[0].size();

    for(int i = 0; i < m; i++){
        if(board[i][0] == 'O'){
            _solve_bfs(board, i, 0);
        }
        if(board[i][n-1] == 'O'){
            _solve_bfs(board, i, n-1);
        }
    }

    for(int j = 0; j < n; j++){
        if(board[0][j] == 'O'){
            _solve_bfs(board, 0, j);
        }
        if(board[m-1][j] == 'O'){
            _solve_bfs(board, m - 1, j);
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == 'A'){
                board[i][j] = 'O';
            }
            else if(board[i][j] == 'O'){
                board[i][j] = 'X';
            }
        }
    }

}

Node* BFS::cloneGraph(Node* node){
    if(node == nullptr){
        return node;
    }
    unordered_map<Node*, Node*> visited;
    queue<Node*> q;
    visited[node] = new Node(node->val);
    q.push(node);

    while(!q.empty()){
        int n = q.size();
        for(int i = 0; i < n; i++){
            Node* node = q.front();
            q.pop();
            for(auto neighbor : node->neighbors){
                if(visited.find(neighbor) == visited.end()){
                    visited[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                visited[node]->neighbors.push_back(visited[neighbor]);
            }
        }
    }
    return visited[node];
}