// BEGIN CUT HERE
// PROBLEM STATEMENT
// You are given a string composed of A's and B's.  Each A and B denotes a move performed by players A and B, respectively.  Return the length of the longest combo performed by either player.  A combo is a string of moves executed by a player that is not interrupted by the opposing player (see the examples for further clarification).

DEFINITION
Class:ComboLength
Method:howLong
Parameters:string
Returns:int
Method signature:int howLong(string moves)


CONSTRAINTS
-moves will contain between 2 and 50 characters inclusive.
-Each character of moves will be A or B.


EXAMPLES

0)
"AAA"

Returns: 3

Player A executes 3 moves in a row.

1)
"AAABBBBAA"

Returns: 4

Player A executes 2 combos of length 3 and 2 respectively.  Player B executes a single combo of length 4.

2)
"BBAABBAABBAABBAA"

Returns: 2

3)
"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"

Returns: 50

4)
"AAAAAAAAAAAAAAAAAAAAAAAAABAAAAAAAAAAAAAAAAAAAAAAAA"

Returns: 25

// END CUT HERE
#line 51 "ComboLength.cxx"
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

class ComboLength {
	public:
		int howLong(string moves) 
		{		
			int ret = 0;
			string A = moves, B = moves, temp;
			forv(i, moves)
			{
				if(moves[i] == 'A')
					B[i] = ' ';
				else
					A[i] = ' ';
			}
			stringstream ssa(A), ssb(B);
			while(ssa>>temp)
				ret >?= temp.sz;
			while(ssb>>temp)
				ret >?= temp.sz;
			return ret;
		}
};
