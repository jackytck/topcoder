// BEGIN CUT HERE
// PROBLEM STATEMENT
// This task is about the scoring in the first phase of the die-game Yahtzee, where five dice are used. The score is determined by the values on the upward die faces after a roll. The player gets to choose a value, and all dice that show the chosen value are considered active. The score is simply the sum of values on active dice.

Say, for instance, that a player ends up with the die faces showing 2, 2, 3, 5 and 4. Choosing the value two makes the dice showing 2 active and yields a score of 2 + 2 = 4, while choosing 5 makes the one die showing 5 active, yielding a score of 5.

Your method will take as input a vector <int> toss, where each element represents the upward face of a die, and return the maximum possible score with these values.



DEFINITION
Class:YahtzeeScore
Method:maxPoints
Parameters:vector <int>
Returns:int
Method signature:int maxPoints(vector <int> toss)


CONSTRAINTS
-toss will contain exactly 5 elements.
-Each element of toss will be between 1 and 6, inclusive.


EXAMPLES

0)
{ 2, 2, 3, 5, 4 }

Returns: 5

The example from the text.

1)
{ 6, 4, 1, 1, 3 }

Returns: 6

Selecting 1 as active yields 1 + 1 = 2, selecting 3 yields 3, selecting 4 yields 4 and selecting 6 yields 6, which is the maximum number of points.

2)
{ 5, 3, 5, 3, 3 }

Returns: 10

// END CUT HERE
#line 47 "YahtzeeScore.cxx"
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

class YahtzeeScore {
	public:
		int maxPoints(vector <int> toss) 
		{		
			vector <int> cnt(6, 0);
			forv(i, toss)
				cnt[toss[i]-1]++;
			forv(i, cnt)
				cnt[i] = cnt[i]*(i+1);
			return *max_element(cnt.begin(), cnt.end());
		}
};
