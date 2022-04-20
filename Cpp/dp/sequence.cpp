#include "sequence.h"

int Sequence::fib(int n){
    vector<int> dp(n+1, 0);
    for(int i = 0; i < n + 1; i++){
        if(i <= 1)
            dp[i] = i;
        else
            dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
int Sequence::fib1(int n){
    if(n == 0 || n == 1){
        return n;
    }
    int pre = 0;
    int cur = 1;
    int res = 0;
    for(int i = 2; i <= n; i++){
        res = pre + cur;
        pre = cur;
        cur = res;
    }
    return res;
}

vector<vector<int>> Sequence::generate(int numRows){
    vector<vector<int>> res(numRows);
    for(int i = 0; i < numRows; i++){
        res[i].resize(i+1);
        res[i][0] = res[i][i] = 1;
        for(int j = 1; j < i; j++){
            res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
        }
    }
    return res;
}

vector<int> Sequence::getRow(int rowIndex){
    vector<vector<int>> dp(rowIndex + 1); 
    for(int i = 0; i < rowIndex + 1; i++){
        dp[i].resize(i+1);
        dp[i][0] = dp[i][i] = 1;
        for(int j = 1; j < i; j++){
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
    return dp[rowIndex];
}

vector<int> getRow1(int rowIndex){
    vector<int> cur(rowIndex + 1);
    for(int i = 0; i < rowIndex + 1; i++){
        cur[i] = 1;
        if(i > 1){
            int tmp = 1;
            for(int j = 1; j < i; j++){
                int newTmp = cur[j];
                cur[j] = tmp + cur[j];
                tmp = newTmp;
            }
        }
    }
    return cur;
}