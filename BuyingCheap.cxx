// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
Steve would like to buy a new car. He isn't wealthy, so he would prefer a reasonably cheap car. The only problem is that the quality of the cheapest cars is... let's say questionable.



Thus Steve decided to make a list of car prices and to buy a car with the third lowest price.



You will be given a vector <int> prices. 
The same price may occur multiple times in prices, but it should count only once in the ordering of available prices. See Example 1 for further clarification.



Write a function that returns the third lowest price in this list. If there are less than three different car prices in prices, your method should return -1.


DEFINITION
Class:BuyingCheap
Method:thirdBestPrice
Parameters:vector <int>
Returns:int
Method signature:int thirdBestPrice(vector <int> prices)


CONSTRAINTS
-prices contains between 1 and 50 elements, inclusive.
-Each element in prices will be between 1 and 1000, inclusive.


EXAMPLES

0)
{10, 40, 50, 20, 70,
 80, 30, 90, 60}

Returns: 30

1)
{10, 10, 10, 10, 20,
 20, 30, 30, 40, 40}

Returns: 30

The lowest price is 10, the second lowest is 20 and the third lowest is 30.

2)
{10}

Returns: -1

3)
{80, 90, 80, 90, 80}

Returns: -1

// END CUT HERE
#line 61 "BuyingCheap.cxx"
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

class BuyingCheap {
	public:
		int thirdBestPrice(vector <int> prices) 
		{		
			int ret = -1, cnt = 0, temp = 0;
			sort(prices.begin(), prices.end());
			forv(i, prices)
			{
				if(prices[i] != temp)
				{
					cnt++;
					temp = prices[i];
					if(cnt == 3)
					{
						ret = temp;
						break;
					}
				}
			}
			return ret;
		}
};
