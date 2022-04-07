#include <iostream>
#include <vector>
using namespace std;
/* �Ƴ������е�ָ��ֵ����󷵻س��ȡ� */
class Solution {
public:
    /* д��1 ����O(n^2) �ص㣺������ԭ�����������Ҫ��עsize�ı仯���״�㣺�ƶ�idx��Ҫ--��sizeҲҪ-- */
    int removeElement(vector<int>& nums, int val){
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (nums[i] == val) {
                for (int j = i; j < size - 1; j++) {    /* (size-1)�Ǳ�֤���һλ����ȥ�Һ�һλ������ */
                    nums[j] = nums[j + 1];
                }
                i--;
                size--;
            }
        }
        return size;
    }
    /* д��2 ���ӹ�ϵ--˫ָ�뷨O(n) �ص㣺һ��ָ�������ǰ�����ֱ�������һ��ָ��ǣ�Ƶо������������Ż���ǰ�� */
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