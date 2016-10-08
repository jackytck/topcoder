// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
A lucky ticket is an integer with exactly 2*n digits (written without leading zeroes), where the sum of the leftmost n digits is equal to the sum of the rightmost n digits.



You are given a string s, which contains only non-zero digits. Find the longest contiguous substring of s that is a lucky ticket and return its length. If there is no such lucky ticket, return 0 instead.



DEFINITION
Class:LuckyTicketSubstring
Method:maxLength
Parameters:string
Returns:int
Method signature:int maxLength(string s)


CONSTRAINTS
-s will contain between 1 and 50 characters, inclusive.
-s will contain non-zero digits ('1'-'9') only.


EXAMPLES

0)
"123231"

Returns: 6

The entire string, 123231, is a lucky ticket because the first 3 digits sum up to 1+2+3=6, and the last 3 digits sum up to 2+3+1=6.

1)
"74233285"

Returns: 4

4233 is the longest lucky ticket here.

2)
"986561517416921217551395112859219257312"

Returns: 36



3)
"1"

Returns: 0



4)
"112"

Returns: 2

A lucky ticket must contain an even number of digits.

// END CUT HERE
#line 64 "LuckyTicketSubstring.cxx"
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
#define clr(x) memset(x, 0, sizeof(x))
#define forn(i,n) for(__typeof(n) i = 0; i < (n); i++)
#define ford(i,n) for(int i = (n) - 1; i >= 0; i--)
#define For(i, st, en) for(__typeof(en) i = (st); i < (en); i++)

using namespace std;

class LuckyTicketSubstring {
	public:
		int maxLength(string s) 
		{		
			vector <int> digits;
			forn(i, s.sz)
			{
				int d;
				d = s[i] - '0';
				digits.push_back(d);
			}
			int len = s.sz;
			while(len > 1)
			{
				if(len % 2 != 0)
				{
					len--;
				}
				else
				{
					forn(i, s.sz - len + 1)
					{
						int r = 0, l = 0;
						forn(j, len / 2)
						{
							r += digits[i + j];
							l += digits[i + len / 2 + j];
						}
						if(r == l)
							return len;
					}
					len--;
				}
			}
			return 0;
		}
};
