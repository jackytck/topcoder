// BEGIN CUT HERE
// PROBLEM STATEMENT
// Given a number x, we can define p(x) as the product of the digits of x.  We can then form a sequence x, p(x), p(p(x))...  The persistence of x is then defined as the index (0-based) of the first single digit number in the sequence.  For example, using 99, we get the sequence 99, 9*9 = 81, 8*1 = 8.  Thus, the persistence of 99 is 2.  You will be given n, and you must return its persistence.

DEFINITION
Class:PersistentNumber
Method:getPersistence
Parameters:int
Returns:int
Method signature:int getPersistence(int n)


CONSTRAINTS
-n will be between 0 and 2,000,000,000, inclusive.


EXAMPLES

0)
99

Returns: 2

The example from the problem statement.

1)
268

Returns: 4

The sequence here is 268, 96, 54, 20, 0.

2)
6

Returns: 0

6 is already a single-digit number.

3)
68889789

Returns: 3



4)
86898

Returns: 7



// END CUT HERE
#line 56 "PersistentNumber.cxx"
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

class PersistentNumber {
	public:
		int getPersistence(int n) 
		{		
			int cnt = 0;
			while(n >= 10)
			{
				n = getProduct(n);
				cnt++;
			}
			return cnt;
		}
		int getProduct(int n)
		{
			int ret = 1;
			while(n != 0)
			{
				ret *= n%10;
				n /= 10;
			}
			return ret;
		}
};
