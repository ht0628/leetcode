#include "subseq.h"

int Subseq::numDistinct(string s, string t){
    int m = t.size();
    int n = s.size();
    /* dp[i][j]代表 t 的前i个字符和 s 的前j个字符的子序列数 */
    vector<vector<unsigned int>>dp(m + 1, vector<unsigned int>(n + 1));
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            /* 第一行边界 */
            if(i == 0){
                dp[i][j] = 1;
            }
            /* 第一列边界 */
            else if(j == 0){
                dp[i][j] = 0;
            }
            else{
                /* 相当于无用功 - s扩张变化无用即等于之前的 */
                if(s[j - 1] != t[i - 1]){
                    dp[i][j] = dp[i][j - 1];
                }
                /* 之前的 + s[:-1]&&t[::-1]的子序列数 */
                else{
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1]; 
                }
            }
        }
    }
    return dp[m][n];
}

bool Subseq::isSubsequence(string s, string t){
    int m = s.size();
    int n = t.size();
    /* dp[i][j]代表 s 的前i个字符是否是 t 的前j个字符的子序列 */
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            if(i == 0){
                dp[i][j] = true;
            }
            else if(j == 0){
                dp[i][j] = false;
            }
            else{
                if(s[i - 1] == t[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else{
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
    }
    return dp[m][n];
} 

int Subseq::longestCommonSubsequence(string text1, string text2){
    int m = text1.size();
    int n = text2.size();
    /* dp[i][j]代表 text1 的前i个字符是否是 text2 的前j个字符的子序列 */
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(text1[i - 1] == text2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    for(int i = 0; i <= m; i++){
        printContrainer(dp[i]);
    }
    return dp[m][n];
}

int Subseq::longestPalindromeSubseq(string s){
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int i = n - 1; i >= 0; i--){
        for(int j = i; j < n; j++){
            if(i == j){
                dp[i][j] = 1;
            }
            else{
                if(s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1] + 2;
                else
                    dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
            }
        }
    }
    return dp[0][n-1];
}


int Subseq::lengthOfLIS(vector<int>& nums){
    int n = nums.size();
    /* dp[i]代表第i个元素作为尾部元素的最长递增子序列 */
    vector<int> dp(n, 1);
    int maxLenth = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(nums[i] > nums[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            } 
        }
        maxLenth = max(maxLenth, dp[i]);
    }
    return maxLenth;
}

bool increasingTriplet(vector<int>& nums){
    int n = nums.size();
    /* 此处dp同上 */
    vector<int> dp(n, 1);
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(nums[i] > nums[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        if(dp[i] >= 3){
            return true;
        }
    }
    return false;
}

int Subseq::findNumberOfLIS(vector<int>& nums){
    int n = nums.size();
    int maxLenth = 1;
    int res = 0;
    /* dp[i]代表以nums[i]为结尾的最长子序列长度,defalult:1 */
    vector<int> dp(n, 1);
    /* cnt[i]代表以nums[i]为结尾的最长子序列的数量,defalut:1 */
    vector<int> cnt(n, 1);

    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(nums[i] > nums[j]){
                /* 此处if表示第一次找到更长的子序列 */
                if(dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    /* 此处将nums[i]直接拼接在num[j]之后，因此初值更新为cnt[j] */
                    cnt[i] = cnt[j];
                    maxLenth = max(maxLenth, dp[i]);
                }
                /* 此处else表示第n(n > 1)次找到相同长度的子序列 */
                else if(dp[j] + 1 == dp[i]){
                    cnt[i] += cnt[j];
                }
            } 
        }
    }
    for(int i = 0; i < n; i++){
        if(dp[i] == maxLenth){
            res += cnt[i]; 
        }
    }
    return res;
}

int Subseq::findLengthOfLCIS(vector<int>& nums){
    int n = nums.size();
    int maxLenth = 1;
    vector<int> dp(n, 1);
    for(int i = 1; i < n; i++){
        if(nums[i] > nums[i-1]){
            dp[i] = dp[i - 1] + 1;
            maxLenth = max(maxLenth, dp[i]);
        }
    }
    return maxLenth;
}


int Subseq::numberOfArithmeticSlices(vector<int>& nums){
    int n = nums.size();
    int res = 0;
    /* dp[i]表示对应的哈希表 */
    vector<unordered_map<int, int>> dp(n);
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            int diff = nums[i] - nums[j];
            dp[i][diff] += dp[j][diff] + 1;
            if(dp[j][diff] > 0){
                res += dp[j][diff];
            }
        }
    }
    return res;
}


int Subseq::rob(vector<int>& nums){
    int n = nums.size();
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = nums[0];
    for(int i = 2; i <=n; i++){
        dp[i] = max(dp[i - 1], nums[i - 1] + dp[i - 2]);
    }
    return dp[n];
}
int rob2(vector<int>& nums){
    // int n = nums.size();
    // if(nums.size() == 1) return nums[0];
    // if(nums.size() == 2) return max(nums[0], nums[1]);
    // int prev = nums[0];
    // int curr = max(nums[0], nums[1]);
    // for(int i = 2; i < n; i++){
    //     int tmp = max(prev + nums[i], curr);
    //     prev = curr;
    //     curr = tmp;
    // }
    // return curr;
    int n = nums.size();
    int prev = 0;
    int curr = 0;
    for(int i = 0; i < n; i++){
        int tmp = max(prev + nums[i], curr);
        prev = curr;
        curr = tmp;
    }
    return curr;
}

int robII_(vector<int>& nums, int start, int end){
    int prev = 0;
    int curr = 0;
    for(int i = start; i <= end; i++){
        int tmp = max(prev + nums[i], curr);
        prev = curr;
        curr = tmp;
    }
    return curr;
}
int Subseq::robII(vector<int>& nums){
    int n = nums.size();
    if(n == 1) return nums[0];
    
    return max(robII_(nums, 0, n-2), robII_(nums, 1, n-1));
}