// BEGIN CUT HERE
// PROBLEM STATEMENT
// A robot is moving in a plane following a set of instructions.

The following instructions are possible (quotes for clarity only):
"LEFT" - turn left 90 degrees
"RIGHT" - turn right 90 degrees
"TURN AROUND" - turn around (a 180 degree turn)
"LEFT X" - turn left X degrees, where X is a positive integer
"RIGHT X" - turn right X degrees, where X is a positive integer
"HALT" - stop executing instructions; further instructions are not executed

You are given a vector <string> containing the robot's instructions. Initially, the robot is facing north. Return the robot's final azimuth - the angle between north and the direction the robot is facing.  Azimuth is always measured clockwise, and is a number between 0, inclusive, and 360, exclusive.  For example, west corresponds to azimuth 270.

DEFINITION
Class:AzimuthMonitoring
Method:getAzimuth
Parameters:vector <string>
Returns:int
Method signature:int getAzimuth(vector <string> instructions)


NOTES
-Turning right corresponds to turning clockwise, turning left corresponds to turning counterclockwise.


CONSTRAINTS
-instructions will contain between 1 and 50 elements, inclusive.
-Each element of instructions will be a valid instruction, as listed in the problem statement.
-In an instruction of the form "LEFT X" or "RIGHT X", X will be an integer between 1 and 179, inclusive, with no leading zeroes.


EXAMPLES

0)
{"RIGHT"}

Returns: 90

Turning 90 degrees right changes the azimuth from 0 to 90.

1)
{"LEFT", "LEFT", "TURN AROUND"}

Returns: 0

After turning left, the robot is facing west (azimuth 270). After turning left again, the robot is facing south (azimuth 180). Finally, turning around makes the robot face north, azimuth 0.

2)
{"LEFT 5", "RIGHT 10", "LEFT 15", "RIGHT 20", "LEFT 25", "RIGHT 30", "LEFT 35", "RIGHT 40"}

Returns: 20

There are four pairs of instructions, each pair making the robot turn right 5 degrees.

3)
{"RIGHT 59", "RIGHT", "RIGHT", "HALT", "LEFT", "LEFT", "LEFT"}

Returns: 239

The fourth instruction is "HALT", thus none of the following "LEFT" instructions are executed.

4)
{"TURN AROUND", "HALT", "LEFT 5", "HALT", "LEFT 5", "HALT"}

Returns: 180

Note that there might be more then one "HALT" instruction.

5)
{"LEFT", "LEFT", "LEFT", "LEFT", "LEFT", "HALT"}

Returns: 270

After the first 4 turns the robot is facing north again, and the fifth instruction turns him west. The last instruction doesn't change anything.

// END CUT HERE
#line 79 "AzimuthMonitoring.cxx"
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

class AzimuthMonitoring {
	public:
		int getAzimuth(vector <string> instructions) 
		{		
			int angle = 0;
			forv(i, instructions)
			{
				if(instructions[i] != "HALT")
				{
					if(instructions[i] == "LEFT")
						angle -= 90;
					else if(instructions[i] == "RIGHT")
						angle += 90;
					else if(instructions[i] == "TURN AROUND")
						angle += 180;
					else
					{
						char buf[6];
						int turn;
						sscanf(instructions[i].c_str(), "%s %d", buf, &turn);
						if(string(buf) == "LEFT")
							angle -= turn;
						else
							angle += turn;
					}
				}
				else
					break;
			}
			return angle % 360 >= 0 ? angle % 360: angle % 360 + 360;
		}
};
