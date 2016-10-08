// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
You are currently at a point (x,y) inside a rectangle.  The rectangle's bottom left corner is at (0,0) and its top right corner is at (w,h). Return the shortest distance you must travel in order to reach the rectangle's boundary.



DEFINITION
Class:EscapeFromRectangle
Method:shortest
Parameters:int, int, int, int
Returns:int
Method signature:int shortest(int x, int y, int w, int h)


CONSTRAINTS
-w and h will be between 2 and 1000, inclusive.
-x will be between 1 and w - 1, inclusive.
-y will be between 1 and h - 1, inclusive.


EXAMPLES

0)
1
1
5
5

Returns: 1

We can go either straight down or straight to the left.

1)
6
2
10
3

Returns: 1

Go straight to the upper boundary here.

2)
653
375
1000
1000

Returns: 347

Going straight to the right leads to success.

3)
161
181
762
375

Returns: 161

// END CUT HERE
#line 64 "EscapeFromRectangle.cxx"
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

class EscapeFromRectangle {
	public:
		int shortest(int x, int y, int w, int h) 
		{		
			return min(min(x, y), min(w-x, h-y));
		}
};
