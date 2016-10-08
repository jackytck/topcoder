// BEGIN CUT HERE
// PROBLEM STATEMENT
// You have just finished eating your Chinese food, and the waiter has brought you the bill.
You note the untaxed total on the bill, given as an int in total.
Additionally, you know the tax rate in your locale, given as an int in taxPercent.
Lastly, you have counted how much money you have, given as an int in money.

Since you feel the service was excellent, you want to give as large a tip as you can afford. You are to return the largest integral value of tip such that: 
total + floor(total*taxPercent/100) + floor(total*tip/100) <= money 
If there is no non-negative value of tip that satisfies the above inequality, return -1 (you don't have enough money to pay the bill and tax). 


DEFINITION
Class:WaiterTipping
Method:maxPercent
Parameters:int, int, int
Returns:int
Method signature:int maxPercent(int total, int taxPercent, int money)


NOTES
-total and money are given in cents
-Although certainly unusual, it is perfectly permissible to leave a tip that is larger than the original bill.


CONSTRAINTS
-total and money will be between between 100 and 100000, inclusive.
-taxPercent will be between 0 and 100, inclusive.


EXAMPLES

0)
500
10
600

Returns: 10

Here, you pay 500 for the bill and 50 for tax, leaving you 50 for the tip, which is 10% of the original bill total.

1)
500
10
604

Returns: 10

Similar to above, but here you have 54 cents for tip, but this will still only get you 10%.

2)
850
8
870

Returns: -1

Uh-oh, looks like you don't have enough money!

3)
226
48
584

Returns: 111

226 + floor(226*48/100) + floor(226*111/100) =
226 + floor(10848/100) + floor(25086/100) = 
226 + 108 + 250 =
584

4)
123
52
696

Returns: 415

123 + floor(123*52/100) + floor(123*415/100) =
123 + floor(6396/100) + floor(51045/100) = 
123 + 63 + 510 = 
696

5)
500
10
550

Returns: 0

// END CUT HERE
#line 93 "WaiterTipping.cxx"
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

class WaiterTipping {
	public:
		int maxPercent(int total, int taxPercent, int money) 
		{	
			int delta = money-total-floor(total*taxPercent/100.0);
			int tip = delta*100/total;
			while(delta > 0 && floor(total*(tip+1)/100.0) <= delta)
				tip++;
			return delta >= 0 ? tip : -1;
		}
};
