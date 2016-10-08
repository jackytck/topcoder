// BEGIN CUT HERE
// PROBLEM STATEMENT
// In this problem, you will simulate a program that controls the actions of a progress indicator. The indicator is a single bar character in the middle of the screen with one of 4 states: '|', '-', '\', and '/'. The program is given as a sequence of instructions in the form:
<instr> <secs>
where <instr> represents one of 4 possible actions, and <secs> is the action's duration in seconds. The action is performed once each second. The 4 possible actions are::
'L': Spin left.  If the bar is in state '|', it goes to '\'.  State '\' goes to '-', '-' goes to '/', and '/' goes to '|'.
'R': Spin right.  This is the exact opposite of 'L': '\' goes to '|', '|' goes to '/', '/' goes to '-', and '-' goes to '\'.
'S': Stay.  The bar remains in its current state.
'F': Flip.  The bar is rotated 90 degrees: '\' becomes '/', '/' becomes '\', '-' becomes '|', and '|' becomes '-'.
So, the sequence "F03L02" and the starting state of '-' leads to the following sequence: "-|-|\-".
You are given a program and a startState. Return a string containing the sequence of states produced by the program. The ith character of the string is the state of the progress indicator after i seconds. At time 0, the indicator is in its initial state, so the first character of the return value is always startState.

DEFINITION
Class:IndicatorMotion
Method:getMotion
Parameters:string, char
Returns:string
Method signature:string getMotion(string program, char startState)


NOTES
-In the examples the character '\' appears as '\\' because of the C++/Java syntax for escaping characters.


CONSTRAINTS
-startState will be '|', '-', '\' or '/'.
-program will contain exactly 3*k characters, where k is an integer between 0 and 10, inclusive.
-For each k, the (3*k)-th character in program will be one of 'L', 'R', 'F' or 'S'.
-For each k, the (3*k+1)-th and (3*k+2)-th characters of program will be digits ('0'-'9').


EXAMPLES

0)
"F03L02R03S02F04"
'-'

Returns: "-|-|\\-\\|///\\/\\/"

This leads to the following sequence of states (below each state is the action performed during that second):
-|-|\-\|///\/\/
.FFFLLRRRSSFFFF


1)
"F10R01F10"
'/'

Returns: "/\\/\\/\\/\\/\\/-|-|-|-|-|-"

2)
""
'/'

Returns: "/"

Watch out for empty programs!

3)
"F00R00L00S00"
'\\'

Returns: "\\"

And "empty" programs.

// END CUT HERE
#line 69 "IndicatorMotion.cxx"
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

class IndicatorMotion {
	public:
		string getMotion(string program, char startState) 
		{		
			string ret = "";
			ret += startState;
			char states[] = {'|', '/', '-', '\\'};
			int state;
			for(state=0; state<4; state++)
				if(states[state] == startState)
					break;
			for(int i=0; i<program.sz; i+=3)
			{
				int time = 10*(program[i+1]-'0') + program[i+2]-'0';
				while(time != 0)
				{
					if(program[i] == 'L')
					{
						state--;
						state = state>=0 ? state%4 : 4+state%4;
					}
					else if(program[i] == 'R')
					{
						state++;
						state = state>=0 ? state%4 : 4+state%4;
					}
					else if(program[i] == 'F')
					{
						state += 2;
						state = state>=0 ? state%4 : 4+state%4;
					}
					ret += states[state];
					time--;
				}
			}
			return ret;
		}
};
