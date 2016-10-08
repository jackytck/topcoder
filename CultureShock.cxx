// BEGIN CUT HERE
// PROBLEM STATEMENT
// Bob and Doug have recently moved from Canada to the United States, and they are confused by this strange letter, "ZEE". They need your assistance. Given a string text, replace every occurrence of the word, "ZEE", with the word, "ZED", and return the result.


Note that if "ZEE" is just part of a larger word (for example, "ZEES"), it should not be altered.


DEFINITION
Class:CultureShock
Method:translate
Parameters:string
Returns:string
Method signature:string translate(string text)


CONSTRAINTS
-text will contain between 1 and 50 characters inclusive.
-Each character in text will either be a space (' '), or a capital letter ('A'-'Z').
-text will have precisely one space between consecutive words, and it will have no leading or trailing spaces.


EXAMPLES

0)
"THE TWENTY SIXTH LETTER OF THE ALPHABET IS ZEE"

Returns: "THE TWENTY SIXTH LETTER OF THE ALPHABET IS ZED"

There is precisely one occurrence of "ZEE" in this line of text, so it should be replaced with "ZED".

1)
"ZEE"

Returns: "ZED"

2)
"SPELLING IN ENGLISH IS EZEE"

Returns: "SPELLING IN ENGLISH IS EZEE"

The "ZEE" at the end of this line should not be altered since it is part of a larger word.

3)
"ZEE ZEE ZED ZEDS ZEE ZEES"

Returns: "ZED ZED ZED ZEDS ZED ZEES"

// END CUT HERE
#line 51 "CultureShock.cxx"
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

class CultureShock {
	public:
		string translate(string text) 
		{		
			string ret, input;
			stringstream ss(text);
			while(ss >> input)
			{
				ret += input == "ZEE" ? "ZED" : input;
				ret += ' ';
			}
			return ret.substr(0, ret.sz-1);
		}
};
