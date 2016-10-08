// BEGIN CUT HERE
// PROBLEM STATEMENT
// Massive numbers can be represented using the exponent notation. For example, 3^100 is 3 raised to the power of 100. 3 is the base and 100 is the exponent.

Suppose we want to compare two massive numbers. Instead of computing the exact value of each number we can rely on a useful mathematical trick. Suppose m = a^b and n = c^d are two massive numbers. Let R be a relationship operator: less, equal or greater. Then we have the following:

If b*Log(a) R d*Log(c) then it is also the case that m R n,
where a, b, c, d, m and n are defined above.

So which is greater: 3^100 or 2^150? Let's do the math. 100*Log(3) = 47.7..., 150*Log(2) = 45.2.... Since 47.7 > 45.2, our rule tells us that 3^100 > 2^150.

Given two numbers numberA and numberB return the larger number formatted exactly the same as the input. numberA and numberB will be formatted as <base>^<exponent>. Constraints will ensure that numberA and numberB are not equal.

DEFINITION
Class:MassiveNumbers
Method:getLargest
Parameters:string, string
Returns:string
Method signature:string getLargest(string numberA, string numberB)


NOTES
-In Java, the log of a number can be found with Math.log().
-In C++, the log of a number can be found with log().
-In C# and VB, the log of a number can be found with Math.Log().


CONSTRAINTS
-numberA and numberB will contain between 3 and 9 characters inclusive.
-numberA and numberB will be formatted as <base>^<exponent>, where <base> and <exponent> are integers between 1 and 1000 inclusive. <base> and <exponent> cannot have leading zeroes.
-The relative difference between b*Log(a) and d*Log(c) (where a, b, c and d are defined in the problem statement) will be at least 1e-6.


EXAMPLES

0)
"3^100"
"2^150"

Returns: "3^100"

Above example.

1)
"1^1000"
"2^1"

Returns: "2^1"

numberA is equal to 1, while numberB is equal to 2.

2)
"893^605"
"396^906"

Returns: "396^906"

3)
"999^1000"
"1000^999"

Returns: "999^1000"

// END CUT HERE
#line 66 "MassiveNumbers.cxx"
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

class MassiveNumbers {
	public:
		string getLargest(string numberA, string numberB) 
		{		
			int ab = 0, ae = 0, bb = 0, be = 0;
			sscanf(numberA.c_str(), "%d^%d", &ab, &ae);
			sscanf(numberB.c_str(), "%d^%d", &bb, &be);
			return ae*log(ab) > be*log(bb) ? numberA : numberB;
		}
};
