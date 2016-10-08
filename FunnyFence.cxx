// BEGIN CUT HERE
// PROBLEM STATEMENT
// A sequence of characters is called a fence if it consists of alternating '|' and '-' characters, like "|-|-|-|" or "-|-|" (quotes for clarity only). Notice that "|-||-|" or "--" are not fences, because each contains two equal characters adjacent to each other.

Given a string s, find the longest consecutive substring of it that is a fence, and return its length.

DEFINITION
Class:FunnyFence
Method:getLength
Parameters:string
Returns:int
Method signature:int getLength(string s)


CONSTRAINTS
-s will contain between 1 and 50 characters, inclusive.
-Each character of s will be either '|' or '-'.


EXAMPLES

0)
"|-|-|"

Returns: 5

The entire string is a fence.

1)
"-|-|-|-"

Returns: 7

Still a fence.

2)
"||||||"

Returns: 1

A fence can be just 1 character long, so every 1 character substring here is a fence.

3)
"|-||-|-"

Returns: 4

The last 4 characters form the longest consecutive substring that is a fence.

4)
"|-|---|-|---|-|"

Returns: 5

"-|-|-" right in the middle gives the longest fence.

5)
"|||-||--|--|---|-||-|-|-|--||---||-||-||-|--||"

Returns: 8

// END CUT HERE
#line 64 "FunnyFence.cxx"
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

class FunnyFence {
	public:
		int getLength(string s) 
		{		
			int ret = 0;
			forn(i, s.sz)
			{
				int len = 1, j;
				for(j = i; j < s.sz-1; j++)
					if(s[j+1] == s[j])
						break;
				len = j - i + 1;
				ret = max(ret, len);
			}
			return ret;
		}
};
