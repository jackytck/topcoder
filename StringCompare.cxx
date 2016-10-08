// BEGIN CUT HERE
// PROBLEM STATEMENT
// Your company is writing a spell-checker system, and you have been tasked with writing a function to determine how closely two words resemble each other.  The algorithm you are to use, albeit not a very good one, is to compare the two words character by character, and count how many times the characters in a given position are the same.  For instance, the words "TICK" and "TOCK" have a score of 3, since three characters (T, C, K) are the same.  Similarly, "CAT" and "DOG" score 0, since no letters match.

You are given strings a and b and are to return an int indicating the score (as defined above) of how closely the two match.

DEFINITION
Class:StringCompare
Method:simpleDifference
Parameters:string, string
Returns:int
Method signature:int simpleDifference(string a, string b)


NOTES
-The two strings may have different lengths.  In that case, your comparison should only process characters until it reaches the end of either string.


CONSTRAINTS
-a and b will each contain between 1 and 50 characters, inclusive.
-Each character of a and b will be 'A'-'Z'.


EXAMPLES

0)
"TICK"
"TOCK"

Returns: 3

The first example from the problem statement.

1)
"CAT"
"DOG"

Returns: 0

The second example from the problem statement.

2)
"APPLE"
"APPLES"

Returns: 5

Notice the lengths are different, so the most we can compare is 5 characters, which are all identical.

3)
"FANTASTIC"
"ANTASTIC"

Returns: 0

Here's an example of why this particular method is far from ideal.  In a situation like this, it appears one character is missing the from the second string, but by our algorithm as described, they score a 0 in similarlity.

4)
"ANTIDISESTABLISHMENTARIANISM"
"FLOCCIPAUCINIHILIPIFICATION"

Returns: 1

// END CUT HERE
#line 66 "StringCompare.cxx"
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

class StringCompare {
	public:
		int simpleDifference(string a, string b) 
		{		
			int ret = 0;
			for(int i=0; i<min(a.sz, b.sz); i++)
				if(a[i] == b[i])
					ret++;
			return ret;
		}
};
