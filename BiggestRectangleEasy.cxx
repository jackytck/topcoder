// BEGIN CUT HERE
// PROBLEM STATEMENT
// Little Josh has found several sticks that are each 1 inch long.  He wants to form a rectangle with the biggest possible area, using these sticks as the perimeter.  He is allowed to glue sticks together, but he is not allowed to break a single stick into multiple shorter sticks.

For example, if Josh has 11 sticks, he can create a 2 x 3 rectangle using 10 sticks.  This rectangle has an area of 6 square inches, which is the biggest area that can be achieved in this case.

You will be given an int N, and you must return the maximal area (in square inches) of a rectangle that can be created using N or less sticks.


DEFINITION
Class:BiggestRectangleEasy
Method:findArea
Parameters:int
Returns:int
Method signature:int findArea(int N)


CONSTRAINTS
-N will be between 4 and 10000, inclusive.


EXAMPLES

0)
11

Returns: 6

The example from the problem statement.

1)
5

Returns: 1

The only rectangle that can be created is a square with 1 inch side.

2)
64

Returns: 256

Josh can create a square with the 16 inches side.

3)
753

Returns: 35344

4)
7254

Returns: 3288782

// END CUT HERE
#line 57 "BiggestRectangleEasy.cxx"
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

class BiggestRectangleEasy {
	public:
		int findArea(int N) 
		{		
			return int(N/4) * (int(N/2)-int(N/4));
		}
};
