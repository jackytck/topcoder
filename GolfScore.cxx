// BEGIN CUT HERE
// PROBLEM STATEMENT
// 


A full-sized golf course consists of 18 lawns known as holes. The player's
objective is to strike a ball with his club in such a way that it travels
from a specified point at one end of the lawn to a specified point at
the other, and to do so with as few strokes as he can. Associated with
each hole is a positive number, the par, which is the number of strokes
it is expected to take a competent golfer to complete the hole.



A player's performance on an individual hole is described by
a phrase that depends on the number of strokes he took relative to
par. To make a "bogey", for example, means that the player has completed
a hole in one stroke more than the par value, and a "double bogey" is
two strokes over par. Two strokes under par, on the other hand, is an
"eagle", while the "albatross", a rare bird indeed, is three strokes
under par. The following is a complete dictionary of scoring phrases.




    
    "triple bogey"  three strokes over par
    "double bogey"  two strokes over par
    "bogey"         one stroke over par
    "par"           exactly par 
    "birdie"        one stroke under par
    "eagle"         two strokes under par
    "albatross"     three strokes under par
    "hole in one"   exactly one stroke


 

The managers of Gravel Mountain Golf Course have contracted you to
implement a score-management system that will translate a single player's
scores from the above jargon to a numerical total. You are given a
vector <int> specifying the par value of each of the course's
18 holes in playing order. You are also given a vector <string>
such that the nth string describes the player's
score on the nth hole.  The reported scores will be valid
and complete. Compute the player's total score and return it as an
int.




DEFINITION
Class:GolfScore
Method:tally
Parameters:vector <int>, vector <string>
Returns:int
Method signature:int tally(vector <int> parValues, vector <string> scoreSheet)


CONSTRAINTS
-parValues and scoreSheet each contain exactly 18 elements
-each element of parValues is between 1 and 5, inclusive
-each element of scoreSheet is one of the eight phrases listed above
-no element of scoreSheet describes an impossible score


EXAMPLES

0)
{1, 1, 1, 1, 1, 1,
 1, 1, 1, 5, 5, 5,
 5, 5, 5, 5, 5, 5}
{"bogey", "bogey", "bogey", "bogey", "bogey", "bogey",
 "bogey", "bogey", "bogey", "eagle", "eagle", "eagle",
 "eagle", "eagle", "eagle", "eagle", "eagle", "eagle"}

Returns: 45

The player took 9*2 = 18 strokes on the front nine and 9*3 = 27 on the back nine for a total score of 18+27 = 45.

1)
{3, 2, 4, 2, 2, 1,
 1, 1, 3, 2, 4, 4,
 4, 2, 3, 1, 3, 2}
{"bogey", "double bogey", "par", "double bogey", "double bogey", "triple bogey",
 "triple bogey", "triple bogey", "bogey", "double bogey", "par", "par",
 "par", "double bogey", "bogey", "triple bogey", "bogey", "double bogey"}

Returns: 72

This player takes four strokes on every hole.

2)
{3, 2, 4, 2, 2, 1,
 1, 1, 3, 2, 4, 4,
 4, 2, 3, 1, 3, 2}
{"eagle", "birdie", "albatross", "birdie", "birdie", "par",
 "hole in one", "par", "eagle", "birdie", "albatross", "albatross",
 "albatross", "birdie", "eagle", "hole in one", "eagle", "birdie"}

Returns: 18

This can only be Tiger Woods.

3)
{4, 1, 3, 3, 4, 4,
 1, 4, 2, 3, 3, 5,
 4, 1, 4, 4, 2, 1}
{"triple bogey", "triple bogey", "bogey", "par", "triple bogey", "double bogey",
 "triple bogey", "triple bogey", "par", "eagle", "bogey", "bogey",
 "birdie", "par", "triple bogey", "eagle", "triple bogey", "triple bogey"}

Returns: 77

// END CUT HERE
#line 117 "GolfScore.cxx"
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

class GolfScore {
	public:
		int tally(vector <int> parValues, vector <string> scoreSheet) 
		{		
			int ret = 0;
			string nickname[] = {"triple bogey", "double bogey", "bogey", "par", "birdie", "eagle", "albatross", "hole in one"};
			forv(i, scoreSheet)
			{
				int stroke = 3-int(find(nickname, nickname+7, scoreSheet[i])-nickname)+parValues[i];
				ret += stroke>0 ? stroke : 1;
			}
			return ret;
		}
};
