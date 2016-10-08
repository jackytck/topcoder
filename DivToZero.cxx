// BEGIN CUT HERE
// PROBLEM STATEMENT
// You are given an integer num from which you should replace the last two digits such that the resulting number is divisible by factor and is also the smallest possible number.  Return the two replacement digits as a string.
For instance:
if num = 275, and factor = 5, you would return "00" because 200 is divisible by 5.
if num = 1021, and factor = 11, you would return "01" because 1001 is divisible by 11.
if num = 70000, and factor = 17, you would return "06" because 70006 is divisible by 17.

DEFINITION
Class:DivToZero
Method:lastTwo
Parameters:int, int
Returns:string
Method signature:string lastTwo(int num, int factor)


CONSTRAINTS
-factor must be between 1 and 100, inclusive.
-num must be between 100 and 2,000,000,000, inclusive.


EXAMPLES

0)
2000000000
100

Returns: "00"

1)
1000
3

Returns: "02"

2)
23442
75

Returns: "00"

3)
428392
17

Returns: "15"

4)
32442
99

Returns: "72"

// END CUT HERE
#line 56 "DivToZero.cxx"
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

class DivToZero {
	public:
		string lastTwo(int num, int factor) 
		{		
			int i = 0;
			while((num/100*100+i)%factor != 0)
				i++;
			string ret = "  ";
			ret[0] = '0'+i/10;
			ret[1] = '0'+i%10;
			return ret;
		}
};
