/*
===============================================================================
Author : chang de (41075901h@gapps.ntnu.edu.tw)
FileName : P.331-1__彭昶得_41075901h.cpp
-------------------------------------------------------------------------------
Description of the problem :
Write a program that converts from 24-hour notation to 12-hour notation.
For example, it should convert 14:25 to 2:25 PM. The input is given as two integers. There should be at least three
functions, one for input, one to do the conversion, and one for output. Record the AM/PM information as a value of type
char, 'A' for AM and 'P' for PM. Thus, the function for doing the conversions will have a call-by-reference formal
parameter of type char to record whether it is AM or PM. (The function will have other parameters as well.) Include a
loop that lets the user repeat this computation for new input values again and again until the user says he or she wants
to end the program.
================================================================================
*/

#include <iomanip>
#include <iostream>
#define PI 3.14
using namespace std;

double_t calVolume(double_t width, double_t height, double_t length);
double_t calVolume(double_t radius, double_t height);
double_t calVolume(double_t radius);

int main()
{
    int32_t ops;
    cerr << "What do you want to calculate? \n \
    1. The volume of a box\n \
    2. The volume of a sphere\n \
    3. The volume of a cylinder?\n";
    cin >> ops;
    cout << fixed << setprecision(2);
    if (ops == 1)
    {
        double_t l, w, h;
        cerr << "Please input the length, width, and height.\n";
        cin >> l >> w >> h;
        cout << calVolume(l, w, h);
    }
    else if (ops == 2)
    {
        double_t r;
        cerr << "Please input the radius.\n";
        cin >> r;
        cout << calVolume(r);
    }
    else if (ops == 3)
    {
        double_t r, h;
        cerr << "Please input the radius and height.\n";
        cin >> r >> h;
        cout << calVolume(r, h);
    }
    else
    {
        cerr << "Enter 1, 2, or 3. Do not input anything else = =\n";
    }
}

double_t calVolume(double_t width, double_t height, double_t length)
{
    return width * height * length;
}

double_t calVolume(double_t radius, double_t height)
{
    return PI * radius * radius * height;
}

double_t calVolume(double_t radius)
{
    return 4.0 / 3.0 * PI * radius * radius * radius;
}