// BEGIN CUT HERE
// PROBLEM STATEMENT
// A string is considered to be a composite of several maximal segments of identical characters. For example, "aaabbaaac" is a composite of the segments: "aaa", "bb", "aaa" and "c". Given a string, return the average length of all the segments which form that string.


DEFINITION
Class:StringSegment
Method:average
Parameters:string
Returns:double
Method signature:double average(string s)


NOTES
-A return value with either an absolute or relative error of less than 1.0E-9 is considered correct.


CONSTRAINTS
-s will contain between 1 and 50 characters, inclusive.
-s will contain only lowercase letters ('a'-'z').


EXAMPLES

0)
"aaabbaaac"

Returns: 2.25

Average length of all the segments = ( 3 + 2 + 3 + 1 ) / 4 = 2.25

1)
"aabbccdd"

Returns: 2.0



2)
"abba"

Returns: 1.3333333333333333



// END CUT HERE
#line 48 "StringSegment.cxx"
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

class StringSegment {
	public:
		double average(string s) 
		{		
			vector <char> ret;
			ret.PB('0');
			forn(i, s.sz)
				if(ret[ret.sz-1] != s[i])
					ret.PB(s[i]);
			return double(s.sz) / (ret.sz - 1);
		}
};
