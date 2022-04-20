#include "combination.h"

void _letterCombinations(string digits, vector<string>& res, string& path, int idx, unordered_map<char, string> map){
    if(digits == ""){
        return; 
    }
    if(path.size() == digits.size()){
        res.push_back(path);
        return;
    }
    string s = map[digits[idx]];
    for(char c:s){
        path.push_back(c);
        _letterCombinations(digits, res, path, idx + 1, map);
        path.pop_back();
    }
}
vector<string> Combination::letterCombinations(string digits){
    unordered_map<char, string> table{
        {'0', " "}, {'1',"*"}, {'2', "abc"},
        {'3',"def"}, {'4',"ghi"}, {'5',"jkl"},
        {'6',"mno"}, {'7',"pqrs"},{'8',"tuv"},
        {'9',"wxyz"}
    };
    vector<string> res;
    string path;
    _letterCombinations(digits, res, path, 0, table);
    return res;
}

void _combine(int n, int k, vector<vector<int>>& res, vector<int>& path, int idx){
    if(path.size() == k){
        res.push_back(path);
        return;
    }

    for(int i = idx; i <= n - (k - path.size()) + 1; i++){
        path.push_back(i);
        _combine(n, k, res, path, i + 1);
        path.pop_back();
    }
    
}
vector<vector<int>> Combination::combine(int n, int k){
    vector<vector<int>> res;
    vector<int> path;
    int idx = 1;
    _combine(n, k, res, path, idx);
    return res;
}

void _combinationSum(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& path, int idx){
    if(target == 0){
        res.push_back(path);
        return;
    }
    else if(target < 0){
        return;
    }
    for(int i = idx; i <= candidates.size() - 1; i++){
        path.push_back(candidates[i]);
        _combinationSum(candidates, target - candidates[i], res, path, i);
        path.pop_back();
    }
}
vector<vector<int>> Combination::combinationSum(vector<int>& candidates, int target){
    vector<vector<int>> res;
    vector<int> path;

    _combinationSum(candidates, target, res, path, 0);

    return res;
}

void _combinationSum2(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& path, int idx){
    if(target < 0){
        return;
    }
    if(target == 0){
        res.push_back(path);
        return;
    }

    for(int i = idx; i <= candidates.size() - 1; i++){
        if(i > idx && candidates[i] == candidates[i - 1]){
            continue;
        }
        path.push_back(candidates[i]);
        _combinationSum2(candidates, target - candidates[i], res, path, i + 1);
        path.pop_back();
    }
}
vector<vector<int>> Combination::combinationSum2(vector<int>& candidates, int target){
    vector<vector<int>> res;
    vector<int> path;
    sort(candidates.begin(), candidates.end());
    _combinationSum2(candidates, target, res, path, 0);
    return res;
}

void _combinationSum3(int k, int n, vector<vector<int>>& res, vector<int>& path, int idx){
    if(n < 0){
        return;
    }
    if(path.size() == k){
        if(n == 0){
            res.push_back(path);
        }
        return;
    }

    for(int i = idx; i <= 9 - (k - path.size()) + 1; i++){
        path.push_back(i);
        _combinationSum3(k, n - i, res, path, i + 1);
        path.pop_back();
    }
}
vector<vector<int>> Combination::combinationSum3(int k, int n){
    vector<vector<int>> res;
    vector<int> path;
    _combinationSum3(k, n, res, path, 1);
    return res;
}

void _generateParenthesis(int n, vector<string>& res, string s, int left, int right){
    if(right > left || left > n){
        return;
    }
    if(s.size() ==  2 * n){
        res.push_back(s);
        return;
    }
    _generateParenthesis(n, res, s + '(', left + 1, right);
    _generateParenthesis(n, res, s + ')', left, right + 1);
}
vector<string> Combination::generateParenthesis(int n){
    vector<string> res;
    string s = "";
    _generateParenthesis(n, res, s, 0, 0);
    return res;
}

