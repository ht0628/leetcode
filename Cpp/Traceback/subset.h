#pragma once
#ifndef _SUBSET_H
#define _SUBSET_H
#include "common.h"

class Subset
{
    public:
        /* 78.子集 */
        vector<vector<int>> subsets(vector<int>& nums);
        /* 90.子集II*/
        vector<vector<int>> subsetsWithDup(vector<int>& nums);
};

#endif