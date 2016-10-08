// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
Prior to 1971, Britain used a system of coins that can be traced back to the time of Charlemagne.  The three main units of 
coinage were the penny, the shilling, and the pound.  There were 12 pennies in a shilling and 20 shillings in a pound.
Given a number pence of pennies, convert this amount into pounds, shillings, and pennies by first converting 
as many pennies as possible into pounds, and then converting as many of the remaining pennies as possible into shillings.
Return a vector <int> of size three containing the number of pounds, the number of shillings, and the number of
pennies, in that order. 


DEFINITION
Class:BritishCoins
Method:coins
Parameters:int
Returns:vector <int>
Method signature:vector <int> coins(int pence)


CONSTRAINTS
-pence is between 0 and 10000, inclusive.


EXAMPLES

0)
533

Returns: { 2,
  4,
  5 }

First, we make 2 pounds, leaving 53 pence.  Then, we make 4 shillings, leaving 5 pence.

1)
0

Returns: { 0,
  0,
  0 }

2)
6

Returns: { 0,
  0,
  6 }

3)
4091

Returns: { 17,
  0,
  11 }

4)
10000

Returns: { 41,
  13,
  4 }

// END CUT HERE
#line 65 "BritishCoins.cxx"
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

class BritishCoins {
	public:
		vector <int> coins(int pence) 
		{		
			vector <int> ret(3, 0);
			ret[0] = pence/240;
			ret[1] = (pence%240)/12;
			ret[2] = (pence%240)%12;
			return ret;
		}
};
