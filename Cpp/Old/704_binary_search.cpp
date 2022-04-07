#include <iostream>
#include <vector>
using namespace std;
/*
在升序数组中查找一个值，成功返回idx，失败返回-1。
*/
class Solution {
public:
    /* 写法1 左闭右闭 */
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] > target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return -1;
    }
    /* 写法2 左闭右开 */
    int search1(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();/*右开所以要比真实长度大1*/
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] > target) {
                right = mid;    /*右开所以right可以直接取不要的mid*/
            }
            else {
                left = mid + 1;
            }
        }
        return -1;
    }
};


int main()
{
    vector<int> nums = { -1,0,3,5,9,12 };
    vector<int> targets = nums;
    int res = -1;
    Solution s = Solution();
    for (int i = 0; i < targets.size(); i++) {
        res = s.search1(nums, targets[i]);
        cout << "res=" << res << endl;
    }
}


