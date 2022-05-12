#include "sequence.h"
#include "substr.h"
#include "subseq.h"
#include "subarr.h"

int main()
{
    Sequence* seq = new Sequence();
    Substr* substr = new Substr();
    Subseq* subseq = new Subseq();
    Subarr* subarr = new Subarr();

    int val1_1 = seq->fib(3);
    cout << val1_1 << endl;
    vector<vector<int>> vec1_1 = seq->generate(5);
    for(int i = 0; i < vec1_1.size(); i++){
        printContrainer(vec1_1[i]);
    }


    string s2_1 = substr->longestPalindrome("babad");
    cout << s2_1 << endl;
    vector<vector<string>> vec2_1 = substr->partition("aab");
    for(int i = 0; i < vec2_1.size(); i++){
        printContrainer(vec2_1[i]);
    }

    vector<string> vec2_2 = {"leet", "code"};
    bool flag2_2 = substr->wordBreak("leetcode", vec2_2);
    cout << flag2_2 << endl;

    bool flag2_3 = substr->isMatch("aab", "c*a*b");
    bool flage2_4 = substr->isMatch2("mississippi", "mis*is*p*");

    int val2_5 = substr->longestValidParentheses(")()())");
    cout << "val2_5 = " << val2_5 << endl;

    int val3_1 = subseq->numDistinct("rabbbit","rabit");
    
    vector<int> vec3_2 = {0,1,0,3,2,3};
    int val3_2 = subseq->lengthOfLIS(vec3_2);

    vector<int> vec3_3 = {7,7,7,7,7};
    int val3_3 = subseq->numberOfArithmeticSlices(vec3_3);
    cout << val3_3 << endl;

    vector<int> vec3_4 = {1,3,5,4,7};
    int val3_4 = subseq->findNumberOfLIS(vec3_4);
    cout << val3_4 << endl;

    int val3_5 = subseq->longestCommonSubsequence("bl","yby");
    cout << val3_5 << endl;

    vector<int> nums4_1 = {-2,1,-3,4,-1,2,1,-5,4};
    int val4_1 = subarr->maxSubArray(nums4_1);
    cout << val4_1 << endl;
    return 0;
}