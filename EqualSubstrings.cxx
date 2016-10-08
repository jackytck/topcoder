// BEGIN CUT HERE
// PROBLEM STATEMENT
// You will be given a string str consisting of lowercase letters.  You will return a vector <string> containing elements x and y in that order.  The returned strings x and y must satisfy:

1) The string xy (x with y concatenated on the end) must equal str.
2) The number of a's in x must equal the number of b's in y.
3) If multiple solutions are possible, use the one that maximizes the length of x.
  See the examples for further clarifications.

DEFINITION
Class:EqualSubstrings
Method:getSubstrings
Parameters:string
Returns:vector <string>
Method signature:vector <string> getSubstrings(string str)


CONSTRAINTS
-str will contain between 1 and 50 characters inclusive.
-Each character in str will be a lowercase letter ('a'-'z').


EXAMPLES

0)
"aaabbb"

Returns: { "aaa",  "bbb" }

Here we can split str right down the center.

1)
"bbbaaa"

Returns: { "bbb",  "aaa" }

Again the center works.

2)
"bbbbbb"

Returns: { "bbbbbb",  "" }

y can be empty.

3)
"aaaaaa"

Returns: { "",  "aaaaaa" }

x can be empty.

4)
"abjlkbjalkbjaljsbljbalb"

Returns: { "abjlkbjalkbjaljs",  "bljbalb" }

Make sure to maximize the length of x.

// END CUT HERE
#line 62 "EqualSubstrings.cxx"
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

class EqualSubstrings {
	public:
		bool check(string x, string y)
		{
			int a = 0, b = 0;
			forv(i, x)
				if(x[i] == 'a')
					a++;
			forv(i, y)
				if(y[i] == 'b')
					b++;
			return a == b;
		}
		
		vector <string> getSubstrings(string str) 
		{		
			vector <string> ret(2, "");
			forn(i, str.sz+1)
			{
				string x = str.substr(0, i);
				string y = str.substr(min(i,str.sz-1), str.sz-i);
				if(check(x, y))
				{
					ret[0] = x;
					ret[1] = y;
				}
			}
			return ret;
		}
			
};
