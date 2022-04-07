#include <iostream>
#include <vector>
using namespace std;
/* 移除数组中的指定值，最后返回长度。 */
class Solution {
public:
    /* 写法1 遍历O(n^2) 重点：由于用原数组操作，故要关注size的变化。易错点：移动idx后要--，size也要-- */
    int removeElement(vector<int>& nums, int val){
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (nums[i] == val) {
                for (int j = i; j < size - 1; j++) {    /* (size-1)是保证最后一位不再去找后一位的数字 */
                    nums[j] = nums[j + 1];
                }
                i--;
                size--;
            }
        }
        return size;
    }
    /* 写法2 主从关系--双指针法O(n) 重点：一个指针奋勇向前（保持遍历），一个指针牵制敌军（符合条件才会向前） */
    int removeElement1(vector<int>& nums, int val){
        int slowidx = 0;
        for(int fastidx = 0; fastidx < nums.size(); fastidx++){
            if(nums[fastidx] != val){
                nums[slowidx++] = nums[fastidx];
            }
        }
        return slowidx;
    }
};

int main()
{
    vector<int> nums = { 3,2,2,3 };
    int targets = 2;
    int res = -1;
    Solution s = Solution();
    res = s.removeElement1(nums, targets);
    cout << "res=" << res << endl;
}