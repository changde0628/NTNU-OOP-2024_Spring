/*
===============================================================================
Author : chang de (41075901h@gapps.ntnu.edu.tw)
FileName : P.335-9_彭昶得_41075901h.cpp
-------------------------------------------------------------------------------
Description of the problem :
Write a program to play a simple number-guessing game against a computer opponent. The rules of the game are as follows:
1. The computer randomly selects a secret number between 0 and 100.
2. The user enters a number between 0 and 100 as their secret number.
3. The computer will then attempt to guess the user's number. This guessed number should be printed to the screen and if
it is less than the user's secret number, the program should print, "The guess is too low"; if the guess is greater than
the user's secret number, it should print "The guess is too high".
4. The user will then attempt to guess the computer's secret number. This guessed number should be printed to the screen
and if it is less than the computer's secret number, the program should print, "The guess is too low"; if the guess is
above the user's secret number, it should print "The guess is too high"
5. Repeat steps 3 and 4 until either the computer or the user correctly guesses the other's secret number.
================================================================================
*/

#include <iostream>
#include <random>
#include <string>
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