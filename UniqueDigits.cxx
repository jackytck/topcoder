// BEGIN CUT HERE
// PROBLEM STATEMENT
// Given an int n find all positive integers less than n whose digits are all different. Return the total number of such integers.

DEFINITION
Class:UniqueDigits
Method:count
Parameters:int
Returns:int
Method signature:int count(int n)


CONSTRAINTS
-n will be between 1 and 10000 inclusive.


EXAMPLES

0)
21

Returns: 19

We count all integers between 1 and 20, except 11.

1)
101

Returns: 90

2)
1001

Returns: 738

3)
1

Returns: 0

// END CUT HERE
#line 43 "UniqueDigits.cxx"
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

class UniqueDigits {
	public:
		int count(int n) 
		{		
			int ret = 0;
			For(i, 1, n)
			{
				stringstream ss;
				ss << i;
				string s;
				ss >> s;
				vector <int> digits(10, 0);
				forn(j, s.sz)
					digits[s[j]-'0']++;
				if(*max_element(digits.begin(), digits.end()) <= 1)
					ret++;
			}
			return ret;
		}
};
