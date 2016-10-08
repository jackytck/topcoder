// BEGIN CUT HERE
// PROBLEM STATEMENT
// An electronics manufacturer has called you in to make a program to decode resistor color codes.  You are given a vector <string> code containing three elements corresponding to the first three color bands on a resistor.  Return the # of Ohms the resistor represents.
The first two bands of resistors represent the value, while the third is a multiplier, as shown in the following chart:

Color:      Value:       Multiplier:

black         0                   1
brown         1                  10
red           2                 100
orange        3               1,000
yellow        4              10,000
green         5             100,000
blue          6           1,000,000
violet        7          10,000,000
grey          8         100,000,000
white         9       1,000,000,000

For example if you are given { "yellow", "violet", "red" }, you would return 4700.

DEFINITION
Class:ColorCode
Method:getOhms
Parameters:vector <string>
Returns:long long
Method signature:long long getOhms(vector <string> code)


NOTES
-Actual resistors can have a 4th and even a 5th band representing the tolerance, and the amount the value might change in 1,000 hours of use, respectively, but for our purposes we will only deal with the first three bands.


CONSTRAINTS
-code consists of 3 elements each containing one of the color words above, all in lower case.


EXAMPLES

0)
{ "yellow", "violet", "red" }

Returns: 4700

The example from the problem statement.

1)
{ "orange", "red", "blue" }

Returns: 32000000

2)
{ "white", "white", "white" }

Returns: 99000000000

The maximum possible.

// END CUT HERE
#line 60 "ColorCode.cxx"
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define sz size()
#define PB push_back
#define clr(x) memset(x, 0, sizeof(x))
#define forn(i,n) for(__typeof(n) i = 0; i < (n); i++)
#define ford(i,n) for(int i = (n) - 1; i >= 0; i--)
#define forv(i,v) forn(i, v.sz)
#define For(i, st, en) for(__typeof(en) i = (st); i < (en); i++)

using namespace std;

class ColorCode {
	public:
		long long getOhms(vector <string> code) 
		{		
			string color[] = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white"};
			return ((find(color, color+10, code[0])-color)*10+(find(color, color+10, code[1])-color))*pow(10.0, find(color, color+10, code[2])-color);
		}
};
