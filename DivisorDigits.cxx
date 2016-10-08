// BEGIN CUT HERE
// PROBLEM STATEMENT
// Create a class DivisorDigits containing a method howMany which takes an int number and returns how many digits in number divide evenly into number itself.

DEFINITION
Class:DivisorDigits
Method:howMany
Parameters:int
Returns:int
Method signature:int howMany(int number)


NOTES
-No number is divisible by 0.


CONSTRAINTS
-number will be between 10000 and 999999999.


EXAMPLES

0)
12345

Returns: 3

12345 is divisible by 1, 3, and 5.

1)
661232

Returns: 3

661232 is divisible by 1 and 2.

2)
52527

Returns: 0

52527 is not divisible by 5, 2, or 7.

3)
730000000

Returns: 0

Nothing is divisible by 0.  In this case, the number is also not divisible by 7 or 3.

// END CUT HERE
#line 53 "DivisorDigits.cxx"
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

class DivisorDigits {
	public:
		int howMany(int number) 
		{		
			int ret = 0;
			stringstream ss;
			ss << number;
			string no;
			ss >> no;
			forv(i, no)
				if(no[i] != '0' && number%(no[i]-'0')==0)
					ret++;
			return ret;
		}
};
