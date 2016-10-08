// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
There is an unsafe way to write encrypted messages that works as follows.  At most one contiguous substring of the original string is reversed and enclosed in square brackets.  For example, the encrypted string "he[row oll]ld" represents the string "hello world".  You will be given s, a string encrypted with this method, and you must return the original unencrypted string.



DEFINITION
Class:ReversingBrackets
Method:removeBrackets
Parameters:string
Returns:string
Method signature:string removeBrackets(string s)


CONSTRAINTS
-s will contain between 1 and 50 characters, inclusive.
-Each character of s will be a lowercase letter ('a'-'z'), a space (' ') or a bracket ('[' and ']').
-s will contain either no bracket or exactly one '[' and one ']', and the '[' character will appear before the ']'.


EXAMPLES

0)
"he[row oll]ld"

Returns: "hello world"

The example from the problem statement.

1)
"ab[edc]f"

Returns: "abcdef"



2)
"topcoder"

Returns: "topcoder"

Note that there can be no brackets.

3)
"[desrever lla]"

Returns: "all reversed"

// END CUT HERE
#line 52 "ReversingBrackets.cxx"
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

class ReversingBrackets {
	public:
		string removeBrackets(string s) 
		{		
			string ret;
			if(s.find('[') != string::npos)
			{
				int start = s.find('[', 0) + 1, end = s.find(']', 0) - 1;
				string middle = s.substr(start, end-start+1);
				reverse(middle.begin(), middle.end());
				ret = s.substr(0, start-1) + middle + s.substr(end+2);
			}
			else
				ret = s;
			return ret;
		}
};
