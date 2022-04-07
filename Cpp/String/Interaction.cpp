#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    //14.最长公共前缀
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        for(int i = 0; i < strs[0].size(); i++){
            for(int j = 0; j < strs.size() - 1; j++){
                if((i > strs[j].size() -1) || (i > strs[j+1].size() - 1) || (strs[j][i] != strs[j+1][i])){
                    return res;
                }
            }
            res += strs[0][i];
        }
        return res;
    }

    //30.串联所有单词的子串
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size();
        int wordsNum = words.size();
        int wordLenth = words[0].size();
        int winLenth = wordsNum * wordLenth;
        unordered_map<string, int> umap;
        for(auto word:words){
            umap[word]++;
        }
        vector<int> res;

        for(int i=0; i < n - winLenth + 1; i++){
            unordered_map<string, int> record;
            string target = s.substr(i,winLenth);
            int cnt = wordsNum;
            int j = 0;
            while(j < target.size()){
                string tmp = target.substr(j,wordLenth);
                record[tmp]++;
                if(umap.find(tmp) == umap.end()) break;
                if(umap[tmp] < record[tmp]) break;
                j+= wordLenth;
            }
            if(j == target.size()) res.push_back(i);
        }
        return res;
    }

    //415.字符串相加
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1, j = num2.size() - 1, carry = 0;
        string res = "";
        
        while(i >= 0 || j >= 0 || carry){
            int a = (i >= 0) ? num1[i--] - '0' : 0;
            int b = (j >= 0) ? num2[j--] - '0' : 0;
            int tmp = (a + b + carry) % 10;
            carry = (a + b + carry) / 10;
            res += to_string(tmp);
        }
        reverse(res.begin(),res.end());
        return res;
    }

    //43.字符串相乘
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0"){
            return "0";
        }
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int n1 = num1.size();
        int n2 = num2.size();
        vector<int> res(n1 + n2);

        for(int i = 0; i < n1; i++){
            for(int j = 0; j < n2; j++){
                res[i+j] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        for(int i = 0; i < res.size() - 1; i++){
            if(res[i] > 9){
                int carry = res[i] / 10;
                res[i] = res[i] % 10;
                res[i+1] = res[i+1] + carry;
            }
        }
        
        if(res.back() == 0) res.pop_back();
        reverse(res.begin(),res.end());
        string s = "";
        for(int i:res){
            s += (i + '0');
        }
        return s;
    }

    //49.字母异位词分组
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string,int> umap;

        int idx = 0;
        for(string s:strs){
            string tmp = s;
            sort(tmp.begin(),tmp.end());
            if(umap.find(tmp) == umap.end()){
                umap[tmp] = idx++;
                vector<string> v = {s};
                res.push_back(v);
            }
            else{
                res[umap[tmp]].push_back(s);
            }
        }
        return res;
    }

    //67.二进制求和
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        string res;
        int i = 0, j = 0, carry = 0;
        while(i < a.size() || j < b.size() || carry){
            int x = (i < a.size()) ? (a[i] - '0') : 0;
            int y = (j < b.size()) ? (b[j] - '0') : 0;
            int tmp = x + y + carry;
            carry = tmp / 2;
            int remainder = tmp % 2;
            res.push_back(remainder + '0');
            i++;
            j++;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    Solution s = Solution();
    vector<string> strs = {"flower","flow","flight"};
    string res1 = s.longestCommonPrefix(strs);
    cout << res1 << endl;

    vector<string> words = {"foo","bar"};
    vector<int> res2 = s.findSubstring("barfoothefoobarman",words);
    for(int i = 0; i < res2.size(); i++){
        cout << res2[i] << " ";
    }
    cout << endl;

    string res3 = s.addStrings("456","77");
    cout << res3 << endl;

    string res4 = s.multiply("123","456");
    cout << res4 << endl;

    vector<string> a = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res5 = s.groupAnagrams(a);
    for(int i = 0; i < res5.size(); i++){
        for(int j = 0; j < res5[i].size(); j++){
            cout << res5[i][j] << " ";
        }
        cout << endl;
    }

    string res6 = s.addBinary("1010", "1011");
    cout << res6 << endl;
}