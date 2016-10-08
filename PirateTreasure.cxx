// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
The great pirate Silver has buried a treasure on a tropical island. You
managed to find a map of the island with an X marking a spot on the island,
and a set of instructions.
Each instruction is of the form "walk A steps in the direction B".
If you start at the X and follow the instructions in the given order,
at the end you will arrive at the location where the treasure is buried.



Your evil twin has a copy of the map, and has already started to follow
the instructions. To beat him, you must find the location of the treasure
and walk straight to that place.



You will be given the set of instructions as a vector <int> steps and a vector <string>
directions. 
Element i of directions corresponds to element i of steps.
Write a method that will find the location of the treasure, and
return the straight-line distance (in steps) from the place
where you start to the place where the treasure is buried.



Each direction in directions will be one of the eight basic directions on a compass.
Refer to the image below for clarification.






DEFINITION
Class:PirateTreasure
Method:getDistance
Parameters:vector <int>, vector <string>
Returns:double
Method signature:double getDistance(vector <int> steps, vector <string> directions)


NOTES
-The returned value must have an absolute or relative error less than 1e-9.
-Assume that the island lies on a plane, and that it is large enough to accomodate the entire walk.
-Note that making a step northwest is not the same as making a step north and then a step west. See Example 3.
-The Euclidean distance between two points A=(ax,ay) and B=(bx,by) in a plane is equal to sqrt( (ax-bx)^2 + (ay-by)^2 ).


CONSTRAINTS
-steps will contain between 1 and 50 elements, inclusive.
-Each element in steps will be between 1 and 50, inclusive.
-directions will contain the same number of elements as steps.
-Each element of directions will be one of NORTH, SOUTH, EAST, WEST, NORTHEAST, NORTHWEST, SOUTHEAST, and SOUTHWEST.


EXAMPLES

0)
{1}
{"NORTH"}

Returns: 1.0

After one step north, you will be (surprisingly) one step away from where you started.

1)
{2}
{"NORTHWEST"}

Returns: 2.0

Two steps northwest will take you two steps away from where you started.

2)
{3,10,7}
{"EAST","WEST","EAST"}

Returns: 0.0

After following these instructions you'll end exactly where you started.

3)
{34,48,34}
{"NORTH","SOUTHWEST","EAST"}

Returns: 0.08326112068522587

Following these instructions won't get you exactly to the same place where you started, but you will be pretty close.

4)
{2,2,2,1}
{"NORTH","NORTH","NORTH","NORTHWEST"}

Returns: 6.744277676240694

After six steps north and one step northwest, your straight line distance from where you started is a little less than seven steps.

// END CUT HERE
#line 102 "PirateTreasure.cxx"
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

class PirateTreasure {
	public:
		double getDistance(vector <int> steps, vector <string> directions) 
		{		
			double x = 0, y = 0;
			forv(i, steps)
			{
				if(directions[i] == "NORTH")
				{
						y += steps[i];
				}
				else if(directions[i] == "SOUTH")
				{
						y -= steps[i];
				}
				else if(directions[i] == "EAST")
				{
						x += steps[i];
				}
				else if(directions[i] == "WEST")
				{
						x -= steps[i];
				}
				else if(directions[i] == "NORTHEAST")
				{
						x += steps[i] * sqrt(2) / 2;
						y += steps[i] * sqrt(2) / 2;
				}
				else if(directions[i] == "NORTHWEST")
				{
						x -= steps[i] * sqrt(2) / 2;
						y += steps[i] * sqrt(2) / 2;
				}
				else if(directions[i] == "SOUTHEAST")
				{
						x += steps[i] * sqrt(2) / 2;
						y -= steps[i] * sqrt(2) / 2;
				}
				else
				{
						x -= steps[i] * sqrt(2) / 2;
						y -= steps[i] * sqrt(2) / 2;
				}
			}
				return sqrt(x * x + y * y);
		}
};
