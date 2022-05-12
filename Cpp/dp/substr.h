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

        /* 44. 通配符匹配 */
        bool isMatch(string s, string p);
        /* 10.正则表达式匹配 */
        bool isMatch2(string s, string p);
        
        /* 139.单词拆分 */
        bool wordBreak(string s, vector<string>& wordDict);
        /* 140.单词拆分II */
        vector<string> wordBreak2(string s, vector<string>& wordDict);
        /* 343.整数拆分 */
        int integerBreak(int n);

        /* 32.最长有效括号 */
        int longestValidParentheses(string s);

};

#endif