#pragma once
#ifndef _2D_H
#define _2D_H
#include "common.h"

class Chessboard
{
    public:
        /* 51.N皇后 */
        vector<vector<string>> solveNQueens(int n);
        /* 52.N皇后II */
        int totalNQueens(int n);

        /* 36.有效的数独 */
        bool isValidSudoku(vector<vector<char>>& board);
        /* 37.解数独 */
        void solveSudoku(vector<vector<char>>& board);
        
        /* 79.单词搜索 */
        /* for循环写法 前馈控制 */
        bool exist(vector<vector<char>>& board, string word);
        /* 枚举写法 反馈控制*/
        bool exist2(vector<vector<char>>& board, string word);
        /* 212.单词搜索 II */
        /* for循环写法 前馈控制 */
        vector<string> findWords(vector<vector<char>>& board, vector<string>& words);
        /* 枚举写法 反馈控制*/
        vector<string> findWords2(vector<vector<char>>& board, vector<string>& words);
        /* 前缀树写法 */
        vector<string> findWords3(vector<vector<char>>& board, vector<string>& words);
};

#endif