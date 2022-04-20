#pragma once
#ifndef _SEQUENCE_H
#define _SEQUENCE_H
#include "common.h"

class Sequence
{
    public:
        int fib(int n);
        int fib1(int n);
        vector<vector<int>> generate(int numRows);
        vector<int> getRow(int rowIndex);
        vector<int> getRow1(int rowIndex);
};

#endif