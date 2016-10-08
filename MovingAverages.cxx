// BEGIN CUT HERE
// PROBLEM STATEMENT
// Moving averages are well known in stock charts analysis.
They are used to emphasize the direction of a trend and to smooth out fluctuations.
Athletes may use moving averages to analyze their training results.


Given a vector <string> times containing the times from successive training sessions
(e.g. the time to cycle a certain leg)
and an int n, return a vector <int> containing the n-moving averages in seconds for
these times, with each average rounded down.


Each element of times is in the format "hh:mm:ss" (quotes for clarity), where hh,
mm and ss are two digit numbers (with a leading zero if necessary) indicating the
number of hours, minutes and seconds, respectively.

A n-moving average is the average (i.e. the arithmetic mean) of n consecutive times.
So for t times given, t-n+1 n-moving averages are to be calculated.
The first average is composed from the times 1 to n, the second average from the times 2 to n+1 and so on,
the last average is composed from the times t-n+1 to t.




DEFINITION
Class:MovingAverages
Method:calculate
Parameters:vector <string>, int
Returns:vector <int>
Method signature:vector <int> calculate(vector <string> times, int n)


CONSTRAINTS
-times contains between 1 and 50 elements, inclusive.
-Each element of times is in the format "hh:mm:ss" (quotes for clarity), wherehh is a two digit number (with a leading zero if necessary) between 0 and 23, inclusive,mm is a two digit number (with a leading zero if necessary) between 0 and 59, inclusive,ss is a two digit number (with a leading zero if necessary) between 0 and 59, inclusive.
-n is between 1 and the number of elements in times, inclusive.


EXAMPLES

0)
{"01:19:10", "01:17:40", "01:19:44", "01:17:23", "01:17:07"}
3

Returns: { 4731,  4695,  4684 }

4731 (01:18:51) is the average of of the first three times, namely 01:19:10, 01:17:40, and 01:19:44.
4695 (01:18:15) is the average of the middle three times (01:17:40, 01:19:44, 01:17:23).
Finally, 4684 (01:18:04) is the average of the last three times (01:19:44, 01:17:23, 01:17:07).


1)
{"01:19:10", "01:17:40", "01:19:44", "01:17:23", "01:17:07"}
1

Returns: { 4750,  4660,  4784,  4643,  4627 }

The 1-moving averages are just the times given.

2)
{"01:19:10", "01:17:40", "01:19:44", "01:17:23", "01:17:07"}
5

Returns: { 4692 }

The 5-moving averages of five times is just one value, the average of all the five values.


// END CUT HERE
#line 72 "MovingAverages.cxx"
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

class MovingAverages {
	public:
		vector <int> calculate(vector <string> times, int n) 
		{		
			vector <int> seconds;
			forv(i, times)
			{
				int h, m, s;
				sscanf(times[i].c_str(), "%d:%d:%d", &h, &m, &s);
				seconds.PB(h*3600+m*60+s);
			}
			vector <int> ret;
			forn(i, times.sz-n+1)
			{
				int avg = 0;
				forn(j, n)
					avg += seconds[i+j];
				ret.PB(avg/n);
			}
			return ret;
		}
};
