// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
You are to create a class Multiples with a method number, which takes three ints: min, max, and factor.



Given a range of integers from min to max (inclusive), determine how many numbers within that range are evenly divisible by factor.


DEFINITION
Class:Multiples
Method:number
Parameters:int, int, int
Returns:int
Method signature:int number(int min, int max, int factor)


NOTES
-If x is evenly divisble by y, there exists some integer k such that k * y = x.


CONSTRAINTS
-min will be between -1000000 and 1000000, inclusive.
-max will be between -1000000 and 1000000, inclusive.
-max will be greater than or equal to min.
-factor will be between 1 and 1000, inclusive.


EXAMPLES

0)
0
14
5

Returns: 3

The numbers 0, 5, and 10 are evenly divisible by 5, so this returns 3.

1)
7
24
3

Returns: 6

The numbers 9, 12, 15, 18, 21, 24 are evenly divisible by 3, so this returns 6.


2)
-123456
654321
997

Returns: 780

3)
-75312
407891
14

Returns: 34515

// END CUT HERE
#line 67 "Multiples.cxx"
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

class Multiples {
	public:
		int number(int min, int max, int factor) 
		{		
			int ret = 0;
			For(i, min, max+1)
				if(i%factor == 0)
					ret++;
			return ret;
		}
};
