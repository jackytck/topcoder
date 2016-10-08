// BEGIN CUT HERE
// PROBLEM STATEMENT
// Consider a necklace composed of marbles of various colors arranged in a circle.  The colors are represented by uppercase letters.  We can describe a necklace with a string of characters as follows: start with any marble and go through all the marbles in either a clockwise or counter-clockwise direction, until the starting marble is reached again, meanwhile appending to the string the colors of the marbles in the order they are visited.  Obviously, there could be many different strings describing the same necklace.  For example, the necklace described by the string "CDAB" can also be described by seven other strings (see example 0).

You are given a string necklace containing the description of a necklace.  Return the description for that necklace that comes earliest alphabetically.


DEFINITION
Class:MarbleNecklace
Method:normalize
Parameters:string
Returns:string
Method signature:string normalize(string necklace)


CONSTRAINTS
-necklace will contain between 1 and 50 characters, inclusive.
-Each character of necklace will be an uppercase letter ('A'-'Z').


EXAMPLES

0)
"CDAB"

Returns: "ABCD"

This necklace can be described by the eight strings "CDAB", "DABC", "ABCD", "BCDA", "CBAD", "DCBA", "ADCB", "BADC". "ABCD" comes first lexicographically.

1)
"RGB"

Returns: "BGR"



2)
"TOPCODER"

Returns: "CODERTOP"

3)
"SONBZELGFEQMSULZCNPJODOWPEWLHJFOEW"

Returns: "BNOSWEOFJHLWEPWODOJPNCZLUSMQEFGLEZ"

// END CUT HERE
#line 49 "MarbleNecklace.cxx"
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

class MarbleNecklace {
	public:
		string normalize(string necklace) 
		{		
			string minS = necklace;
			forn(i, necklace.sz)
			{
				string t = necklace.substr(i) + necklace.substr(0, i);
				minS = min(t, minS);
			}
			reverse(necklace.begin(), necklace.end());
			string minSR = necklace;
			forn(i, necklace.sz)
			{
				string t = necklace.substr(i) + necklace.substr(0, i);
				minSR = min(t, minSR);
			}
			return min(minS, minSR);
		}
};
