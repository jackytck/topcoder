// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
You have acquired a list of the math and verbal test scores from all the children in the county.
Write a class Average that contains a method belowAvg that takes two vector <int>,
math and verbal, representing the math and verbal scores of all of the children in the county, and returns the number of children who have a composite score
which is below average in the county.  

The composite score is defined to be the sum of a child's math and verbal scores.


DEFINITION
Class:Average
Method:belowAvg
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int belowAvg(vector <int> math, vector <int> verbal)


NOTES
-each element of math corresponds to the element with the same index in verbal.
-the number of children is the length of math and verbal.


CONSTRAINTS
-math and verbal will contain the same number of elements.
-math will contain between 1 and 50 elements, inclusive.
-each value in math and in verbal is between 200 and 800, inclusive.


EXAMPLES

0)
{200,250,700,700}
{400,400,400,400}

Returns: 2

The composite scores of the 4 children are 600, 650, 1100, and 1100 and the average composite score is 862.5, so 2 of the children are below average.

1)
{500,400}
{300,400}

Returns: 0

Both children have the same composite score 800 which is also the average. Neither are below average

2)
{293}
{799}

Returns: 0

3)
{400,400,400,400,400,400,401}
{400,400,400,400,400,400,400}

Returns: 6

The average composite score is just above 800, so 6 of the 7 children are below average.

// END CUT HERE
#line 65 "Average.cxx"
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

class Average {
	public:
		int belowAvg(vector <int> math, vector <int> verbal) 
		{		
			int ret = 0;
			double avg = accumulate(math.begin(), math.end(), 0.0)/math.sz + accumulate(verbal.begin(), verbal.end(), 0.0)/verbal.sz;
			forv(i, math)
				if(math[i] + verbal[i] < avg)
					ret++;
			return ret;
		}
};
