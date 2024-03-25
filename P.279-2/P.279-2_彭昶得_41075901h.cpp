/*
===============================================================================
Author : chang de (41075901h@gapps.ntnu.edu.tw)
FileName : P.279-2_彭昶得_41075901h.cpp
-------------------------------------------------------------------------------
Description of the problem :
Write a program to calculate the volume of spheres, cylinders and boxes.
Your program should contain three functions, each called calVolume and returning a double.
The volumes should be calculated according to the following formulas:
The volume of a box is its width multiplied by its height multiplied by its length.
The volume of a sphere is $\frac{2}{3}\pi r^3$ where r is the radius of the sphere.
The volume of a cylinder is arth,where ris the radius of the cylinder and h is the height of the cylinder.
Define a global constant PI and set its valueto 3.14.
Your program should ask the user which shape's volume they want to calculate, and get the required information.
It should then call the correct cal cVolume function and output the volume to the screen.
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