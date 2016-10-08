// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
A k-double string is a non-empty string consisting of two equal length halves, where the first half differs from the second half at no more than k positions. For example, "contestcontest", "oopoop" and "aa" are 0-double strings. "contestkontest" is a 1-double string, and "poorpork", "artbat", and "yesyep" are 2-double strings. Obviously, all 0-double strings are also 1-double strings, all 1-double strings are also 2-double strings, etc.


You will be given a vector <string> str and an int k. Concatenate the elements of str to form one long string, and return the number of k-double substrings contained in that string.


If the same string exists in several different positions, count it as many times as it exists. Also, k-double substrings can overlap. See the examples for more details.


DEFINITION
Class:KDoubleSubstrings
Method:howMuch
Parameters:vector <string>, int
Returns:int
Method signature:int howMuch(vector <string> str, int k)


CONSTRAINTS
-str will contain between 1 and 5 elements, inclusive.
-Each element of str will contain between 1 and 50 characters, inclusive.
-Each element of str will contain only lowercase letters ('a'-'z').
-k will be between 0 and 100, inclusive.


EXAMPLES

0)
{"aa"}
0

Returns: 1

"aa" is the only 0-double substring.

1)
{"aaaa"}
0

Returns: 4

There are four substrings of even length and all of them are 0-double strings.

2)
{"contest", "kontest"}
1

Returns: 14

Each pair of consecutive letters form a 1-double substring and the whole string form one more 1-double substring.

3)
{"abacaba", "d", "abacaba"}
1

Returns: 34



4)
{"areyouready"}
2

Returns: 18



// END CUT HERE
#line 72 "KDoubleSubstrings.cxx"
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

class KDoubleSubstrings {
	public:
		int diff(string str)
		{
			int ret = 0;
			forn(i, str.sz/2)
				if(str[i] != str[str.sz/2 + i])
					ret++;
			return ret;
		}

		int howMuch(vector <string> str, int k) 
		{		
			string input;
			int ret = 0;
			forv(i, str)
				input += str[i];
			forn(i, input.sz)
			{
				For(j, i, input.sz)
				{
					if((j-i) % 2 == 0)
						continue;
					if(diff(input.substr(i, j-i+1)) <= k)
						ret++;
				}
			}
			return ret;
		}
};
