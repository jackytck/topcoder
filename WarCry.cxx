// BEGIN CUT HERE
// PROBLEM STATEMENT
// A warring clan in a remote mountain area is fighting a war. In order to better organize their troops, they constructed N outposts situated on a straight line along the hills. Each outpost has the role of monitoring any suspect activity and, in case of an emergency, its messenger has the duty to spread the news. Once an outpost receives the alert, the messenger will continuously blow his alphorn, thus informing the other outposts. It takes exactly one unit of time for the sound to travel between two neighboring outposts. Thus, in order for an outpost to get the message, it takes x units of time, where x is the distance (measured in outposts) between that particular outpost and the nearest alarm source (see example 0 for further clarification).

Consider a scenario in which some of the outposts are already on alert. Your task is to determine how many units of time it will take until all the remaining outposts get the message. You will be given a string outposts, describing the state of each of the N outposts. The i-th character of  outposts  denotes the state of the i-th outpost, where lowercase 'x' stands for an alert and '-' stands for tranquility.  

 Return an int denoting the amount of time needed for all outposts to be alerted.



DEFINITION
Class:WarCry
Method:alertTime
Parameters:string
Returns:int
Method signature:int alertTime(string outposts)


CONSTRAINTS
- outposts  will contain between 1 and 50 characters, inclusive.
-Each character in  outposts  will be either lowercase 'x' or '-'.
-At least one character in  outposts  will be lowercase 'x'.


EXAMPLES

0)
"-x---x-"

Returns: 2

In this example we have 7 outposts, and the outposts at positions (0-based) 1 and 5 are initially on alert.  The following table shows, for each outpost, the position of the nearest outpost already on alert, and the amount of time to become alert:
Outpost   -   Nearest   -   Time
   0             1            1
   1             1            0
   2             1            1
   3             1            2
   4             5            1
   5             5            0
   6             5            1

Note that outpost 3 is equally close to outposts 1 and 5, so either 1 or 5 would have worked in the table above.  Of all the times 2 is largest, so we return 2.


1)
"xx--xx"

Returns: 1

2)
"xx----xx"

Returns: 2

3)
"xx-------xx"

Returns: 4

4)
"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"

Returns: 0

All the outposts are on alert from the beginning.


5)
"x------------------------------------------------x"

Returns: 24

6)
"--x----x----x--"

Returns: 2

7)
"x"

Returns: 0

// END CUT HERE
#line 85 "WarCry.cxx"
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

class WarCry {
	public:
		int alertTime(string outposts) 
		{		
			int ret = 0;
			vector <int> alerts;
			forn(i, outposts.sz)
				if(outposts[i] == 'x')
					alerts.PB(i);
			forn(i, outposts.sz)
			{
				int mindist = outposts.sz;
				if(outposts[i] != 'x')
				{
					forv(j, alerts)
						mindist <?= abs(int(i)-alerts[j]);
					ret >?= mindist;
				}
			}
			return ret;
		}
};
