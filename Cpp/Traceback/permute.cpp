#include "permute.h"

void _permute(vector<int>& nums, vector<vector<int>>& res, vector<int>& path, vector<int>& visited){
    if(path.size() == nums.size()){
        res.push_back(path);
        return;
    }

    for(int i = 0; i < nums.size(); i++){
        if(visited[i] == 1){
            continue;
        }
        path.push_back(nums[i]);
        visited[i] = 1;
        _permute(nums, res, path, visited);
        visited[i] = 0;
        path.pop_back();
    }
}
vector<vector<int>> Permute::permute(vector<int>& nums){
    vector<vector<int>> res; 
    vector<int> path;
    vector<int> visited(nums.size(), 0);
    _permute(nums, res, path, visited);
    return res;
}

void _permuteUnique(vector<int>& nums, vector<vector<int>>& res, vector<int>& path, vector<int>& visited){
    if(path.size() == nums.size()){
        res.push_back(path);
        return;
    }

    for(int i = 0; i < nums.size(); i++){
        if(visited[i] == 1){
            continue;
        }
        if(i > 0 && nums[i] == nums[i-1] && visited[i-1] == 0){
            continue;
        }
        path.push_back(nums[i]);
        visited[i] = 1;
        _permuteUnique(nums, res, path, visited);
        visited[i] = 0;
        path.pop_back();
    }   
}
vector<vector<int>> Permute::permuteUnique(vector<int>& nums){
    vector<vector<int>> res; 
    vector<int> path;
    vector<int> visited(nums.size(), 0);
    sort(nums.begin(), nums.end());
    _permuteUnique(nums, res, path, visited);
    return res;
}