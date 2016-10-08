// BEGIN CUT HERE
// PROBLEM STATEMENT
// You are given three positive integers, X, Y and P. Return the least sum of two positive integers a and b such that P is a divisor of a*X+b*Y.

DEFINITION
Class:TheEquation
Method:leastSum
Parameters:int, int, int
Returns:int
Method signature:int leastSum(int X, int Y, int P)


NOTES
-The answer is never greater than 2*P: if a = P and b = P, then P is definitely a divisor of a*X+b*Y.


CONSTRAINTS
-X, Y and P will each be between 1 and 1000, inclusive.


EXAMPLES

0)
2
6
5

Returns: 3

When a=2 and b=1, a*X+b*Y is 10, which is a multiple of P=5. No other valid pair of values for a and b has a smaller sum.

1)
5
5
5

Returns: 2

Don't forget that a and b must be positive.

2)
998
999
1000

Returns: 501



3)
1
1
1000

Returns: 1000



4)
347
873
1000

Returns: 34



// END CUT HERE
#line 70 "TheEquation.cxx"
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
#define For(i, st, en) for(__typeof(en) i = (st); i < (en); i++)

using namespace std;

class TheEquation {
	public:
		int leastSum(int X, int Y, int P) 
		{		
			vector <int> sum;
			For(i, 1, P+1)
			{
				For(j, 1, P+1)
				{
					if((i*X + j*Y) % P == 0)
						sum.PB(i+j);
				}
			}
			sort(sum.begin(), sum.end());
			return sum[0];
		}
};
