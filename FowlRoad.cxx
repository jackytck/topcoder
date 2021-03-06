// BEGIN CUT HERE
// PROBLEM STATEMENT
// The highway extends endlessly headed east and west. Bob the chicken walks in a 
sequence of straight lines. Given Bob's path, we want to figure out 
how many times he crosses the road (assuming he doesn't become road kill).
We will not count it as a crossing if Bob moves onto the road, possibly wanders 
along the road, and then returns to the side he entered the road from.

The road has negligible width, so it is just a horizontal line running along a given y coordinate.
Create a class FowlRoad that contains a method crossings that is given roadY (the
y coordinate of the road), and vector <int>s bobX and bobY giving Bob's path.  It should
return the number of times that Bob crosses the road.

The ith elements of bobX and bobY give the coordinates of a point in Bob's path.
Bob starts at the first point, and proceeds in a straight line to the next point,
continuing until he finishes at the last point. Bob does not start or end on the road.



DEFINITION
Class:FowlRoad
Method:crossings
Parameters:int, vector <int>, vector <int>
Returns:int
Method signature:int crossings(int roadY, vector <int> bobX, vector <int> bobY)


CONSTRAINTS
-bobX contains between 2 and 50 elements, inclusive.
-bobY contains the same number of elements as bobX.
-roadY and each element of bobX and each element of bobY is between -100 and 100, inclusive.
-Neither the first nor the last element of bobY is equal to roadY.


EXAMPLES

0)
6
{3,7,9,2}
{-3,8,8,2}

Returns: 2



   As Bob goes from (3,-3) to (7,8) he crosses the road. From (7,8) to (9,8) he is
   moving parallel to the road, not crossing it. But when he goes from (9,8) to 
   (2,2) he crosses the road again.



1)
10
{3,7,9,2}
{-3,8,8,2}

Returns: 0



   Bob wanders around on the south side of the road, never crossing it.

2)
0
{3,2,5,6,9}
{2,0,0,2,-88}

Returns: 1



   Bob wanders from the north side onto the road, along the road, then back to
   the north side at (6,2). On his last segment he crosses the road from the
   north side to the south side.


3)
0
{3,2,5,6,9}
{-2,0,0,2,-88}

Returns: 2



   This is the same as the preceding example except that Bob starts on the south
   side of the road at (3,-2). He wanders onto the road, along the road and then
   onto the north side thereby completing a crossing from south to north. On his 
   last segment he crosses the road from north to south.

// END CUT HERE
#line 93 "FowlRoad.cxx"
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

class FowlRoad {
	public:
		int crossings(int roadY, vector <int> bobX, vector <int> bobY) 
		{		
			int ret = 0;
			bool state = bobY[0]-roadY>0 ? 1 : 0;
			For(i, 1, bobX.sz)
			{
				bool temp = bobY[i]-roadY>0 ? 1 : ((bobY[i]-roadY)==0 ? state : 0);
				if(state != temp)
				{
					state = temp;
					ret++;
				}
			}
			return ret;
		}
};
