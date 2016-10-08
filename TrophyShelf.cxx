// BEGIN CUT HERE
// PROBLEM STATEMENT
// You have several trophies sitting on a shelf in a straight line.  Their heights are given in a vector <int> trophies, from left to right.  The shelf is positioned so that whenever people enter your room, they see it directly from the left side.  In other words, the leftmost trophy is completely visible to the viewer, the next trophy in line is directly behind it, and so on.

Unfortunately, tall trophies near the left side of the shelf might block the view of other trophies.  A trophy is visible only if every trophy in front of it (from the viewer's perspective) is strictly shorter than it is.  You wonder if rotating the shelf 180 degrees would increase the number of visible trophies.

Return a vector <int> containing exactly two elements.  The first element should be the number of trophies visible when viewing the shelf directly from the left side, and the second element should be the number of trophies visible when viewing the shelf directly from the right side.

DEFINITION
Class:TrophyShelf
Method:countVisible
Parameters:vector <int>
Returns:vector <int>
Method signature:vector <int> countVisible(vector <int> trophies)


CONSTRAINTS
-trophies will contain between 1 and 50 elements, inclusive.
-Each element of trophies will be between 1 and 100, inclusive.


EXAMPLES

0)
{1,2,3,4,5}

Returns: {5, 1 }

When viewed from the left, each trophy is taller than all the trophies in front of it.  However, when viewed from the right, the first trophy blocks the view of all the other trophies.

1)
{5,5,5,5}

Returns: {1, 1 }

Since all trophies have the same height, only the first is visible when viewed from each direction.

2)
{1,2,5,2,1}

Returns: {3, 3 }

This trophy shelf is symmetric.

3)
{1,4,2,5,3,7,1}

Returns: {4, 2 }



// END CUT HERE
#line 54 "TrophyShelf.cxx"
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
#define clr(x) memset(x, 0, sizeof(x))
#define forn(i,n) for(__typeof(n) i = 0; i < (n); i++)
#define ford(i,n) for(int i = (n) - 1; i >= 0; i--)
#define For(i, st, en) for(__typeof(en) i = (st); i <= (en); i++)

using namespace std;

class TrophyShelf {
	public:
		vector <int> countVisible(vector <int> trophies) 
		{
			vector <int> see;
			int r = 1, l = 1;
			int temp = trophies[0];
			forn(i, trophies.sz)
			{
				if(trophies[i] > temp)
				{
					r++;
					temp = trophies[i];
				}
			}
			temp = trophies[trophies.sz-1];
			ford(i, trophies.sz)
			{
				if(trophies[i] > temp)
				{
					l++;
					temp = trophies[i];
				}
			}
			see.push_back(r);
			see.push_back(l);
			return see;
		}
};
