// BEGIN CUT HERE
// PROBLEM STATEMENT
// For those who file jointly and have a taxable income of at least $100,000 
the tax for 2004 is calculated from the following table. To calculate
your tax, you find
the appropriate bracket for your taxable income, multiply your taxable income by the multiplier,
and then subtract the subtraction value.

    At_least   Less_than    Multiplier       Subtraction
    100,000     117,250        25%             6,525.00

    117,250     178,650        28%            10,042.50

    178,650     319,100        33%            18,975.00

    319,100        -           35%            25,357.00

           
When I find out how much tax someone had to pay, I want to be able to figure 
out what their taxable income was.  Create a class TaxTable that contains a
method income that is given the taxAmount and calculates the taxable income whose
tax is closest to taxAmount. This result is returned,
rounded to the nearest dollar (.5 rounds up). If the
taxAmount is too low to have come from the table, return -1.


DEFINITION
Class:TaxTable
Method:income
Parameters:int
Returns:int
Method signature:int income(int taxAmount)


CONSTRAINTS
-taxAmount will be between 0 and 1,000,000, inclusive.
-All values within 1e-6 of the taxable income corresponding to taxAmount will round to the same integer.


EXAMPLES

0)
47025

Returns: 200000



   The tax on $200,000  is  33% * 200,000 - 18975 
which is 47025.




1)
1000

Returns: -1



   Anybody who has taxable income of at least $100,000 has a tax that is
   greater than $1000


2)
47026

Returns: 200003



   The tax on $200,000 is exactly $47,025. For each dollar above that we must pay
   33 cents additional tax.  So the income that results in a tax of exactly
   $47,026 is $200,003.0303030303.... which rounds to $200,003. Note that a 
   return of 200002 would be incorrect, even though the tax on that amount would
   be 47025.66 which is close to 47026.

3)
86304

Returns: 319027

4)
22792

Returns: 117266

// END CUT HERE
#line 91 "TaxTable.cxx"
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

class TaxTable {
	public:
		int income(int taxAmount) 
		{		
			double ret;
			if((taxAmount+6525.0)/.25 < 100000)
				ret = -1;
			else if((taxAmount+6525.0)/.25 < 117250)
				ret = (taxAmount+6525.0)/.25;
			else if((taxAmount+10042.5)/.28 < 178650)
				ret = (taxAmount+10042.5)/.28;
			else if((taxAmount+18975.0)/.33 < 319100)
				ret = (taxAmount+18975.0)/.33;
			else
				ret = (taxAmount+25357)/.35;
			return ret-int(ret)>=0.5 ? int(ret)+1 : int(ret);
		}
};
