/*
===============================================================================
Author : chang de (41075901h@gapps.ntnu.edu.tw)
FileName : P.209-8_彭昶得_41075901h.cpp
-------------------------------------------------------------------------------
Description of the problem :
The following flowchart contains a series of questions to determine what kind
of haircut to get. Write a program that asks the questions to the user and
outputs the recommended haircut.
================================================================================
*/

#include <iostream>
using namespace std;

int main()
{
    int32_t n;
    while (cin >> n)
    {
        double answer = 0.0;
        for (int32_t i = 0; i <= n; ++i)
        {
            if ((i & 1) == 0)
                answer += (1 / (2 * (double)i + 1));
            else
                answer -= (1 / (2 * (double)i + 1));
        }
        cout << 4.0 * answer;
    }
    return 0;
}