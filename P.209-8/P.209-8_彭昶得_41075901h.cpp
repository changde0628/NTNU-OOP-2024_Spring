/*
===============================================================================
Author : chang de (41075901h@gapps.ntnu.edu.tw)
FileName : P.209-8_彭昶得_41075901h.cpp
-------------------------------------------------------------------------------
Description of the problem :
An approximate value of pi can be calculated using the series given below:
pi = 4 [ 1 - 1/3 + 1/5 - 1/7 + 1/9... + ( (-1)^n ) / (2n + 1) ]
Write a C++ program to calculate the approximate value of pi using this series. The program takes an input n that
determines the number of terms in the approximation of the value of pi and outputs the approximation. Include a loop
that allows the user to repeat this calculation for new values n until the user says she or he wants to end the program.
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