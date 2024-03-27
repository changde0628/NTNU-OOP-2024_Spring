/*
===============================================================================
Author : chang de (41075901h@gapps.ntnu.edu.tw)
FileName : P.141-13_彭昶得_41075901h.cpp
-------------------------------------------------------------------------------
Description of the problem :
Write a program to calculate the slope between two points x, y, and x,, ½2* The points should be entered as four double
values in the order x1, y1, x2, and y2. The formula to calculate the slope, m, between two points is
$m=\frac{y_2-y_1}{x_2-x_1}$ Output the calculated slope value. Use this value to output the equation of the line in the
form $y = mx + c$ You can calculate the value of c from one of the pair of points entered as input.
================================================================================
*/

#include <iostream>
using namespace std;

int main()
{
    double x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double m = (y2 - y1) / (x2 - x1);
    double c = y2 - m * x2;
    cout << "Slope is : " << m << endl;
    cout << "Equation is : "
         << "y = " << m << "x + " << c << endl;
    return 0;
}