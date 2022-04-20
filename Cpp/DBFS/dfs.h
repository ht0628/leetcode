#pragma once
#ifndef _DFS_H
#define _DFS_H
#include "common.h"

class DFS
{
    public:
        /* 130.被围绕的区域 */
        void solve(vector<vector<char>>& board);
        /* 200.岛屿数量 */
        int numIslands(vector<vector<char>>& grid);
        /* 463.岛屿的周长 */
        int islandPerimeter(vector<vector<int>>& grid);
        /* 695.岛屿的最大面积 */
        int maxAreaOfIsland(vector<vector<int>>& grid);
        /* 827. 最大人工岛 */
        int largestIsland(vector<vector<int>>& grid);

};


#endif