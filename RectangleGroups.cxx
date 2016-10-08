// BEGIN CUT HERE
// PROBLEM STATEMENT
// You have a list of rectangles divided into groups. The index of a group is the sum of the areas of all the rectangles in the group. You are to determine the group with the biggest index.
You are given a vector <string> rectangles. Each element of rectangles represents a single rectangle, and is formatted as "G L W", where G is the name of the group to which the rectangle belongs, L is the rectangle's length, and W is the rectangle's width. Return a string formatted as "G I", where G is the name of the group with the maximal index, and I is the index of that group with no leading zeroes. If there are multiple groups with the same maximal index, return the one whose name comes first alphabetically.

DEFINITION
Class:RectangleGroups
Method:maximalIndexed
Parameters:vector <string>
Returns:string
Method signature:string maximalIndexed(vector <string> rectangles)


CONSTRAINTS
-rectangles will contain between 1 and 50 elements, inclusive.
-Each element of rectangles will be formatted as "G L W", where G is an uppercase letter ('A' - 'Z') and L and W are integers with no leading zeroes.
-Each L and W will be between 1 and 1000, inclusive.


EXAMPLES

0)
{"A 1 2", "A 3 3"}

Returns: "A 11"

There is only one group, and its index is 11 (1*2 + 3*3).

1)
{"A 1 2", "B 3 3", "A 2 1"}

Returns: "B 9"

The index of A is 4, and the index of B is 9.

2)
{"D 1 6", "F 2 3", "G 1 1", "G 5 1", "C 3 2"}

Returns: "C 6"

All groups have the same index, and C comes first alphabetically.

3)
{"S 2 54", "Y 34 65", "F 234 23", "D 84 127", "R 603 46",
"S 36 192", "Y 76 32", "T 54 28", "S 22 22"}

Returns: "R 27738"

// END CUT HERE
#line 51 "RectangleGroups.cxx"
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

class RectangleGroups {
	public:
		string maximalIndexed(vector <string> rectangles) 
		{		
			vector <int> area(26, 0);
			forv(i, rectangles)
			{
				stringstream ss(rectangles[i]);
				char G;
				int L,W;
				ss >> G >> L >> W;
				area[G-'A'] += L*W;
			}
			int max = *max_element(area.begin(), area.end());
			int found = 0;
			forv(i, area)
				if(area[i] == max)
				{
						found = i;
						break;
				}
			stringstream ss;
			ss << char('A'+found) << " " << area[found];
			return ss.str();
		}
};
