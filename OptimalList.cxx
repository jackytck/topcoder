// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
Billy is going to his grandmother's house. To help him do that, his mother has written down a detailed list of instructions for him to follow. Each instruction is a character 'N', 'S', 'W' or 'E', telling him to go exactly 1 block to the north, south, west or east, respectively. Billy's city consists of an infinitely large grid of streets, where each street extends infinitely to both sides, and the space between 2 adjacent streets going in the same direction is always 1 block.  Billy's house and his grandmother's house are both located at street corners in this city.

Billy knows that his mother does not always choose the shortest path.  Therefore, he wants to make a new list of instructions that will also lead him to his grandmother's house, but uses the minimum possible number of instructions.

You will be given inst, a string with the original list made by Billy's mom. Return the new list Billy wants. If
there are several solutions, return the one that comes first alphabetically.


DEFINITION
Class:OptimalList
Method:optimize
Parameters:string
Returns:string
Method signature:string optimize(string inst)


CONSTRAINTS
-inst will contain between 1 and 50 characters, inclusive.
-Each character of inst will be either 'N', 'S', 'W' or 'E'.


EXAMPLES

0)
"NENENNWWWWWS"

Returns: "NNNWWW"



1)
"NNEESSWW"

Returns: ""

Billy's grandmother lives in the same place as him, so he can get there without walking the big roundabout path his mother suggests.

2)
"NEWSNWESWESSEWSENSEWSEWESEWWEWEEWESSSWWWWWW"

Returns: "SSSSSSSSWWW"



3)
"NENENE"

Returns: "EEENNN"

The list is already optimal in the number of instructions, but Billy wants the alphabetically first optimal list.

// END CUT HERE
#line 57 "OptimalList.cxx"
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

class OptimalList {
	public:
		string optimize(string inst) 
		{		
			int x = 0, y = 0;
			forn(i, inst.sz)
			{
				switch(inst[i])
				{
					case 'N':
						y++;
						break;
					case 'E':
						x++;
						break;
					case 'S':
						y--;
						break;
					case 'W':
						x--;
						break;
				}
			}
			string sp("");
			if(x>=0 && y>=0)
			{
				forn(i, x)
					sp += "E";
				forn(i, y)
					sp += "N";
			}
			else if(x>=0 && y<=0)
			{
				forn(i, x)
					sp += "E";
				forn(i, -y)
					sp += "S";
			}
			else if(x<=0 && y>=0)
			{
				forn(i, y)
					sp += "N";
				forn(i, -x)
					sp += "W";
			}
			else if(x<=0 && y<=0)
			{
				forn(i, -y)
					sp += "S";
				forn(i, -x)
					sp += "W";
			}
			return sp;	
		}
};
