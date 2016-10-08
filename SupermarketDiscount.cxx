// BEGIN CUT HERE
// PROBLEM STATEMENT
// Three girls are shopping at a supermarket.  The supermarket is having a sale: "Spend $50 or more in a single transaction and get $10 off."  The girls realize that if they combine their purchases, they might be able to pay less than if they each pay separately.  For example, if they are buying a total of $46, $62 and $9 worth of goods, respectively, they can combine the $46 and $9 totals and make two purchase transactions ($55 and $62) to get $20 off.

You will be given a vector <int> goods, each element of which is the total cost of the goods purchased by one of the girls.  Return the minimal total cost required to purchase all the goods.  The girls are willing to combine their purchases as described above, but no girl is willing to split up her goods across multiple transactions.

DEFINITION
Class:SupermarketDiscount
Method:minAmount
Parameters:vector <int>
Returns:int
Method signature:int minAmount(vector <int> goods)


CONSTRAINTS
-goods will contain exactly 3 elements. 
-Each element of goods will be between 1 and 99, inclusive.


EXAMPLES

0)
{46, 62, 9}

Returns: 97

The example from the problem statement. 

1)
{50, 62, 93}

Returns: 175

The best decision is to pay separately. 

2)
{5, 31, 15}

Returns: 41

The only way to get the discount is to combine all three purchases into one transaction.


3)
{5, 3, 15}

Returns: 23

The girls have no chance of getting the discount.

// END CUT HERE
#line 53 "SupermarketDiscount.cxx"
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

class SupermarketDiscount {
	public:
		int minAmount(vector <int> goods) 
		{		
			int sum = 0, over = 0, cnt = 0;
			sum = accumulate(goods.begin(), goods.end(), 0);
			forv(i, goods)
				if(goods[i] >= 50)
				{
					cnt++;
					over = i;
				}
			if(cnt == 1)
			{
				int temp = 0;
				forn(i, 3)
				{
					if(i != over)
						temp += goods[i];
				}
				if(temp >= 50)
					cnt++;
			}
			else if(cnt == 0)
				if(sum >= 50)
					cnt++;
			return sum - cnt*10;
		}
};
