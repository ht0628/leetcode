#include "chessboard.h"


void _solveNQueens(int n, vector<vector<string>>& res, vector<string>& board, int row, unordered_set<int>& above, unordered_set<int>& labove, unordered_set<int>& rabove){
    if(row == n){
        res.push_back(board);
        return;
    }
    for(int j = 0; j < n; j++){
        if(above.find(j) != above.end() || labove.find(row - j) != labove.end() || rabove.find(row + j) != rabove.end()){
            continue;
        }
        above.insert(j);
        labove.insert(row - j);
        rabove.insert(row + j);
        board[row][j] = 'Q';
        _solveNQueens(n, res, board, row + 1, above, labove, rabove);  
        board[row][j] = '.';
        above.erase(j);
        labove.erase(row - j);
        rabove.erase(row + j);
    }
}
vector<vector<string>> Chessboard::solveNQueens(int n){
    vector<vector<string>> res;
    vector<string> board(n, string(n, '.'));
    unordered_set<int> above, labove, rabove;
    _solveNQueens(n, res, board, 0, above, labove, rabove);
    return res;
}
void _totalNQueens(int n, int &res, int row, unordered_set<int>& above, unordered_set<int>& labove, unordered_set<int>& rabove){
    if(row == n){
        res += 1;
        return;
    }

    for(int j = 0; j < n; j++){
        if(above.find(j) != above.end() || labove.find(row - j) != labove.end() || rabove.find(row + j) != rabove.end()){
            continue;
        }
        above.insert(j);
        labove.insert(row - j);
        rabove.insert(row + j);
        _totalNQueens(n, res, row + 1, above, labove, rabove);
        above.erase(j);
        labove.erase(row - j);
        rabove.erase(row + j);
    }
}
int Chessboard::totalNQueens(int n){
    int res = 0;
    unordered_set<int> above;
    unordered_set<int> labove;
    unordered_set<int> rabove;
    _totalNQueens(n, res, 0, above, labove, rabove);
    return res;
}


bool _isValidSudoku(vector<vector<char>>& board, int row, int col){
    int val = board[row][col];
    for(int i = 0; i < 9; i ++){
        if(i == row) 
            continue;
        if(board[i][col] == val) 
            return false;
    }

    for(int j = 0; j < 9; j++){
        if(j == col) 
            continue;
        if(board[row][j] == val) 
            return false; 
    }

    
    int startRow = row / 3 * 3;
    int startCol = col / 3 * 3;
    for(int i = startRow; i < startRow + 3; i++){
        for(int j = startCol; j < startCol + 3; j++){
            if(i == row && j == col)
                continue;
            if(board[i][j] == val){
                return false;
            }
        }
    }
    return true;
}
bool Chessboard::isValidSudoku(vector<vector<char>>& board){
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[0].size(); j++){
            if(board[i][j] == '.')
                continue;
            if(!_isValidSudoku(board, i, j))
                return false;
        }
    }
    return true;
}
bool isValid(vector<vector<char>>& board, int r, int c, int val){
    for(int i = 0; i < 9; i ++){
        if(board[i][c] == val){
            return false;
        }
    }

    for(int j = 0; j < 9; j++){
        if(board[r][j] == val){
            return false;
        }
    }

    int startRow = r / 3 * 3;
    int startCol = c / 3 * 3;
    for(int i = startRow; i < startRow + 3; i++){
        for(int j = startCol; j < startCol + 3; j++){
            if(board[i][j] == val){
                return false;
            }
        }
    }
    return true;
}
bool _solveSudoku(vector<vector<char>>& board){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(board[i][j] != '.'){
                continue;
            }
            for(char k = '1'; k <= '9'; k++){
                if(isValid(board, i, j, k)){
                    board[i][j] = k;
                    if(_solveSudoku(board)) 
                        return true;
                    board[i][j] = '.';
                }
            }
            return false; 
        }
    }
    return true;
}
void solveSudoku(vector<vector<char>>& board){
    _solveSudoku(board);
}


