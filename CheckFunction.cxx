// BEGIN CUT HERE
// PROBLEM STATEMENT
// You are given a string code containing a message composed entirely of decimal digits ('0'-'9'). Each digit consists of some number of dashes (see diagram below). A "check function" of a message is defined as the total number of dashes in the message. Return the value of the check function for the message represented in code.




DEFINITION
Class:CheckFunction
Method:newFunction
Parameters:string
Returns:int
Method signature:int newFunction(string code)


NOTES
-0 consists of 6 dashes, 1 consists of 2 dashes, 2 consists of 5 dashes, 3 consists of 5 dashes, 4 consists of 4 dashes, 5 consists of 5 dashes, 6 consists of 6 dashes, 7 consists of 3 dashes, 8 consists of 7 dashes, 9 consists of 6 dashes.


CONSTRAINTS
-code will contain between 1 and 50 characters, inclusive.
-Each character in code will be a digit ('0'-'9').


EXAMPLES

0)
"13579"

Returns: 21

1 consists of 2 dashes;
3 consists of 5 dashes;
5 consists of 5 dashes;
7 consists of 3 dashes;
9 consists of 6 dashes;
2 + 5 + 5 + 3 + 6 = 21.

1)
"02468"

Returns: 28

2)
"73254370932875002027963295052175"

Returns: 157

// END CUT HERE
#line 51 "CheckFunction.cxx"
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

class CheckFunction {
	public:
		int newFunction(string code) 
		{		
			int ret = 0;
			int dashes[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
			forn(i, code.sz)
				ret += dashes[code[i]-'0'];
			return ret;
		}
};
