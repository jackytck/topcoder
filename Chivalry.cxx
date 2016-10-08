// BEGIN CUT HERE
// PROBLEM STATEMENT
// Two lines (or queues) of people often have to merge into a single-file line.  But, chivalry is not dead!  When a man and a woman are about to merge, the man will always let the woman go first.

Given two lines of both men and women, write a method getOrder which will determine the genders of the people in the final line.  If two women are at the front of both lines, the woman from the first line goes first. Likewise, if two men are at the front of both lines, the man from the first line goes first.  Then, the people at the front of both lines are compared again.

Each input line will be a string of letters, each one representing either a man or a woman.  Each man will be represented by an 'M' and each woman by a 'W'.  The output should be of the same form.  The front of each line is the left-most character of the string.

DEFINITION
Class:Chivalry
Method:getOrder
Parameters:string, string
Returns:string
Method signature:string getOrder(string first, string second)


CONSTRAINTS
-first and second will each be between 1 and 50 characters long, inclusive.
-first and second will consist of the characters 'M' and 'W' only.


EXAMPLES

0)
"M"
"W"

Returns: "WM"

1)
"MM"
"MW"

Returns: "MMMW"

Because of the 'tie breaker' rules, the first man from the first line goes first.  Then, the second man from the first line goes, then the rest of the people (both from the second line.)

2)
"MMMM"
"W"

Returns: "WMMMM"

3)
"M"
"WWW"

Returns: "WWWM"

// END CUT HERE
#line 52 "Chivalry.cxx"
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

class Chivalry {
	public:
		string getOrder(string first, string second) 
		{		
			string ret;
			int f = 0, s = 0;
			while(f != first.sz || s != second.sz)
			{
				if(f!=first.sz && s!=second.sz)
				{
					if(first[f] == second[s])
					{
						ret += first[f];
						f++;
					}
					else if(first[f] == 'W')
					{
						ret += first[f];
						f++;
					}
					else
					{
						ret += second[s];
						s++;
					}
				}
				else if(f!=first.sz)
				{
					ret += first[f];
					f++;
				}
				else
				{
					ret += second[s];
					s++;
				}	
			}
			return ret;
		}
};
