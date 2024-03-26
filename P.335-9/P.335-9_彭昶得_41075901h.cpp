/*
===============================================================================
Author : chang de (41075901h@gapps.ntnu.edu.tw)
FileName : P.335-9_彭昶得_41075901h.cpp
-------------------------------------------------------------------------------
Description of the problem :


================================================================================
*/

#include <string>
#include <random>
#include <iostream>
using namespace std;

int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 100);

    int32_t computerRandomNum = dis(gen);
    int32_t userRandomNum = 0;

    int32_t computerGuessUpper = 100;
    int32_t computerGuessLower = 0;

    int32_t tmpGuessNum = 0;

    cerr << "please enter your secret number >> ";
    cin >> userRandomNum;
    while (true)
    {
        cerr << "your turn, guess a number : ";
        cin >> tmpGuessNum;
        if (tmpGuessNum == computerRandomNum)
        {
            cerr << "guess hit, you win !\n";
            break;
        }
        else
        {
            if (tmpGuessNum > computerRandomNum)
                cerr << "The guess is too high\n";
            else
                cerr << "The guess is too low\n";
        }
        tmpGuessNum = (computerGuessLower + computerGuessUpper) / 2;
        cerr << "Now, it is my turn. I guess : " << tmpGuessNum << '\n';
        if (tmpGuessNum == userRandomNum)
        {
            cerr << "guess hit, you lose !\n";
            break;
        }
        else
        {
            if (tmpGuessNum > userRandomNum)
            {
                cerr << "The guess is too high\n";
                computerGuessUpper = tmpGuessNum;
            }
            else
            {
                cerr << "The guess is too low\n";
                computerGuessLower = tmpGuessNum + 1;
            }
        }
    }
    return 0;
}