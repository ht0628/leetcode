#include <iostream>
#include <vector>
using namespace std;
/* 找出该数组中满足其和 ≥ target 的长度最小的连续子数组, 并返回其长度，若不存在则返回0*/
class Solution {
public:
    /* 解法1 暴力循环O(n2) */
    int minSubArrayLen(int target, vector<int>& nums) {
        int minlenth = nums.size() + 1;
        for(int i=0; i<nums.size(); i++){
            int sum = 0;
            for(int j=i; j<nums.size(); j++){
                sum += nums[j];
                if(sum >= target){
                    int lenth = j - i + 1;
                    if(lenth < minlenth){
                        minlenth = lenth;
                    }
                    break;
                }
            }
        }
        if(minlenth == nums.size() + 1){
            minlenth = 0;
        }
        return minlenth;
    }

     int minSubArrayLen1(int target, vector<int>& nums) {
        /* 写法2 快慢双指针，判断指针形成的窗口，满足条件之后移动慢指针 */
        int slowIdx = 0;
        int fastIdx = 0;
        int sum = 0;
        int minLenth = INT32_MAX;

        for(fastIdx=0; fastIdx<nums.size(); fastIdx++){
            sum += nums[fastIdx];
            while(sum>=target){
                int lenth = fastIdx - slowIdx + 1;
                minLenth = (minLenth<lenth)?minLenth:lenth;
                sum -= nums[slowIdx++];
            }
        }

        return (minLenth==INT32_MAX)?0:minLenth;
     }
};

int main()
{
    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;
    Solution s = Solution();
    int res = s.minSubArrayLen1(target, nums);
    printf("%d",res);
    
}