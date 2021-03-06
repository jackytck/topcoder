// BEGIN CUT HERE
// PROBLEM STATEMENT
// An object is placed in the xy-plane at coordinates (x,y), where x > 0 and y > 0. 
The object begins falling straight down toward the x-axis at a speed of one unit per second. Along the way, it may encounter some obstacles.
Each obstacle is a horizontal line segment, and the object hits an obstacle when their y-coordinates are equal and the object's x-coordinate
is between the x-coordinates of the obstacle's endpoints (inclusive). Each time the object hits an obstacle, it will be delayed 5 seconds.
During this delay, the object will travel to the right endpoint of the obstacle (the one with the greater x-coordinate). The object
will then continue to fall straight down from that point.

You are given the object's initial position (x,y) and a vector <string> describing the obstacles.
Return the number of seconds it will take for the object to finally reach the x-axis. Each element of obstacles is formatted
"y x1 x2" (quotes for clarity only), where y is the y-coordinate of an obstacle,
and x1 and x2 are the left and right x-coordinates of that obstacle's endpoints respectively.

DEFINITION
Class:ObjectFall
Method:howLong
Parameters:int, int, vector <string>
Returns:int
Method signature:int howLong(int x, int y, vector <string> obstacles)


CONSTRAINTS
-x will be between 1 and 1000, inclusive.
-y will be between 1 and 1000, inclusive.
-obstacles will contain between 0 and 50 elements, inclusive.
-Each element of obstacles will be formatted "y x1 x2" (quotes for clarity only).
-Each y, x1 and x2 in obstacles will be an integer between 001 and 999, inclusive, and contain exactly 3 digits.
-In each element of obstacles, x1 will be less than or equal to x2.
-obstacles will contain no duplicate y values.


EXAMPLES

0)
15
10
{"005 010 020"}

Returns: 15

The object starts at (15,10), and when it reaches (15,5), it hits the obstacle and is delayed 5 seconds.

1)
15
12
{"010 010 020","015 010 020","005 020 050"}

Returns: 22

The object hits the obstacle at y = 10 and moves to (20,10). From there it continues to fall until it hits the object at y = 5. Finally, it falls to the x-axis at (50,0). The total time is: 2 seconds before hitting the first obstacle + 5 seconds of delay + 5 seconds until hitting the next obstacle + 5 seconds of delay + 5 seconds until hitting the x-axis = 22 seconds.

2)
50
85
{"020 001 100","010 100 100","005 100 200"}

Returns: 100

The object hits all three obstacles, even the one that is a point.

3)
10
1000
{}

Returns: 1000

A free-fall to the x-axis.

4)
500
800
{"800 001 500","400 001 499","401 501 999"}

Returns: 805

5)
645
802
{"739 038 799","916 169 791","822 372 911","162 125 992","261 307 545",
 "510 031 765","592 723 742","477 315 676","566 143 617","337 114 664",
 "986 648 883","116 230 680","254 746 943","742 948 988","060 117 401",
 "634 035 433","288 741 864","819 626 730","906 071 222","554 100 121",
 "573 051 551","949 528 915","562 151 223","857 135 243","621 115 474",
 "588 405 615","895 812 919","052 378 836","858 116 505","285 428 469",
 "792 244 250","109 265 637","714 804 885","625 150 410","518 593 921",
 "282 235 339","081 212 659","663 047 982","556 194 345","798 150 938",
 "391 026 813","886 348 796","975 007 743","053 854 895","243 561 875"}

Returns: 817

// END CUT HERE
#line 95 "ObjectFall.cxx"
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

bool cmp(string a, string b)
{
	int ai, bi;
	sscanf(a.c_str(), "%d", &ai);
	sscanf(b.c_str(), "%d", &bi);
	return bi < ai;
}

class ObjectFall {
	public:
		int howLong(int x, int y, vector <string> obstacles) 
		{		
			int ret = 0;
			sort(obstacles.begin(), obstacles.end(), cmp);
			forv(i, obstacles)
			{
				int a, b, c;
				sscanf(obstacles[i].c_str(), "%d %d %d", &a, &b, &c);
				if(y >= a && x >=b && x <= c)
				{
					ret += y-a+5;
					x = c;
					y = a;
				}
			}
			return ret+y;
		}
};
