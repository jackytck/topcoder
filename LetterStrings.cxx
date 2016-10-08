// BEGIN CUT HERE
// PROBLEM STATEMENT
// A letter-string is composed of letters ('A'-'Z','a'-'z') and dashes ('-').  The
length of a letter-string is the number of characters in it not including dashes
(in other words, the number of letters in the string).  Given a list of
letter-strings you will return the sum of their lengths.

Create a class LetterStrings that contains the method sum, which takes a
vector <string>, s, and returns an int representing the sum of the lengths of
the given letter-strings.


DEFINITION
Class:LetterStrings
Method:sum
Parameters:vector <string>
Returns:int
Method signature:int sum(vector <string> s)


CONSTRAINTS
-s will contain between 1 and 50 elements, inclusive.
-Each element of s will have length between 1 and 50, inclusive.
-Each element of s will contain only letters ('A'-'Z','a'-'z') and dashes ('-').


EXAMPLES

0)
{"-"}

Returns: 0

1)
{"A"}

Returns: 1

2)
{"-----Abc"}

Returns: 3

3)
{"-A-B-C-D", "--------EFGHI", "JKLMNOPQR", "---STU-VW-XYZ"}

Returns: 26

// END CUT HERE
#line 51 "LetterStrings.cxx"
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

class LetterStrings {
	public:
		int sum(vector <string> s) 
		{		
			int ret = 0;
			forv(i, s)
				forv(j, s[i])
					if(isalpha(s[i][j]))
						ret++;
			return ret;
		}
};
