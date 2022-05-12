#include "substr.h"

string Substr::longestPalindrome(string s){
    int n = s.size();
    string res = s.substr(0,1);
    /* dp[i][j]表示s的i~j(idx)子串是否是回文串 */
    /* 对角线都是回文串，所以默认用true，这样避免了讨论对角线的情况 */
    vector<vector<bool>> dp(n, vector<bool>(n, true));
    /* 自底向上遍历 */
    for(int i = n - 1; i >= 0; i--){
        for(int j = i + 1; j <= n - 1; j++){
            dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
            if(dp[i][j] == true){
                if(j - i + 1 > res.size()){
                    res = s.substr(i, j - i + 1);
                }
            }
        }
    }
    return res;
}

void _partition(string s, vector<vector<string>>& res, vector<string>& path, int idx, vector<vector<bool>>& dp){
    /* 存储变量：res,path 位置变量：idx-表示切割起始位置 辅助变量：dp */
    /* 当切割起始位置超限，则return */
    if(idx == s.size()){
        res.push_back(path);
        return;
    }
    /* 选择切割的终止位置 */
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
    int n = s.size();
    /* 构建回文串预解dp-同上 */
    vector<vector<bool>> dp(n, vector<bool>(n, true));
    for(int i = n - 1; i >= 0; i--){
        for(int j = i + 1; j < n; j++){
            dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
        }
    }
    vector<vector<string>> res;
    vector<string> path;
    /* 回溯大法之切割字符串 */
    _partition(s, res, path, 0, dp);
    return res;
}

int Substr::minCut(string s){
    int n = s.size();
    /* 构建回文串dp1预解-同上 */
    vector<vector<bool>> dp1(n, vector<bool>(n, true));
    for(int i = n - 1; i >= 0; i--){
        for(int j = i + 1; j < n; j++){
            dp1[i][j] = dp1[i+1][j-1] && (s[i] == s[j]);
        }
    }
    /* dp2[i]表示角标在[0,i]的子串切割成回文串的最小分割次数 */
    vector<int> dp2(n, n - 1);
    for(int i = 0; i < n; i++){
        /* 首尾构成回文串，则无需分割 */
        if(dp1[0][i]){
            dp2[i] = 0;
        }
        /* 首尾未构成回文串，需要进一步分割 */
        else{
            /* 选择不同的首部j，令角标在[j,i]的子串构成回文串，并筛选出[0，j-1]子串分割次数最小的情况 */
            for(int j = 1; j <= i; j++){
                if(dp1[j][i]){
                    dp2[i] = min(dp2[i], dp2[j - 1] + 1);
                }
            }
        }
    }
    return dp2[n-1];

}

bool Substr::isMatch(string s, string p){
    int m = p.size();
    int n = s.size();
    /* dp[i][j]表示p的前i个字符和s的前j个字符能否匹配 */ 
    vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            /* 第一行边界 */
            if(i == 0){
                if(j == 0) 
                    dp[i][j] = true;
                else 
                    dp[i][j] = false;
            }
            /* 第一列边界 */
            else if(j == 0){
                if(p[i - 1] == '*')
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = false;
            }
            else{
                if(p[i - 1] == '*'){
                    /* 两种情况：不使用*；使用* */
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
                else if(p[i - 1] == '?'){
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else{
                    dp[i][j] = dp[i - 1][j - 1] && p[i - 1] == s[j - 1];
                }
            }
        }
    }
    return dp[m][n];
}

bool Substr::isMatch2(string s, string p){
    int m = p.size();
    int n = s.size();
    /* dp[i][j]表示p的前i个字符和s的前j个字符能否匹配 */ 
    vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            /* 第一行边界 */
            if(i == 0){
                if(j == 0)
                    dp[i][j] = true;
                else
                    dp[i][j] = false;
            }
            /* 第一列边界 */
            else if(j == 0){
                if(p[i - 1] == '*')
                    dp[i][j] = dp[i - 2][j];
            }
            else{
                if(p[i - 1] == '*'){
                    if(p[i - 2] == s[j - 1] || p[i - 2] == '.'){
                        /* 三种情况：使用*删除前面的元素；不使用*号；使用*号重复前面的元素 */
                        dp[i][j] = dp[i - 2][j] || dp[i - 1][j] || dp[i][j - 1];
                    }
                    else if(p[i - 2] != s[j - 1]){
                        /* 只有一种情况： 使用*删除前面的元素*/
                        dp[i][j] = dp[i - 2][j];
                    }
                }
                else if(p[i - 1] == '.'){
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else{
                    dp[i][j] = dp[i - 1][j - 1] && p[i - 1] == s[j - 1];
                }
            }
        }
    }
    return dp[m][n];
}

bool Substr::wordBreak(string s, vector<string>& wordDict){
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    int n = s.size();
    /* dp[i]表示前i个字符能否有dict组成 */
    vector<bool> dp(n + 1, false);
    dp[0] = true;
    /* dp[i]能由字典组成 = 前j个字符能由字典组成 + 剩余字符组成的单词在字典里 */
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

void _wordBreak2(string& s, unordered_set<string>& dict, vector<string>& res, vector<string>& path, int idx, vector<bool>& dp){
    /* 存储变量：res,path 位置变量：idx-表示切割末尾位置 辅助变量：dp */
    /* 切割的末尾朝鲜，则记录path，并return */
    if(idx < 0){
        string x = "";
        for(int i = path.size() - 1; i >= 0; i--){
            x += path[i];
            if(i != 0){
                x += ' ';
            }
        }
        res.push_back(x);
        return;
    }
    /* 选择切割的起始位置 */
    for(int i = idx; i >= 0; i--){
        string tmp = s.substr(i, idx - i + 1);
        /* 成功的切割条件 */
        if(dp[i] && dict.find(tmp) != dict.end()){
            path.push_back(tmp);
            _wordBreak2(s, dict, res, path, i - 1, dp);
            path.pop_back();
        }
    }
}
vector<string> Substr::wordBreak2(string s, vector<string>& wordDict){
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    int n = s.size();
    /* 预解dp - 同上一题 */
    vector<bool> dp(n+1, false);
    dp[0] = true;
    for(int i = 1; i <= n; i++){
        for(int j = i - 1; j >= 0; j --){
            if(dp[j] && dict.find(s.substr(j, i - j)) != dict.end()){
                dp[i] = true;
            }
        }
    }
    /* 回溯大法之反向切割字符串 */
    vector<string> res;
    vector<string> path;
    if(dp[n])
        _wordBreak2(s, dict, res, path, n - 1, dp);
    return res;

}

int Substr::integerBreak(int n){
    /* dp[i]表示i拆分的最大乘积 */
    vector<int> dp(n + 1, 0);
    /* res = max(拆一次[j, i-j], 拆多次) */
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= i - 1; j++){
            dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
        }
    }
    return dp[n];
}

int Substr::longestValidParentheses(string s){
    int n = s.size();
    int maxLenth = 0;
    vector<int> dp(n, 0);
    if(n < 2) return 0;
    for(int i = 1; i < n; i++){
        if(s[i] == ')'){
            if(s[i - 1] == '('){
                dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
            }
            else{
                if(i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '('){
                    dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0)+ 2;
                }
            }
            maxLenth = max(maxLenth, dp[i]);
        }
    }
    return maxLenth;
}