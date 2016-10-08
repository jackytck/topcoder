// BEGIN CUT HERE
// PROBLEM STATEMENT
// An ellipse is a figure on a plane where the sum of the distances from any point on its perimeter to two fixed points is constant. The two fixed points are called foci (plural of focus). In this problem we are interested in the number of points with integral coordinates that lie strictly inside of the given ellipse.

The foci are (x1, y1) and (x2, y2), and the fixed sum of distances is d.

DEFINITION
Class:EllipseCoverage
Method:calculateCoverage
Parameters:int, int, int, int, int
Returns:int
Method signature:int calculateCoverage(int x1, int y1, int x2, int y2, int d)


CONSTRAINTS
-x1, y1, x2, y2 will be between -100 and 100, inclusive.
-d will be between 1 and 200, inclusive.
-The arguments will define a valid ellipse with positive area.


EXAMPLES

0)
0
0
0
0
4

Returns: 9

This is a circle with radius 2.  The points (-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 0), (0, 1), (1, -1), (1, 0) and (-1, 1) lie strictly inside the circle.  The points (-2, 0), (0, -2), (0, 2) and (2, 0) are on the perimeter, so they do not lie strictly inside the circle and should not be counted.

1)
-3
0
3
0
10

Returns: 59

Be careful with (0, 4), (-5, 0), (0, -4) and (5, 0).

2)
10
12
8
14
50

Returns: 1941



3)
0
0
0
0
200

Returns: 31397



4)
13
-23
49
91
200

Returns: 25187



// END CUT HERE
#line 80 "EllipseCoverage.cxx"
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

class EllipseCoverage {
	public:
		int calculateCoverage(int x1, int y1, int x2, int y2, int d) 
		{		
			int cnt = 0;
			For(i, -300, 301)
				For(j, -300, 301)
					if(sqrt((i-x1)*(i-x1) + (j-y1)*(j-y1)) + sqrt((i-x2)*(i-x2) + (j-y2)*(j-y2)) < d)
						cnt++;
			return cnt;
		}
};
