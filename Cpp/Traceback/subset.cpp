#include "subset.h"

void _subsets(vector<int>& nums, vector<vector<int>>& res, vector<int>& path, int idx){
    res.push_back(path);
    for(int i = idx; i < nums.size(); i++){
        path.push_back(nums[i]);
        _subsets(nums, res, path, i + 1);
        path.pop_back();
    }
}
vector<vector<int>> Subset::subsets(vector<int>& nums){
    vector<vector<int>> res;
    vector<int> path;
    _subsets(nums, res, path, 0);
    return res;
}

void _subsetsWithDup(vector<int>& nums, vector<vector<int>>& res, vector<int>& path, int idx){
    res.push_back(path);
    for(int i = idx; i < nums.size(); i++){
        if(i > idx && nums[i] == nums[i - 1]){
            continue;
        }
        path.push_back(nums[i]);
        _subsetsWithDup(nums, res, path, i + 1);
        path.pop_back();
    }
}
vector<vector<int>> Subset::subsetsWithDup(vector<int>& nums){
    vector<vector<int>> res;
    vector<int> path;
    sort(nums.begin(), nums.end());
    _subsetsWithDup(nums, res, path, 0);
    return res;
}