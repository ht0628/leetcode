#include "sequence.h"
#include "substr.h"


int main()
{
    Sequence* seq = new Sequence();
    Substr* substr = new Substr();

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
    return 0;
}