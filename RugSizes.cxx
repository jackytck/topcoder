// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
Rugs come in various sizes. In fact, we can find a rug with any integer width
and length, except that no rugs have a distinct width and length that are both even integers. For example, we can find a 4x4 rug, but not a 2x4 rug.  We want to know how many different choices we have for a
given area.

Create a class RugSizes the contains a method rugCount that is given the desired
area and returns the number of different ways in which we can choose a rug size that
will cover that exact area.
Do not count the same size twice -- a 6 x 9 rug and a 9 x 6 rug should be 
counted as one choice.



DEFINITION
Class:RugSizes
Method:rugCount
Parameters:int
Returns:int
Method signature:int rugCount(int area)


CONSTRAINTS
-area will be between 1 and 100,000, inclusive.


EXAMPLES

0)
4

Returns: 2



   The choices are 1 x 4 (or equivalently 4 x 1) and 2 x 2.



1)
8

Returns: 1

 

   Only 1 x 8 is available. Note that 2 x 4 has the desired area, but is not
   available since its width and length differ and are both even numbers.


// END CUT HERE
#line 54 "RugSizes.cxx"
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

class RugSizes {
	public:
		int rugCount(int area) 
		{		
			int ret = 0;
			For(i, 1, area+1)
				if(area%i == 0 && area/i >= i && !(i%2 == 0 && (area/i)%2 == 0 && i != area/i))
					ret++;
			return ret;
		}
};
