// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
A palindrome is a string that reads the same from left to right as it does from right to left.  Given a string s, return the shortest palindrome that can be produced by adding zero or more characters to the right end of s.  There is always one unique answer.


DEFINITION
Class:Palindromize
Method:minAdds
Parameters:string
Returns:string
Method signature:string minAdds(string s)


CONSTRAINTS
-s will contain between 1 and 50 characters, inclusive.
-Each character of s will be a lowercase letter ('a'-'z').


EXAMPLES

0)
"add"

Returns: "adda"

Add 'a' to make a palindrome. "adddda" is also a valid palindrome, but it is not the shortest possible one.

1)
"cigartragic"

Returns: "cigartragic"

This is already a palindrome, so the shortest solution is to add 0 letters.

2)
"redocpot"

Returns: "redocpotopcoder"



3)
"acaba"

Returns: "acabaca"



4)
"abczyxyz"

Returns: "abczyxyzcba"



// END CUT HERE
#line 59 "Palindromize.cxx"
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

class Palindromize {
	public:
		bool check(string s)
		{
			bool ret = true;
			forn(i, s.sz)
				if(s[i] != s[s.sz-1-i])
					ret = false;
			return ret;
		}

		string minAdds(string s) 
		{		
			forn(i, s.sz)
			{
				string add = s.substr(0, i);
				reverse(add.begin(), add.end());
				if(check(s + add))
				{
					s += add;
					break;
				}
			}
			return s;
		}
};
