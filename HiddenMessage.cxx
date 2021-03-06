// BEGIN CUT HERE
// PROBLEM STATEMENT
// Some texts contain hidden messages. In the context of this problem, the hidden message of a text is composed of the first letter from each word in the text, in the order they appear.

Given a string text, consisting of only lowercase letters and spaces, return the hidden message.  A word is a maximal sequence of consecutive letters.  There may be multiple spaces between words.  Also, text may contain only spaces.


DEFINITION
Class:HiddenMessage
Method:getMessage
Parameters:string
Returns:string
Method signature:string getMessage(string text)


CONSTRAINTS
-text will contain between 1 and 50 characters, inclusive.
-Each character of text will be either a lowercase letter ('a'-'z'), or a space (' ').


EXAMPLES

0)
"compete online design event rating"

Returns: "coder"

Taking the first letter from each word yields the return "coder".

1)
"  c    o d     e      r    "

Returns: "coder"

Watch out for the leading spaces.

2)
"round  elimination during  onsite  contest"

Returns: "redoc"

"coder" written backwards.

3)
" "

Returns: ""

Since there are no words here, the empty string must be returned.

// END CUT HERE
#line 53 "HiddenMessage.cxx"
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

class HiddenMessage {
	public:
		string getMessage(string text) 
		{		
			istringstream is(text);
			string temp, ret;
			while(is >> temp)
				ret += temp[0];
			return ret;
		}
};
