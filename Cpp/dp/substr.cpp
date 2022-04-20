#include "substr.h"

string Substr::longestPalindrome(string s){
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    int maxLenth = 1;
    string s1 = "";
    string maxStr = s1 + s[0];

    for(int j = 0; j < n; j++){
        for(int i = 0; i < n; i++){
            if(i == j){
                dp[i][j] = true;
            }
            else if(i > j){
                continue;
            }
            else{
                if(i + 1 > j - 1){
                    dp[i][j] = (s[i] == s[j]);
                }
                else{
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                }
                if(dp[i][j] == true && j - i + 1 > maxLenth){
                    maxLenth = j - i + 1;
                    maxStr = s.substr(i, j - i + 1);
                }
            }
        }
    }
    return maxStr;
}

vector<vector<bool>> __partition(string s){
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, true));
    for(int i = n - 1; i >= 0; i--){
        for(int j = i + 1; j < n; j++){
            dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
        }
    }
    return dp;
}
void _partition(string s, vector<vector<string>>& res, vector<string>& path, int idx, vector<vector<bool>>& dp){
    if(idx == s.size()){
        res.push_back(path);
        return;
    }
    for(int i = idx; i < s.size(); i++){
        string sub = s.substr(idx, i - idx + 1);
        if(dp[idx][i]){
            path.push_back(sub);
            _partition(s, res, path, i + 1, dp);
            path.pop_back();
        }
    }

}
vector<vector<string>> Substr::partition(string s){
    vector<vector<bool>> dp = __partition(s);
    vector<vector<string>> res;
    vector<string> path;
    _partition(s, res, path, 0, dp);
    return res;
}

int Substr::minCut(string s){
    int n = s.size();
    vector<vector<bool>> dp1(n, vector<bool>(n, true));
    vector<int> dp2(n, n - 1);
    for(int i = n - 1; i >= 0; i--){
        for(int j = i + 1; j < n; j++){
            dp1[i][j] = dp1[i+1][j-1] && (s[i] == s[j]);
        }
    }
    for(int i = 0; i < n; i++){
        if(dp1[0][i]){
            dp2[i] = 0;
        }
        else{
            for(int j = 1; j <= i; j++){
                if(dp1[j][i]){
                    dp2[i] = min(dp2[i], dp2[j - 1] + 1);
                }
            }
        }
    }
    return dp2[n-1];

}

bool Substr::wordBreak(string s, vector<string>& wordDict){
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    int n = s.size();
    vector<bool> dp(n + 1, false);
    dp[0] = true;
    for(int i = 1; i <= n; i++){
        for(int j = i - 1; j >= 0; j--){
            if(dp[j]){
                string tmp = s.substr(j, i - j);
                if(dict.find(tmp) != dict.end()){
                    dp[i] = true;
                }
            }
        }
    }
    return dp[n];
}