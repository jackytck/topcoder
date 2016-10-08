// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
You will be given a list of numbers, and a target average.
Compute the value of one additional number to add to the list, such that the average value of the new list is equal to target.


For example, given the list of numbers { 3.0, 7.0, 2.5 } and the target average 4.5, you would have to add the number 5.5 to the list because (3.0 + 7.0 + 2.5 + 5.5) / 4 = 4.5.


DEFINITION
Class:FixTheAverage
Method:add
Parameters:vector <double>, double
Returns:double
Method signature:double add(vector <double> list, double target)


NOTES
-Your return value must have an absolute or relative error less than 1e-9.


CONSTRAINTS
-list will contain between 1 and 10 elements, inclusive.
-Each element of list will be between 0 and 100, inclusive.
-target will be between 0 and 100, inclusive.


EXAMPLES

0)
{ 3.0, 7.0, 2.5 }
4.5

Returns: 5.5

This is the example from the problem statement.

1)
{ 72, 72, 72, 72 }
72

Returns: 72.0

2)
{ 0, 0 }
100

Returns: 300.0

3)
{ 100, 100, 100, 100, 100, 100, 100, 100, 100, 100 }
0

Returns: -1000.0

4)
{ 0.01 }
0.02

Returns: 0.03

// END CUT HERE
#line 65 "FixTheAverage.cxx"
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

class FixTheAverage {
	public:
		double add(vector <double> list, double target) 
		{		
			return target*(list.sz+1) - accumulate(list.begin(), list.end(), 0.);
		}
};
