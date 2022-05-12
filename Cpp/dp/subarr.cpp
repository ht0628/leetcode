#include "subarr.h"

int Subarr::maxSubArray(vector<int>& nums){
    int n = nums.size();
    vector<int> dp(n);
    dp[0] = nums[0];
    int maxSum = dp[0];
    for(int i = 1; i < n; i++){
        if(dp[i - 1] > 0){
            dp[i] = dp[i - 1] + nums[i];
        }
        else{
            dp[i] = nums[i];
        }
        maxSum = max(maxSum, dp[i]);
    }
    return maxSum;
}

int maxSubArray(vector<int>& nums){
    int n = nums.size();
    int maxSum = nums[0];
    int cur = nums[0];
    for(int i = 1; i < n; i++){
        if(cur > 0)
            cur = nums[i] + cur;   
        else
            cur = nums[i];
        maxSum = max(maxSum, cur);
    }
    return maxSum;
}

int Subarr::maxProduct(vector<int>& nums){
    int n = nums.size();
    vector<int> maxdp(n);
    vector<int> mindp(n);
    maxdp[0] = nums[0];
    mindp[0] = nums[0];
    int res = nums[0];

    for(int i = 1; i < n; i++){
        maxdp[i] = max(nums[i] * maxdp[i - 1], max(nums[i] * mindp[i - 1], nums[i]));
        mindp[i] = min(nums[i] * mindp[i - 1], min(nums[i] * maxdp[i - 1], nums[i]));
        res = max(res, maxdp[i]);
    }
    return res;
}

int Subarr::findLength(vector<int>& nums1, vector<int>& nums2){
    int m = nums1.size();
    int n = nums2.size();
    int maxLenth = 0;
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for(int i = m - 1; i >= 0; i--){
        for(int j = n - 1; j >= 0; j--){
            if(nums1[i] == nums2[j]){
                dp[i][j] = dp[i+1][j+1] + 1;
                maxLenth = max(maxLenth, dp[i][j]);
            }
            else{
                dp[i][j] = 0;
            }
        }
    }  
    return maxLenth;   
}