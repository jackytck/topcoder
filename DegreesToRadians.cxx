// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
In some forms of geometry, like the kind used in geographical longitude/latitude measurements, angles are measured in base-60.  The base unit is the degree.  One degree contains 60 minutes, and one minute contains 60 seconds.


You will be given the measurement of an angle in degrees, minutes, and seconds.  Return the given angle in radians.  Note that n degrees is equal to  n*PI/180 radians.


DEFINITION
Class:DegreesToRadians
Method:convertToRadians
Parameters:int, int, int
Returns:double
Method signature:double convertToRadians(int degrees, int minutes, int seconds)


NOTES
-The return value must have an absolute or relative error less than 1e-9.


CONSTRAINTS
-degrees will be between 0 and 359, inclusive.
-minutes will be between 0 and 59, inclusive.
-seconds will be between 0 and 59, inclusive.


EXAMPLES

0)
0
0
0

Returns: 0.0

Zero is zero, in either measurement system.

1)
180
0
0

Returns: 3.141592653589793

180 degrees is PI radians.

2)
359
59
59

Returns: 6.283180459042776

This is as close to a full circle as it gets.

3)
23
30
5

Returns: 0.41017661490272295

// END CUT HERE
#line 66 "DegreesToRadians.cxx"
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

class DegreesToRadians {
	public:
		double convertToRadians(int degrees, int minutes, int seconds) 
		{		
			return (degrees + double(minutes)/60 + double(seconds)/3600) * acos(0) / 90;
		}
};
