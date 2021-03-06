// BEGIN CUT HERE
// PROBLEM STATEMENT
// At a certain company, a worker is paid an hourly rate of P1 dollars for the first 200 hours he works each month. He is paid an hourly rate of P2 dollars for the remaining hours. Return the minimum number of hours he must work this month to earn salary dollars.


DEFINITION
Class:SalaryCalculator
Method:calcHours
Parameters:int, int, int
Returns:double
Method signature:double calcHours(int P1, int P2, int salary)


NOTES
-Your return value must have an absolute or relative error less than 1e-9.


CONSTRAINTS
-P1 will be between 1 and 100, inclusive. 
-P2 will be between 1 and 100, inclusive. 
-salary will be between 1 and 1,000,000, inclusive. 


EXAMPLES

0)
10
15
1000

Returns: 100.0

The worker is paid 10 dollars per hour for the first 200 hours, and 15 dollars per hour for any hours beyond that.  To earn 1000 dollars, he only needs to work 100 hours at 10 dollars per hour.

1)
10
15
3000

Returns: 266.6666666666667

The worker is paid 10 dollars per hour for the first 200 hours for a total of 2000 dollars.  To earn the extra 1000 dollars, he must work approximately 66.67 hours at 15 dollars per hour.

2)
100
1
1000000

Returns: 980200.0

The company does not like to pay for overtime work.

3)
17
23
973546

Returns: 42380.260869565216

4)
82
8
12140

Returns: 148.0487804878049



// END CUT HERE
#line 71 "SalaryCalculator.cxx"
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

class SalaryCalculator {
	public:
		double calcHours(int P1, int P2, int salary) 
		{		
			return salary <= P1*200 ? double(salary)/P1 : 200+double(salary-200*P1)/P2;
		}
};
