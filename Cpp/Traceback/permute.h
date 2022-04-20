#pragma once
#ifndef _PERMUTE_H
#define _PERMUTE_H
#include "common.h"

class Permute
{
    public:
        /* 46.全排列 */
        vector<vector<int>> permute(vector<int>& nums);
        /* 47.全排列II */
        vector<vector<int>> permuteUnique(vector<int>& nums);


};

#endif