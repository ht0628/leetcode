#pragma once
#ifndef _SUBSTR_H
#define _SUBSTR_H
#include "common.h"

class Substr
{
    public:
        /* 5.最长回文子串 */
        string longestPalindrome(string s);
        /* 131.分割回文串 */
        vector<vector<string>> partition(string s);
        /* 132.分割回文串II */
        int minCut(string s);
        
        /* 139.单词拆分 */
        bool wordBreak(string s, vector<string>& wordDict);
};

#endif