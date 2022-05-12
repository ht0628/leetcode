#pragma once
#ifndef _SUBSEQ_H
#define _SUBSEQ_H
#include "common.h"

class Subseq{
    public:
        /* 115.不同的子序列 */
        int numDistinct(string s, string t);
        /* 392.判断子序列 */
        bool isSubsequence(string s, string t);
        /* 1143.最长公共子序列 */
        int longestCommonSubsequence(string text1, string text2);
        /* 516.最长回文子序列 */
        int longestPalindromeSubseq(string s);
        
        /* 300.最长递增子序列 */
        int lengthOfLIS(vector<int>& nums);
        /* 334.递增的三元子序列 */
        bool increasingTriplet(vector<int>& nums);
        /* 673.最长递增子序列的个数 */
        int findNumberOfLIS(vector<int>& nums);
        /* 674.最长连续递增序列 */
        int findLengthOfLCIS(vector<int>& nums);

        /* 446.等差数列划分 II - 子序列 */
        int numberOfArithmeticSlices(vector<int>& nums);

        /* 198.打家劫舍 */
        int rob(vector<int>& nums);
        /* 213.打家劫舍 II */
        int robII(vector<int>& nums);
        
};


#endif