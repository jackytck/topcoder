// BEGIN CUT HERE
// PROBLEM STATEMENT
// Computers operate on binary numbers.  Almost all computation is done by
manipulating 0's and 1's.  Thus, in order for computers to use the numbers we
give them, they must convert them from base 10 (what we use normally) into
binary (base 2).  It is sometimes useful to determine how many bits a number
will take to represent, so that we can save memory.  For example, if a number
is smaller than 256, we can represent it with 8 bits.

A binary number's value is determined as follows:
For each '1' in the binary number add 2^i (2 to the power of i), where i is the
number of digits to the right of the '1'.
For example, 10100 binary, is equivalent to 20 in decimal.  The first 1 has 4
digits to the right, so it is equivalent to 2^4 = 16.  The other 1 has two
digits to the right of it, so it is 2^2 = 4.  16 + 4 = 20.  Another example is
1111, whose base 10 equivalent is 2^3 + 2^2 + 2^1 + 2^0 = 8 + 4 + 2 + 1 = 15.

Your task is to write a method that, given an int, will determine the minimum
number of bits that must be used to represent this number in binary.

DEFINITION
Class:Bits
Method:minBits
Parameters:int
Returns:int
Method signature:int minBits(int n)


CONSTRAINTS
-n is between 1 and 1,000,000, inclusive.


EXAMPLES

0)
32

Returns: 6

32 in binary is 100000 because 2^5 = 32, so a 1 with 5 0's to its right is 32.
Thus, we need 6 digits and the method return 6.

1)
12

Returns: 4

12 in binary is 1100, so the method returns 4.

2)
1

Returns: 1

3)
1500

Returns: 11

// END CUT HERE
#line 62 "Bits.cxx"
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

class Bits {
	public:
		int minBits(int n) 
		{		
			int ret = 0;
			while(n > 0)
			{
				ret++;
				n >>= 1;
			}
			return ret;
		}
};
