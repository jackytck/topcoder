// BEGIN CUT HERE
// PROBLEM STATEMENT
// An integer N greater than 1 is called almost prime if and only if the following conditions hold:

N is not prime.  In other words, it is divisible by some positive integer other than 1 and itself.
Each positive divisor of N (other than 1) is greater than 10.


Return the smallest almost prime number that is strictly greater than m.


DEFINITION
Class:AlmostPrimeNumbers
Method:getNext
Parameters:int
Returns:int
Method signature:int getNext(int m)


CONSTRAINTS
-m will be between 1 and 10^6, inclusive.


EXAMPLES

0)
200

Returns: 209

201 is divisible by 3, which is less than 10, so 201 is not almost prime.  202, 204, 206, and 208 are all divisible by 2.  203 is divisible by 7, 205 by 5, and 207 by 3.  So, the smallest almost prime number greater than 200 is 209 = 11*19.

1)
666

Returns: 667

667 = 23*29, so it's almost prime.

2)
1000

Returns: 1003

3)
1591

Returns: 1633

4)
6

Returns: 121

The smallest almost prime number is 11*11 = 121.

// END CUT HERE
#line 59 "AlmostPrimeNumbers.cxx"
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

class AlmostPrimeNumbers {
	public:
		int getNext(int m) 
		{		
			int ap = m;
			vector<int> divisors;
			while(++ap)
			{
				forn(i, ap)
				{
					if(i != 0 && i != 1 && ap % i == 0) 
					{
						if(i <= 10) goto again;
						divisors.PB(i);
					}
				}
				if(divisors.sz == 0) continue; 
				return ap;
				again:;
			}
			return 0;
		}
};
