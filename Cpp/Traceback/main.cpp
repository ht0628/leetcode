#include "combination.h"
#include "permute.h"
#include "subset.h"
#include "segment.h"
#include "chessboard.h"

int main()
{
    Combination* com = new Combination();
    Permute* per = new Permute();
    Subset* sub = new Subset();
    Segment* seg = new Segment();
    Chessboard* chess = new Chessboard();

    cout << "/* 17.电话号码的组合 */" << endl;   
    vector<string> vec1_1 = com->letterCombinations("23");
    printContrainer(vec1_1);

    cout << "/* 77.组合 */" << endl;
    vector<vector<int>> vec1_2 = com->combine(4,2);
    for(int i = 0; i < vec1_2.size(); i++){
        printContrainer(vec1_2[i]);
    } 

    cout << "/* 39.组合总和 */" << endl;
    vector<int> vec1_3 = {2,3,6,7};
    vector<vector<int>> vec1_4 = com->combinationSum(vec1_3, 7);
    for(int i = 0; i < vec1_4.size(); i++){
        printContrainer(vec1_4[i]);
    }  

    cout << "/* 40.组合总和II */" << endl;
    vector<int> vec1_5 = {10,1,2,7,6,1,5};
    vector<vector<int>> vec1_6 = com->combinationSum2(vec1_5, 8);
    for(int i = 0; i < vec1_6.size(); i++){
        printContrainer(vec1_6[i]);
    }

    cout << "/* 216. 组合总和 III */" << endl;
    vector<vector<int>> vec1_7 = com->combinationSum3(3, 7);
    for(int i = 0; i < vec1_7.size(); i++){
        printContrainer(vec1_7[i]);
    }

    cout << "/* 22.括号生成 */" << endl;
    vector<string> vec1_8 = com->generateParenthesis(3);
    printContrainer(vec1_8);

    cout << "/* 46.全排列 */" << endl;
    vector<int> vec2_1 = {1,2,3};
    vector<vector<int>> vec2_2 = per->permute(vec2_1);
    for(int i = 0; i < vec2_2.size(); i++){
        printContrainer(vec2_2[i]);
    }

    cout << "/* 47.全排列II */" << endl;
    vector<int> vec2_3 = {1,1,2};
    vector<vector<int>> vec2_4 = per->permuteUnique(vec2_3);
    for(int i = 0; i < vec2_4.size(); i++){
        printContrainer(vec2_4[i]);
    }

    cout << "/* 78.子集 */" << endl;
    vector<int> vec3_1 = {1,2,3};
    vector<vector<int>> vec3_2 = sub->subsets(vec3_1);
    for(int i = 0; i < vec3_2.size(); i++){
        printContrainer(vec3_2[i]);
    }

    cout << "/* 90.子集II */" << endl;
    vector<int> vec3_3 = {1,2,2};
    vector<vector<int>> vec3_4 = sub->subsetsWithDup(vec3_3);
    for(int i = 0; i < vec3_4.size(); i++){
        printContrainer(vec3_4[i]);
    }

    cout << "/* 93.复原 IP 地址 */" << endl;
    string s4_1 = "25525511135";
    vector<string> vec4_1 = seg->restoreIpAddresses(s4_1);
    printContrainer(vec4_1);

    cout << "/* 131.分割回文串 */" << endl;
    string s4_2 = "aab";
    vector<vector<string>> vec4_2 = seg->partition(s4_2);
    for(int i = 0; i < vec4_2.size(); i++){
        printContrainer(vec4_2[i]);
    }

    cout << "/* 140. 单词拆分 II */" << endl;
    vector<string> dict = {"cat","cats","and","sand","dog"};
    vector<string> vec4_3 = seg->wordBreak("catsanddog", dict);
    printContrainer(vec4_3);

    cout << "/* 51.N皇后 */" << endl;
    vector<vector<string>> vec4_4 = chess->solveNQueens(4);
    for(int i = 0; i < vec4_4.size(); i++){
        printContrainer(vec4_4[i]);
    }

    cout << "/* 52.N皇后II */" << endl;
    int n4_5 = chess->totalNQueens(4);
    cout << n4_5 << endl;

    cout << "/* 79. 单词搜索 */" << endl;
    vector<vector<char>> vec5_1 = {{'A','A','A','A','A','A'},{'A','A','A','A','A','A'},
                                    {'A','A','A','A','A','A'},{'A','A','A','A','A','A'},
                                    {'A','A','A','A','A','A'},{'A','A','A','A','A','A'}};
    bool b5_1 = chess->exist(vec5_1,"AAAAAAAAAAAAAAB");
    cout << b5_1 << endl;

    cout << "/* 212.单词搜索 II */" << endl;
    vector<vector<char>> vec5_2 = {{'o','a','a','n'},{'e','t','a','e'},
                                    {'i','h','k','r'},{'i','f','l','v'}};
    vector<string> vec5_3 = {"oath","pea","eat","rain"};
    // vector<vector<char>> board = {{'a'}};
    // vector<string> words = {"a"};
    vector<string> vec5_4 = chess->findWords(vec5_2, vec5_3);
    printContrainer(vec5_4);

}