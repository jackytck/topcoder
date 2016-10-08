// BEGIN CUT HERE
// PROBLEM STATEMENT
// You are developing a new software calculator. During the testing phase of the software you have found that the test cases use different symbols as the decimal point of 
floating numbers. Moreover some test cases contain useless space symbols. Now you want to
bring the numbers to a unified format.
You will be given a vector <string> numbers. Remove all space symbols (ASCII code 32) from the given numbers and 
replace each non-digit symbol with a dot symbol ('.'). You should not make any other changes to the numbers.


DEFINITION
Class:CalcTest
Method:uniform
Parameters:vector <string>
Returns:vector <string>
Method signature:vector <string> uniform(vector <string> numbers)


CONSTRAINTS
-numbers will have between 1 and 50 elements, inclusive.
-Each element of numbers will contain between 1 and 50 characters, inclusive.
-Each character in numbers will have ASCII code between 32 and 127, inclusive.
-Each element of numbers will contain at most one non-space non-digit symbol.
-Each element of numbers will contain at least one digit.


EXAMPLES

0)
{"1.5", "2$ 3", "12 3"}

Returns: {"1.5", "2.3", "123" }

1)
{",5", "3,", ".5", "3.", "000,000", "000 000"}

Returns: {".5", "3.", ".5", "3.", "000.000", "000000" }

2)
{"263C45233 ", " 2364A56", "B273664"}

Returns: {"263.45233", "2364.56", ".273664" }

// END CUT HERE
#line 45 "CalcTest.cxx"
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

class CalcTest {
	public:
		vector <string> uniform(vector <string> numbers) 
		{		
			vector <string> ret;
			forv(i, numbers)
			{
				string no = "";
				forv(j, numbers[i])
				{
					if(numbers[i][j] == ' ')
						continue;
					else if(isdigit(numbers[i][j]))
						no += numbers[i][j];
					else
						no += '.';
				}
				ret.PB(no);
			}
			return ret;
		}
};
