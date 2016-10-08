// BEGIN CUT HERE
// PROBLEM STATEMENT
// Start with any integer between 00 and 99, inclusive, written as two digits (use a leading zero if the number is less than 10).  Add the two digits together.  Now concatenate the rightmost digit of the first number with the rightmost digit of the sum to get a new number.  If you repeat this process enough times, you'll end up back at the original number.  For example:

			    Combine Second Digits of
Start With    Add Digits    the Original and the Sum
------------------------------------------------------
    26     :   2+6 = 08   :   "6" and "8" = 68 
    68     :   6+8 = 14   :   "8" and "4" = 84
    84     :   8+4 = 12   :   "4" and "2" = 42
    42     :   4+2 = 06   :   "2" and "6" = 26

In this case, it took us 4 steps to get back to where we started, so we would return 4.  Starting with n, return the number of steps it takes to get back to n.

DEFINITION
Class:AdditionCycles
Method:cycleLength
Parameters:int
Returns:int
Method signature:int cycleLength(int n)


CONSTRAINTS
-n will be between 0 and 99, inclusive.


EXAMPLES

0)
26

Returns: 4

The example from the problem statement.  It goes 26->68->84->42->26, so there's 4 steps for the cycle.

1)
55

Returns: 3

The cycle is 55->50->05->55.  Remember to treat numbers under 10 as though there was a leading zero.

2)
0

Returns: 1

Zero comes back to zero at every step - so the length of the cycle is one (00->00)

3)
71

Returns: 12



// END CUT HERE
#line 59 "AdditionCycles.cxx"
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

class AdditionCycles {
	public:
		int sumDigit(int n)
		{
			return n/10 + n%10;
		}

		int cycleLength(int n) 
		{		
			int t = n, cnt = 0;
			while(cnt == 0 || t != n)
			{
				t = (t%10)*10 + sumDigit(t)%10;
				cnt++;
			}
			return cnt;
		}
};
