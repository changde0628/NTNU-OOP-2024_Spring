/*
===============================================================================
Author : chang de (41075901h@gapps.ntnu.edu.tw)
FileName : P.331-1__彭昶得_41075901h.cpp
-------------------------------------------------------------------------------
Description of the problem :


================================================================================
*/

#include <iomanip>
#include <string>
#include <iostream>
using namespace std;

bool inputData(int16_t &hour, int16_t &min);
char convertTo12(int16_t &hour, const int16_t &min);
void displayAnswer(const int16_t &hour, const int16_t &min, const char Am_or_Pm);

int main()
{
    int16_t hour,min;
    char Am_or_Pm;
    while(inputData(hour,min))
    {
        Am_or_Pm = convertTo12(hour,min);
        displayAnswer(hour,min,Am_or_Pm);
    }
    return 0;
}

bool inputData(int16_t &hour, int16_t &min)
{
    cin >> hour >> min;
    if(hour<=24 && hour >= 0 && min < 60 && min >= 0)
        return 1;
    else
        return 0;
}

char convertTo12(int16_t &hour, const int16_t &min)
{
    char Am_or_Pm;
    if(hour >= 12)
        Am_or_Pm = 'P';
    else
        Am_or_Pm = 'A';
    hour = (hour > 12) ? (hour % 12) : (hour);
    return Am_or_Pm;
}

void displayAnswer(const int16_t &hour, const int16_t &min, char Am_or_Pm)
{
    cout << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << min <<  " " << Am_or_Pm << "M" << '\n';
} 