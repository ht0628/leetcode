#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    //3.无重复字符的最长子串
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_set <char> record;
        int maxLenth = 0;

        for(int left = 0, right = 0; right < n; right++){
            while(record.count(s[right])){
                record.erase(s[left]);
                left++;
            }
            record.insert(s[right]);
            maxLenth = max(maxLenth, right-left+1);
        }
        return maxLenth;
    }

    //5.最长回文子串
    //动态规划
    string longestPalindrome(string s){
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        int resIdx = 0;
        int maxLenth = 0;

        for(int j = 0; j < n; j++){
            for(int i = 0; i<=j; i++){
                if(j - i < 3){
                    dp[i][j] = (s[i]==s[j]);
                }
                else{
                    dp[i][j] = (s[i]==s[j]) && dp[i+1][j-1];
                }
                if(dp[i][j]){
                    if(maxLenth < j-i+1){
                        maxLenth = j-i+1;
                        resIdx = i;
                    }
                }
            }
        }
        return s.substr(resIdx, maxLenth);
    }
    //中心扩散法
    string expand(string &s, int left, int right){
        while(left>=0&&right<=s.size()-1&&s[left]==s[right]){
            left--;
            right++;
        }
        return s.substr(left+1,right-left-1);
    }
    string longestPalindrome1(string s){
        string res = "";
        if(s.size() < 2) return s;

        for(int i=0;i<s.size();i++){
            string res1 = expand(s,i,i);
            res = (res1.size() > res.size())?res1:res;
            if((i+1) < s.size()){ 
                string res2 = expand(s,i,i+1);
                res = (res2.size() > res.size())?res2:res;
            }
        }
        return res;
    }

    //76.最小覆盖字串
    string minWindow(string s, string t){
        int left = 0;
        unordered_map<char,int> record;
        for(char c:t){
            record[c]++;
        }
        int n = s.size();
        int count = t.size();
        string res(n+1,'0');

        for(int right=0;right<n;right++){
            if(record.find(s[right]) != record.end()){
                record[s[right]]--;
                if(record[s[right]] >= 0) 
                    count--;
            }
            while(!count){
                if(record.find(s[left]) != record.end()){
                    record[s[left]]++;
                    if(record[s[left]] > 0){
                        count++;
                        res = ((right-left+1) < res.size())?s.substr(left,right-left+1):res;
                    }
                }
                left++;
            }
        }
        return (res.size()==n+1)?"":res;
    }

    //187.重复的DNA序列
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        if(s.size()<10){
            return res;
        }
        unordered_map<string,int> record;
    
        for(int i=0;i<s.size()-9;i++){
            string tmp = s.substr(i,10);
            record[tmp]++;
        }
        for(auto iter=record.begin(); iter!=record.end(); iter++){
            if(iter->second > 1){
                res.push_back(iter->first);
            }
        }
        return res;
    }
};

int main()
{
    Solution s = Solution();

    string s1 = "abcabcbb";
    int res1 = 0;
    res1 = s.lengthOfLongestSubstring(s1);
    cout << "res1=" << res1 << endl;

    string s2 = "abcabcbba";
    string res2;
    res2 = s.longestPalindrome(s2);
    cout << "res2=" << res2 << endl;
    string res3;
    res3 = s.longestPalindrome1(s2);
    cout << "res3=" << res3 << endl;

    string s4 = "ADOBECODEBANC", t="ABC";
    string res4 = s.minWindow(s4,t);
    cout << "res4=" << res4 << endl;

    string s5 = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string> res5 = s.findRepeatedDnaSequences(s5);
    for(auto iter=res5.begin(); iter!=res5.end(); iter++){
        cout << *iter << " ";
    }

}

