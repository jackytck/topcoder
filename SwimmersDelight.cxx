// BEGIN CUT HERE
// PROBLEM STATEMENT
// You want to cross a river 10 feet wide and there are 2 stones in the water you can jump on. A few jumps are needed, but your only concern is the longest one. This is obviously the most problematic, so you wish to choose a path that makes this jump as small as possible. 

The length of a jump between two stones of coordinates (x1,y1) and (x2,y2) is defined as the Euclidian distance:  
      sqrt((x1 - x2) * (x1 - x2)  +  (y1 - y2) * (y1 - y2))


You will be given a int[] x and a int[] y with exactly 2 elements each, representing the coordinates of the stones: (x[i],y[i]) is the location of the i-th stone. The edge of the shore on which you initially stand has an x-value of 0 and could take any y-value. Thus, the minimal distance between the shore and the first stone you jump on is the x-value in the location of that stone. The edge of the other shore has an x-value of 10 and could take any y-value as well. 

Return the distance of the longest jump you need to make, rounded to the nearest integer.   


DEFINITION
Class:SwimmersDelight
Method:longestJump
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int longestJump(vector <int> x, vector <int> y)


NOTES
-You may jump on the 2 stones in any order, or just on one stone.


CONSTRAINTS
-x and y will each contain 2 elements.
-All values in x are between 1 and 9, inclusive.
-All values in y are between 0 and 10, inclusive.
-The two stones are not in the same location.
-No actual distance will be more than 1e-4 close to some integer + 0.5.


EXAMPLES

0)
{3,7}
{5,5}

Returns: 4

The three stones are arranged in a line, so the strategy is quite simple here: you first jump on the stone at (3,5), then on the stone at (7,5) and you finally reach the other shore at (10,5). The longest jump has a length of 4 feet: from (3,5) to (7,5). 
If you like to play around, you can follow the path (0,5) - (7,5) - (3,5) - (10,5), but this is not optimal since you have to make a jump of 7 feet! 
Thus, the correct answer is 4.  

1)
{3,6}
{5,2}

Returns: 4

The path you should take is (0,5) - (3,5) - (6,2) - (10,2). Between (3,5) and (6,2) there is a distance of sqrt(3*3 + 3*3) = 4.2426. There are no jumps longer than this and because the answer is rounded to the nearest integer, you should return 4.

2)
{1,1}
{4,6}

Returns: 9

If you can jump 9 feet at once, chances are you are also a good swimmer ...

3)
{3,8}
{0,10}

Returns: 7

Only the stone at (3,0) is used in this case. The stone at (8,10) is more than 7 feet away from both the shore and the stone at (3,0). 

4)
{4,2}
{5,5}

Returns: 6

The river can be a good initiation in the triple-jump technique. But you can also skip the stone at (2,5), as you need to take a 6 feet jump anyway.

// END CUT HERE
#line 80 "SwimmersDelight.cxx"
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

class SwimmersDelight {
	public:
		int longestJump(vector <int> x, vector <int> y) 
		{		
			double distxy = pow((x[1]-x[0])*(x[1]-x[0])+(y[1]-y[0])*(y[1]-y[0]), 0.5);
			int onestone = (x[0] >? 10-x[0]) <? (x[1] >? 10-x[1]);
			double twostone = (x[0] >? distxy >? 10-x[1]) <? (x[1] >? distxy >? 10-x[0]);
			return onestone>twostone ? (twostone-int(twostone)>=0.5 ? int(twostone)+1 : int(twostone)) : onestone;
		}
};
