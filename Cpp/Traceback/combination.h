#pragma once
#ifndef _COMBINATION_H
#define _COMBINATION_H
#include "common.h"

class Combination
{
    public:
        /* 77.组合 */
        vector<vector<int>> combine(int n, int k);
        /* 39.组合总和 */
        vector<vector<int>> combinationSum(vector<int>& candidates, int target);
        /* 40.组合总和II */
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target);
        /* 216.组合总和 III */
        vector<vector<int>> combinationSum3(int k, int n);
        /* 17.电话号码的组合 */
        vector<string> letterCombinations(string digits);
        /* 22.括号生成 */
        vector<string> generateParenthesis(int n);
};

#endif