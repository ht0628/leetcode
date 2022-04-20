#include "dfs.h"

void _solve(vector<vector<char>>& board, int row, int col){
    if(row >= board.size() || col >= board[0].size() || row < 0 || col < 0){
        return;
    }
    if(board[row][col] == 'O'){
        board[row][col] = 'A';
        _solve(board, row + 1, col);
        _solve(board, row - 1, col);
        _solve(board, row, col + 1);
        _solve(board, row, col - 1);
    }
}
void DFS::solve(vector<vector<char>>& board){
    int m = board.size();
    int n = board[0].size();
    for(int i = 0; i < m; i++){
        _solve(board, i, 0);
        _solve(board, i, n-1);
    }
    for(int j = 0; j < n; j++){
        _solve(board, 0, j);
        _solve(board, m-1, j);
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

void _numIslands(vector<vector<char>>& grid, int row, int col){
    if(row >= grid.size() || col >= grid[0].size() || row < 0 || col < 0){
        return;
    }
    if(grid[row][col] != '1'){
        return;
    }
    grid[row][col] = '2';
    _numIslands(grid, row + 1, col);
    _numIslands(grid, row - 1, col);
    _numIslands(grid, row, col + 1);
    _numIslands(grid, row, col - 1);
}
int DFS::numIslands(vector<vector<char>>& grid){
    int count = 0;
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            if(grid[i][j] == '1'){
                count++;
                _numIslands(grid, i, j);
            }
        }
    }
    return count;
}
int _islandPerimeter(vector<vector<int>>& grid, int row, int col){
    if(row >= grid.size() || col >= grid[0].size() || row < 0 || col < 0){
        return 1;
    }
    if(grid[row][col] == 0){
        return 1;
    }
    if(grid[row][col] == 2){
        return 0;
    }
    grid[row][col] = 2;
    return  _islandPerimeter(grid, row + 1, col) +
            _islandPerimeter(grid, row - 1, col) +
            _islandPerimeter(grid, row, col + 1) +
            _islandPerimeter(grid, row, col - 1);

}
int DFS::islandPerimeter(vector<vector<int>>& grid){
    int res = 0;
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            if(grid[i][j] == 1){
                res += _islandPerimeter(grid, i, j);
            }
        }
    }
    return res;
}
int _maxAreaOfIsland(vector<vector<int>>& grid, int row, int col){
    if(row >= grid.size() || col >= grid[0].size() || row < 0 || col < 0){
        return 0;
    }
    if(grid[row][col] == 0){
        return 0;
    }
    if(grid[row][col] == 2){
        return 0;
    }
    grid[row][col] = 2;
    return  1 + 
            _maxAreaOfIsland(grid, row + 1, col) +
            _maxAreaOfIsland(grid, row - 1, col) + 
            _maxAreaOfIsland(grid, row, col + 1) + 
            _maxAreaOfIsland(grid, row, col - 1);


}
int DFS::maxAreaOfIsland(vector<vector<int>>& grid){
    int res = 0;
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            if(grid[i][j] == 1){
                res = max(res, _maxAreaOfIsland(grid, i, j));
            }
        }
    }
    return res;
}
int _largestIsland(vector<vector<int>>& grid){
    return 0;
}
int DFS::largestIsland(vector<vector<int>>& grid){
    return 0;
}