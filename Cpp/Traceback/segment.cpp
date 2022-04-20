#include "segment.h"

void _restoreIpAddresses(string s, vector<string>& res, vector<string>& path, int idx){
    int n = s.size();
    if(n > 12 || n < 4){
        return;
    }
    if(path.size() > 4){
        return;
    }
    if(idx == n && path.size() == 4){
        string tmp = "";
        for(int i = 0; i < path.size(); i++){
            tmp += path[i];
            if(i != path.size() - 1){
                tmp += '.';
            }
        }
        res.push_back(tmp);
    }

    for(int i = idx; i < min(idx + 3, n); i++){
        string x = s.substr(idx, i - idx + 1);
        if(x.size() > 1 && x[0] == '0'){
            continue;
        }
        int x_val = stoi(x);
        if(!(x_val >=0 && x_val <= 255)){
            continue;
        }
        path.push_back(x);
        _restoreIpAddresses(s, res, path, i+1);
        path.pop_back();
    }
}
vector<string> Segment::restoreIpAddresses(string s){
    vector<string> res;
    vector<string> path;
    _restoreIpAddresses(s, res, path, 0);
    return res;
}

bool _ispalindrome(string s){
    int n = s.size();
    for(int i = 0; i < n / 2; i++){
        if(s[i] != s[n-i-1]){
            return false;
        }    
    }
    return true;
}
void _partition(string s, vector<vector<string>>& res, vector<string>& path, int idx){
    int n = s.size();
    if(idx == n){
        res.push_back(path);
        return;
    }

    for(int i = idx; i < n; i++){
        string tmp = s.substr(idx, i - idx + 1);
        if(_ispalindrome(tmp)){
            path.push_back(tmp);
            _partition(s, res, path, i + 1);
            path.pop_back();
        }
    }
}
vector<vector<string>> Segment::partition(string s){
    vector<vector<string>> res;
    vector<string> path;
    _partition(s, res, path, 0);
    return res;
}

void _wordBreak(string s, vector<string>& wordDict, vector<string>& res, vector<string>& path, int idx){
    int n = s.size();
    if(idx == n){
        string tmp = "";
        for(int i = 0; i < path.size(); i++){
            tmp += path[i];
            if(i != path.size() - 1){
                tmp += ' ';
            }
        }
        res.push_back(tmp);
        return;
    }

    for(int i = idx; i < n; i++){
        string x = s.substr(idx, i -idx + 1);
        if(find(wordDict.begin(), wordDict.end(), x) != wordDict.end()){
            path.push_back(x);
            _wordBreak(s, wordDict, res, path, i + 1);
            path.pop_back();
        } 
    }

}
vector<string> Segment::wordBreak(string s, vector<string>& wordDict){
    vector<string> res; 
    vector<string> path;
    _wordBreak(s, wordDict, res, path, 0);
    return res;
}