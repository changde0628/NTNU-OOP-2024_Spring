/*
===============================================================================
Author : chang de (41075901h@gapps.ntnu.edu.tw)
FileName : P.141-13_彭昶得_41075901h.cpp
-------------------------------------------------------------------------------
Description of the problem :
The following flowchart contains a series of questions to determine what kind of
haircut to get. Write a program that asks the questions to the user and outputs
the recommended haircut.
================================================================================
*/

#include <iostream>
using namespace std;

int main() {
  double x1, x2, y1, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  double m = (y2 - y1) / (x2 - x1);
  double c = y2 - m * x2;
  cout << "Slope is : " << m << endl;
  cout << "Equation is : "
       << "y = " << m << "x + " << c << endl;
  return 0;
}