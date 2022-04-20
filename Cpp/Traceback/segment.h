#pragma once
#ifndef _SEGMENT_H
#define _SEGMENT_H
#include "common.h"

class Segment
{
    public:
        /* 93.复原 IP 地址 */
        vector<string> restoreIpAddresses(string s);
        /* 131.分割回文串 */
        vector<vector<string>> partition(string s);
        /* 140. 单词拆分 II */
        vector<string> wordBreak(string s, vector<string>& wordDict);


};

#endif