bool _exist(vector<vector<char>>& board, string& word, int idx, int (&dirs)[4][2], int r, int c, vector<vector<int>>& visited){
    if(board[r][c] != word[idx]){
        return false;
    }
    if(idx == word.size() - 1){
        return true;
    }

    for(int i = 0; i < 4; i++){
        int newRow = r + dirs[i][0];
        int newCol = c + dirs[i][1];
        if(newRow < 0 || newRow >= board.size() || newCol < 0 || newCol >= board[0].size()){
            continue;
        }
        if(visited[newRow][newCol] == 1){
            continue;
        }
        visited[newRow][newCol] = 1;
        if(_exist(board, word, idx + 1, dirs, newRow, newCol, visited)) return true;
        visited[newRow][newCol] = 0;
    }
    return false;

}
bool Chessboard::exist(vector<vector<char>>& board, string word){
    int m = board.size();
    int n = board[0].size();
    vector<vector<int>> visited(m, vector<int>(n));
    int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            visited[i][j] = 1;
            if(_exist(board, word, 0, dirs, i, j, visited)){
                return true;
            }
            visited[i][j] = 0;
        }
    }
    return false;
}
bool _exist2(vector<vector<char>>& board, string& word, int row, int col, int idx, vector<vector<int>>& visited){
    if(idx == word.size()){
        return true;
    }

    if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size()){
        return false;
    }
    
    if(word[idx] != board[row][col])
        return false;
    
    if(visited[row][col] == 1){
        return false;
    }
    
    visited[row][col] = 1;
    if( _exist2(board, word, row + 1, col, idx + 1, visited)||
        _exist2(board, word, row - 1, col, idx + 1, visited)||
        _exist2(board, word, row, col + 1, idx + 1, visited)||
        _exist2(board, word, row, col - 1, idx + 1, visited)){
        return true;
    }
    visited[row][col] = 0;

    return false;
}
bool Chessboard::exist2(vector<vector<char>>& board, string word){
    int m = board.size();
    int n = board[0].size();
    vector<vector<int>> visited(m, vector<int>(n));

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(_exist2(board, word, i, j, 0, visited)){
                return true;
            }
        }
    }
    return false;
}
void _findWords(vector<vector<char>>& board, unordered_set<string>& words, int& maxLenth, vector<string>& res, string& path, int (&dirs)[4][2], int row, int col, vector<vector<int>>& visited){    
    if(path.size() > maxLenth){
        return;
    }
    if(words.find(path) != words.end()){
        res.push_back(path);
        words.erase(path);
        maxLenth = 0;
        for(auto w = words.begin(); w != words.end(); w++){
            int size = (*w).size();
            maxLenth = max(maxLenth, size);
        }
    }

    for(int i = 0; i < 4; i++){
        int newRow = row + dirs[i][0];
        int newCol = col + dirs[i][1];
        if(newRow < 0 || newRow >= board.size() || newCol < 0 || newCol >= board[0].size()){
            continue;
        }
        if(visited[newRow][newCol] == 1){
            continue;
        }
        visited[newRow][newCol] = 1;
        path.push_back(board[newRow][newCol]);
        _findWords(board, words, maxLenth, res, path, dirs, newRow, newCol, visited);
        path.pop_back();
        visited[newRow][newCol] = 0;
    }
}
vector<string> Chessboard::findWords(vector<vector<char>>& board, vector<string>& words){
    int m = board.size();
    int n = board[0].size();
    unordered_set<string> words_(words.begin(), words.end());
    int maxLenth = 0;
    for(auto w = words.begin(); w != words.end(); w++){
        int size = (*w).size();
        maxLenth = max(maxLenth, size);
    }
    vector<string> res;
    string path = "";
    int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<int>> visited(m, vector<int>(n));

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            visited[i][j] = 1;
            path.push_back(board[i][j]);
            _findWords(board, words_, maxLenth, res, path, dirs, i, j, visited);
            path.pop_back();
            visited[i][j] = 0;
        }
    }
    return res;
}
void _findWords2(vector<vector<char>>& board, unordered_set<string>& words, vector<string>& res, string& path, int row, int col, int& maxLenth, vector<vector<int>>& visited){
    if(words.find(path) != words.end()){
        res.push_back(path);
        words.erase(path);
        maxLenth = 0;
        for(auto w = words.begin(); w != words.end(); w++){
            int size = (*w).size();
            maxLenth = max(maxLenth, size);
        }
    }

    if(path.size() >= maxLenth){
        return;
    }
    if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size()){
        return;
    }
    if(visited[row][col] == 1){
        return;
    }

    path.push_back(board[row][col]);
    visited[row][col] = 1;
    _findWords2(board, words, res, path, row + 1, col, maxLenth, visited);
    _findWords2(board, words, res, path, row - 1, col, maxLenth, visited);
    _findWords2(board, words, res, path, row, col + 1, maxLenth, visited);
    _findWords2(board, words, res, path, row, col - 1, maxLenth, visited);
    visited[row][col] = 0;
    path.pop_back();

}
vector<string> Chessboard::findWords2(vector<vector<char>>& board, vector<string>& words){
    int m = board.size();
    int n = board[0].size();
    unordered_set<string> words_(words.begin(), words.end());
    vector<string> res;
    string path = "";
    int maxLenth = 0;
    for(auto w = words.begin(); w != words.end(); w++){
        int size = (*w).size();
        maxLenth = max(maxLenth, size);
    }
    vector<vector<int>> visited(m, vector<int>(n));

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            _findWords2(board, words_, res, path, i, j, maxLenth, visited);
        }
    }
    return res;
}

