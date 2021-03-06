// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
The binary numeral system (base 2 numerals) represents numeric values using two symbols: 0 and 1. 
Counting in binary is similar to counting in any other number system.
If you want to increase a number by 1, try to increase its last digit by 1.  
If this fails, set the last digit to zero, and try to increase the previous digit, 
and so on, until you succeed.



For example, the decimal sequence:
1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...
converted to binary looks as follows:
1, 10, 11, 100, 101, 110, 111, 1000, 1001, 1010, 1011, ...



You are given a string x that contains the binary representation of a positive integer X.
Write a method that will return a string containing the binary representation of (X+1).
The returned string must not contain leading zeroes.


DEFINITION
Class:BinaryIncrementation
Method:plusOne
Parameters:string
Returns:string
Method signature:string plusOne(string x)


CONSTRAINTS
-x will contain between 1 and 30 characters, inclusive.
-Each character in x will be a one ('1') or a zero ('0').
-The first character in x will be a one ('1').


EXAMPLES

0)
"10011"

Returns: "10100"

"10011" is binary for 16+2+1 = 19. The next integer is 20 = 16+4, which is "10100" in binary.

1)
"10000"

Returns: "10001"



2)
"1111"

Returns: "10000"

Be careful not to miss the case when the result is a power of two.

3)
"1"

Returns: "10"



4)
"101010101010101010101010101010"

Returns: "101010101010101010101010101011"



// END CUT HERE
#line 77 "BinaryIncrementation.cxx"
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

class BinaryIncrementation {
	public:
		string plusOne(string x) 
		{		
			string ret;
			int add = 1;
			ford(i, x.sz)
			{
				if(x[i]-'0' + add == 2)
				{
					ret = '0' + ret;
					add = 1;
				}
				else if(x[i]-'0' + add == 1)
				{
					ret = '1' + ret;
					add = 0;
				}
				else
				{
					ret = '0' + ret;
				        add = 0;
				}	
			}
			if(add == 1)
				ret = '1' + ret;
			return ret;
		}
};
