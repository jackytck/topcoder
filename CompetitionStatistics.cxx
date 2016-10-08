// BEGIN CUT HERE
// PROBLEM STATEMENT
// The longest consecutive rating increase streak is a very important statistic in any competition. You are to calculate this statistic for a certain player.
You will be given a vector <int> ratingChanges containing the rating changes of the player in chronological order. Your method should return the maximum number of consecutive competitions with positive rating changes. Note that 0 is not a positive number.


DEFINITION
Class:CompetitionStatistics
Method:consecutiveGrowth
Parameters:vector <int>
Returns:int
Method signature:int consecutiveGrowth(vector <int> ratingChanges)


CONSTRAINTS
-ratingChanges will contain between 1 and 50 elements, inclusive.
-Each element of ratingChanges will be between -1000 and 1000, inclusive.


EXAMPLES

0)
{30, 5, -5, 3, 3, 1}

Returns: 3

The player raises rating two times, afterwards reduces it once and finally raises it three times in a row.

1)
{-1, -5, -9}

Returns: 0

No rating changes are positive.

2)
{12, 0, 15, 73}

Returns: 2

3)
{12, 1, 15, 73}

Returns: 4

4)
{-6, 13, 15, -11, 12, 12, 33, 12, -1}

Returns: 4

// END CUT HERE
#line 53 "CompetitionStatistics.cxx"
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

class CompetitionStatistics {
	public:
		int consecutiveGrowth(vector <int> ratingChanges) 
		{		
			int ret = 0, iret = 0;
			forv(i, ratingChanges)
			{
				if(ratingChanges[i] > 0)
					iret++;
				else
				{
					ret >?= iret;
					iret = 0;
				}
			}
			return ret >? iret;
		}
};
