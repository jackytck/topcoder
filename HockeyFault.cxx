// BEGIN CUT HERE
// PROBLEM STATEMENT
// Last week, MyOwnBusiness Inc. received an urgent call from the IIHF (International Ice Hockey Federation) requesting a system to raise an alarm to the referee when there are too many players from the same team inside the rink. The system will be composed of three parts:


A digital camera in the ceiling to take photos of the rink every second.
A software module to extract the position of each player from the photo taken by the digital camera.
A software module to count the number of players from the same team inside the hockey rink.


The hockey rink consists of a width x height rectangle whose lower-left corner is at (x, y), and two circles with radius height / 2, one centered at (x, y + radius) and the other centered at (x + width, y + radius). See the image below for a graphic description. The players are specified by the vector <int>s px and py, where the k-th player's position is (px[k], py[k]).



You have been assigned the task of implementing the system's third module, following the specification given by the project leader: "Given the rink's specification and the players' positions, create a method numPlayers that returns the number of players on the boundary or inside the rink."


DEFINITION
Class:HockeyFault
Method:numPlayers
Parameters:int, int, int, int, vector <int>, vector <int>
Returns:int
Method signature:int numPlayers(int width, int height, int x, int y, vector <int> px, vector <int> py)


NOTES
-For those who know about ice hockey, the rink described in this problem is different than a real hockey rink.


CONSTRAINTS
-width will be between 1 and 100, inclusive.
-height will be between 2 and 100, inclusive.
-height will be an even number.
-x will be between -100 and 100, inclusive.
-y will be between -100 and 100, inclusive.
-px will contain between 1 and 50 elements, inclusive.
-Each element of px will be between -300 and 300, inclusive.
-py will contain the same number of elements as px.
-Each element of py will be between -300 and 300, inclusive.


EXAMPLES

0)
20
10
5
0
{15, 1, 1}
{5, 5, 1}

Returns: 2

The first player is exactly in the middle of the rink, the second player is exactly at the left border of the left circle and the third player is outside the rink.

1)
20
10
0
0
{-5, -4, -4, -3, -3, 0, 0, 20, 20, 23, 23, 24, 24, 25}
{5, 2, 8, 1, 9, 0, 10, 0, 10, 1, 9, 2, 8, 5}

Returns: 14

All players are on the rink boundary.

2)
52
84
-44
66
{26, -33, -49, 40, -10, 47, 25, -16, -82, 7}
{118, 106, 128, 114, 101, 85, 142, 140, 126, 145}

Returns: 8

3)
24
100
-61
71
{-63, -26, -9, -113, -124, -95, -89, -55}
{109, 164, 91, 80, 75, 140, 116, 113}

Returns: 6



// END CUT HERE
#line 92 "HockeyFault.cxx"
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

class HockeyFault {
	public:
		int numPlayers(int width, int height, int x, int y, vector <int> px, vector <int> py) 
		{		
			int p = 0;
			forv(i, px)
			{
				if(((px[i]-x)*(px[i]-x) + (py[i]-y-height/2)*(py[i]-y-height/2) <= (height*height)/4) || ((px[i]-x-width)*(px[i]-x-width) + (py[i]-y-height/2)*(py[i]-y-height/2) <= (height*height)/4) || (px[i] >= x && px[i] <= x+width && py[i] >= y && py[i] <= y+height))
					p++;
			}
			return p;
		}
};
