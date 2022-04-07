#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {

public:
    /* 76.最小覆盖子串 */
    string minWindow(string s, string t) {
        /* 滑窗左边界 */
        int l = 0;
        /* 辅助判断 */
        unordered_map<char, int> need;
        for(char c:t) need[c]++;
        int needCnt = t.size();
        /* 中间结果 */
        int start = 0;
        int size = INT_MAX;
        /* 最终结果 */
        string res = "";

        for(int i=0; i<s.size(); i++){
            /* 右指针开始循环 */
            if(need.find(s[i]) != need.end()){
                if (need[s[i]]>0)   needCnt--;
                need[s[i]]--;
            }  
            /* 左指针触发条件 */
            if(needCnt == 0){
                /* 1.循环吐出无效数据 */
                while(true){
                    /* 当存在该键但该键值为负数，那么也是无效数据 */
                    char c = s[l];
                    if(need.find(c) != need.end()){
                        if(need[c] < 0)  need[c]++;
                        else break;
                    }
                    l++;
                }
                /* 2.更新中间结果 */
                int tmpSize = i - l + 1;
                if(tmpSize < size){
                    start = l;
                    size = tmpSize;
                }
                /* 3.删除一个有效数据，寻找下一个滑窗。 */
                need[s[l]]++;
                needCnt++;
                l++;
            }
        }

        /* 计算最终结果 */
        res = (size == INT_MAX) ? "" : s.substr(start, size);
        return res;
    }

    /* 904.水果成篮 */
    int totalFruit(vector<int>& fruits) {
        /* 滑窗左边界 */
        int l=0;
        /* 辅助判断 */
        unordered_map<int,int> basket;
        /* 中间结果 */
        int len = 0;
        /* 最终结果 */
        int res = 0;

        for(int r=0; r<fruits.size(); r++){
            /* 右指针开始循环 */
            basket[fruits[r]]++;
            len++;

            while(basket.size()>2){
                basket[fruits[l]]--;
                if (basket[fruits[l]] == 0) basket.erase(fruits[l]);
                l++;
                len--;
            }
            /* 更新最终结果 */
            res = max(res,len);
        }    

        return res;
    }
};

int main()
{
    Solution s = Solution();
    string s1 = s.minWindow("ADOBECODEBANC","ABC");
    printf("%s\n",s1.c_str());
    vector<int> nums = {1,2,1};
    int res = s.totalFruit(nums);
    printf("%d\n",res);
    
}