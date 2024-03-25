/*
===============================================================================
Author : chang de (41075901h@gapps.ntnu.edu.tw)
FileName : P.142-16_彭昶得_41075901h.cpp
-------------------------------------------------------------------------------
Description of the problem :
The following flowchart contains a series of questions to determine what kind
of haircut to get. Write a program that asks the questions to the user and
outputs the recommended haircut.
================================================================================
*/

#include <iostream>
using namespace std;

void printMessage(string ref1, string ref2)
{
    cerr << "Input 1 or 0 to select an option.";
    cerr << "1. " << ref1 << "0. " << ref2 << endl;
}

int main()
{
    bool answer;
    printMessage("Male", "Female");
    cin >> answer;
    if (answer == 1)
    {
        printMessage("Superhero", "Super villain");
        cin >> answer;
        if (answer == 1)
        {
            printMessage("Steak", "Sushi");
            cin >> answer;
            if (answer == 1)
                cout << "You should get a flat top";
            else
                cout << "You should get a pompadour";
        }
        else
            cout << "You should get a mohawk";
    }
    else
    {
        printMessage("Superhero", "Super villain");
        cin >> answer;
        if (answer == 1)
            cout << "You should get a mohawk";
        else
        {
            printMessage("Anime", "Sitcom");
            cin >> answer;
            if (answer == 1)
                cout << "You should go with bangs";
            else
                cout << "You should get a bob";
        }
    }
    return 0;
}