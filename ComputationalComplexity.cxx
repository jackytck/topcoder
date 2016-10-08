// BEGIN CUT HERE
// PROBLEM STATEMENT
// You are testing several algorithms and you want to find the fastest one for your task. Computational complexities of these algorithms will be given to you in three vector <int>s - constant, power and logPower. The ith algorithm needs on average constant[i]*Npower[i]*lnlogPower[i](N) operations to solve your task.

Given an int N, the size of your task, return the 0-based index of the fastest algorithm. In case of a tie, return the smallest index.

DEFINITION
Class:ComputationalComplexity
Method:fastestAlgo
Parameters:vector <int>, vector <int>, vector <int>, int
Returns:int
Method signature:int fastestAlgo(vector <int> constant, vector <int> power, vector <int> logPower, int N)


NOTES
-ln(x) in the formula means natural logarithm of x. It can be computed as: - Math.log(x) in java - log(x) in C++ - Math.Log(x) in C# and VB.


CONSTRAINTS
-constant, power and logPower will have the same number of elements.
-constant, power and logPower will each have between 1 and 50 elements, inclusive.
-N will be between 1 and 1000, inclusive.
-All elements of power and logPower will be between 0 and 5, inclusive.
-All elements of constant will be between 1 and 100, inclusive.


EXAMPLES

0)
{5, 50, 45}
{2, 1, 1}
{0, 1, 1}
400

Returns: 2

The first algorithm needs 5*400*400 = 800000 operations. The second one needs about 50*400*ln(400) (approximately 170000)  and the third is even a bit faster.

1)
{5, 50, 45}
{2, 1, 1}
{0, 1, 1}
10

Returns: 0

For the small N the first algorithm works faster.

2)
{100}
{5}
{5}
1000

Returns: 0

3)
{32, 33, 58, 93, 8, 27, 43, 69, 95, 77,
 57, 73, 87, 87, 50, 92, 67, 20, 2, 46,
 73, 48, 25, 90, 48, 18, 28, 26, 20, 33,
 59, 48, 69, 4, 19, 13, 10, 78, 55, 90}
{5, 0, 1, 4, 0, 3, 5, 4, 3, 3,
 0, 5, 0, 5, 5, 3, 0, 4, 1, 1,
 4, 0, 2, 4, 0, 0, 3, 2, 0, 0,
 4, 3, 5, 0, 2, 4, 3, 4, 3, 0}
{2, 2, 2, 0, 4, 5, 2, 3, 4, 5,
 0, 0, 1, 4, 2, 5, 2, 4, 5, 0,
 5, 4, 3, 0, 4, 1, 1, 3, 3, 0,
 1, 5, 2, 1, 1, 4, 0, 0, 2, 3}
1000

Returns: 33

// END CUT HERE
#line 76 "ComputationalComplexity.cxx"
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
#include <cfloat>

#define sz size()
#define PB push_back
#define clr(x) memset(x, 0, sizeof(x))
#define forn(i,n) for(__typeof(n) i = 0; i < (n); i++)
#define ford(i,n) for(int i = (n) - 1; i >= 0; i--)
#define forv(i,v) forn(i, v.sz)
#define For(i, st, en) for(__typeof(en) i = (st); i < (en); i++)

using namespace std;

class ComputationalComplexity {
	public:
		int fastestAlgo(vector <int> constant, vector <int> power, vector <int> logPower, int N) 
		{		
			int ret = 0;
			double mincost = DBL_MAX;
			forv(i, constant)
			{
				double cost = constant[i]*pow(N, double(power[i]))*pow(log(N), logPower[i]);
				if(cost+1e-6 < mincost)
				{
					mincost = cost;
					ret = i;
				}
			}
			return ret;
		}
};
