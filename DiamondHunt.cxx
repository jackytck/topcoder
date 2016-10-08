// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
You are a diamond hunter looking for diamonds in a peculiar mine. This mine is a string of '<' and '>' characters, and each diamond is a substring of the form "<>". Each time you find a diamond, you remove it and the residual mine is updated by removing the 2 characters from the string.

For example, if you have a mine like "><<><>>><", you can start by removing the first appearance of "<>" to get "><<>>><", then remove the only remaining diamond to get "><>><". Note that this produces a new diamond which you can remove to get ">><". Since there are no diamonds left, your expedition is done.

Given a string mine, return the number of diamonds that can be found. Note that the order in which you remove simultaneous appearances of diamonds is irrelevant; any order will lead to the same result.


DEFINITION
Class:DiamondHunt
Method:countDiamonds
Parameters:string
Returns:int
Method signature:int countDiamonds(string mine)


CONSTRAINTS
-mine will contain between 1 and 50 characters, inclusive.
-Each character of mine will be either '<' or '>'.


EXAMPLES

0)
"><<><>>><"

Returns: 3

The example from the problem statement.

1)
">>>><<"

Returns: 0

No diamonds here.

2)
"<<<<<<<<<>>>>>>>>>"

Returns: 9



3)
"><<><><<>>>><<>><<><<>><<<>>>>>><<<"

Returns: 14



// END CUT HERE
#line 56 "DiamondHunt.cxx"
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

class DiamondHunt {
	public:
		int countDiamonds(string mine) 
		{		
			int cnt = 0;
			bool again = true;
			while(again)
			{
				again = false;
				forn(i, int(mine.sz) - 1)
				{
					if(mine[i] == '<' && mine[i+1] == '>')
					{
						mine.replace(i, 2, "");
						again = true;
						cnt++;
						break;
					}
				}
			}
			return cnt;
		}
};
