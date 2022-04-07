#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
/* 平方之后再排序，范围排序后的vector */
class Solution {
public:
    /* 直观法 时间复杂度O(nlogn) */
    vector<int> sortedSquares(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            nums[i] *= nums[i];
        }
        sort(nums.begin(), nums.end()); //快速排序
        
        return nums;
    }
    
    /* 平等关系--双指针法 时间复杂度O(n) 重点：一前一后，双向奔赴 */
    vector<int> sortedSquares1(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        vector<int> res(nums.size(), 0);
        int k = res.size() - 1;
        while(i <= j){
            if(nums[i]*nums[i] < nums[j]*nums[j]){
                res[k--] = nums[j]*nums[j];
                j--;
            }
            else{
                res[k--] = nums[i]*nums[i];
                i++;
            }
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {-9,2,3,-4};
    Solution s = Solution();
    vector<int> res = s.sortedSquares1(nums);
    for(int i=0; i<res.size(); i++){
        printf("res[%d]=%d ",i,res[i]);
    }
    
}