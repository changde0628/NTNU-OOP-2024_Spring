# 112-2物件導向程式設計 第一次程式

41075901h_彭昶得

## Before Test

對於後面的所有程式碼，我都使用相同的Makefile進行編譯與測試，並且自行產生一些測資進行測試。

- 編譯器 ： g++
- C++版本 ： C++14
- 編譯指令 ： g++ fileName.cpp -std=c++14 -Wall -o main

### 檔案結構

![image-20240327140459767](/Users/pengchangde/Desktop/CodeSpace/BasicC/OOP/report.assets/image-20240327140459767.png)

<div style="page-break-after: always;"></div>

### Makefile

```makefile
CXX = g++
CXXFLAGS = -std=c++14 -Wall
TARGET = main
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
TEST_FILES = $(wildcard pattern/*.in)
TOTAL_TESTS = $(words $(TEST_FILES))
all: $(TARGET)
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
test:
	@$(eval PASSED_TESTS=0)
	@echo "====== Testing Begins ======"
	@for file in $(TEST_FILES); do \
		echo "\n🔍 Testing Case: $$file"; \
		./$(TARGET) < $$file > $${file%.in}.result; \
		if diff -u $${file%.in}.out $${file%.in}.result > /dev/null; then \
			echo "✅ Test: Pass"; \
			PASSED_TESTS=$$((PASSED_TESTS + 1)); \
		else \
			echo "❌ Test: Fail"; \
		fi; \
	done; \
	echo "\n====== Test Summary ======"; \
	echo "📊 Total Passed: $$PASSED_TESTS / $(TOTAL_TESTS)"; \
	echo "=========================="; \
	if [ "$$PASSED_TESTS" -eq "$(TOTAL_TESTS)" ]; then \
		cat art.txt; \
	fi
clean:
	rm -f $(OBJS) $(TARGET) $(TEST_FILES:.in=.result)
.PHONY: all clean test
```

<div style="page-break-after: always;"></div>

## P.141-13

### 測試結果：

```
Test 1 :
input :
1 1 2 2
output :
Slope is : 1
Equation is : y = 1x + 0

Test 2 :
input :
-1.40625 0 0 4.5
output :
Slope is : 3.2
Equation is : y = 3.2x + 4.5

Test 3 :
input :
-1.40625 0 0 4.5
output :
Slope is : 3.2
Equation is : y = 3.2x + 4.5

Test 4 :
input :
-0.45 0 0 4.5
output :
Slope is : 10
Equation is : y = 10x + 4.5

Test 5 :
input :
-0.5012 0 0 50.12
output :
Slope is : 100
Equation is : y = 100x + 50.12
```

<div style="page-break-after: always;"></div>

```c++
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
```

<div style="page-break-after: always;"></div>

## P.142-16

### 測試結果：

```
Test 1 :
input :
1 1 1
output :
You should get a flat top

Test 2 :
input :
1 1 0
output :
You should get a pompadour

Test 3 :
input :
1 0
output :
You should get a mohawk

Test 4 :
input :
0 1
output :
You should get a mohawk

Test 5 :
input :
0 0 1
output :
You should go with bangs

Test 6 :
input :
0 0 0
output :
You should get a bob
```

<div style="page-break-after: always;"></div>

```c++
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
```

<div style="page-break-after: always;"></div>

## P.209-8

### 測試結果：

```
Test 1 :
input :
1
output :
2.66667

Test 2 :
input :
2
output :
3.46667

Test 3 :
input :
5
output :
2.97605

Test 4 :
input :
20
output :
3.18918

Test 5 :
input :
50
output :
3.1612

Test 6 :
input :
100
output :
3.15149
```

<div style="page-break-after: always;"></div>

```c++
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
```

<div style="page-break-after: always;"></div>

## P.279-2

### 測試結果：

```
Test 1 :
input :
1
50.2 39.4 92.6
output :
183151.69

Test 2 :
input :
1
100 200 300
output :
6000000.00

Test 3 :
input :
2
10
output :
4186.67

Test 4 :
input :
2
87
output :
2756932.56

Test 5 :
input :
3
10 87
output :
27318.00

Test 6 :
input :
3
64 8964
output :
115289948.16
```

<div style="page-break-after: always;"></div>

```c++
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
```

<div style="page-break-after: always;"></div>

## P.331-1

### 測試結果：

```
Test 1 :
input :
0 0
output :
00:00 AM

Test 2 :
input :
12 0
output :
12:00 PM

Test 3 :
input :
5 3
output :
05:03 AM

Test 4 :
input :
18 19
output :
06:19 PM

Test 5 :
input :
15 2
output :
03:02 PM

Test 6 :
input :
1 1
output :
01:01 AM
```

<div style="page-break-after: always;"></div>

```c++
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
#include <string>
using namespace std;

bool inputData(int16_t &hour, int16_t &min);
char convertTo12(int16_t &hour, const int16_t &min);
void displayAnswer(const int16_t &hour, const int16_t &min, const char Am_or_Pm);

int main()
{
    int16_t hour, min;
    char Am_or_Pm;
    while (inputData(hour, min))
    {
        Am_or_Pm = convertTo12(hour, min);
        displayAnswer(hour, min, Am_or_Pm);
    }
    return 0;
}

bool inputData(int16_t &hour, int16_t &min)
{
    cin >> hour >> min;
    if (hour <= 24 && hour >= 0 && min < 60 && min >= 0)
        return 1;
    else
        return 0;
}

char convertTo12(int16_t &hour, const int16_t &min)
{
    char Am_or_Pm;
    if (hour >= 12)
        Am_or_Pm = 'P';
    else
        Am_or_Pm = 'A';
    hour = (hour > 12) ? (hour % 12) : (hour);
    return Am_or_Pm;
}

void displayAnswer(const int16_t &hour, const int16_t &min, char Am_or_Pm)
{
    cout << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << min << " " << Am_or_Pm << "M" << '\n';
}
```

<div style="page-break-after: always;"></div>

## P.335-9

### 測試結果：

在程式中，我實現了電腦會透過Binary Search最佳化猜測玩家的數字，在範圍$0-100$中，最多僅需要$log_2(100)+1$次就可以猜測到玩家數字。

以下是測試的截圖：

- 玩家贏：

<img src="/Users/pengchangde/Desktop/CodeSpace/BasicC/OOP/report.assets/image-20240327140258424.png" alt="image-20240327140258424" style="zoom:67%;" />

- 電腦贏：

<img src="/Users/pengchangde/Desktop/CodeSpace/BasicC/OOP/report.assets/image-20240327140142322.png" alt="image-20240327140142322" style="zoom:67%;" />

<div style="page-break-after: always;"></div>

```c++
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
```