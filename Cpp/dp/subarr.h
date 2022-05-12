#pragma once
#ifndef _SUBARR_H
#define _SUBARR_H
#include "common.h"

class Subarr
{   
    public:
        /* 53.最大子数组和 */
        int maxSubArray(vector<int>& nums);
        /* 152.乘积最大子数组 */
        int maxProduct(vector<int>& nums);
        /* 718.最长重复子数组 */
        int findLength(vector<int>& nums1, vector<int>& nums2);
};

#endif