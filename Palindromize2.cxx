// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
A palindrome is a string that reads the same from left to right as it does from right to left. 
Given a String s, return a palindrome that is produced by changing the minimum possible 
number of characters in s. Changing a character means replacing it with any single
character at the same position.  You are not allowed to remove or add any characters.
If there are multiple answers, return the one that comes first alphabetically.


DEFINITION
Class:Palindromize2
Method:minChanges
Parameters:string
Returns:string
Method signature:string minChanges(string s)


CONSTRAINTS
-s will contain between 1 and 50 characters, inclusive.
-Each character of s will be a lowercase letter ('a'-'z').


EXAMPLES

0)
"ameba"

Returns: "abeba"

You can get "abeba" or "amema" with only 1 change. Among those two, "abeba" comes earlier alphabetically.

1)
"cigartragic"

Returns: "cigartragic"

The input is already a palindrome, so the best choice is to do 0 changes.

2)
"abcdef"

Returns: "abccba"



3)
"cxbpaxz"

Returns: "cxapaxc"



// END CUT HERE
#line 56 "Palindromize2.cxx"
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

class Palindromize2 {
	public:
		string minChanges(string s) 
		{		
			string ret;
			forn(i, s.sz)
			{
				if(s[i] != s[s.sz-1-i])
					ret += s[i] < s[s.sz-1-i] ? s[i]: s[s.sz-1-i];
				else
					ret += s[i];
			}
			return ret;
		}
};
