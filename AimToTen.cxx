// BEGIN CUT HERE
// PROBLEM STATEMENT
// You are given a int[] marks containing the grades you have received so far in a class. Each grade is between 0 and 10, inclusive.  Assuming that you will receive a 10 on all future assignments, determine the minimum number of future assignments that are needed for you to receive a final grade of 10.  You will receive a final grade of 10 if your average grade is 9.5 or higher.


DEFINITION
Class:AimToTen
Method:need
Parameters:vector <int>
Returns:int
Method signature:int need(vector <int> marks)


CONSTRAINTS
-marks has between 1 and 50 elements, inclusive.
-Each element of marks is between 0 and 10, inclusive.


EXAMPLES

0)
{9, 10, 10, 9}

Returns: 0

Your average is already 9.5, so no future assignments are needed.

1)
{8, 9}

Returns: 4

In this case you need 4 more assignments. With each completed assignment, your average could increase to 9, 9.25, 9.4 and 9.5, respectively.

2)
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

Returns: 950

3)
{10, 10, 10, 10}

Returns: 0

// END CUT HERE
#line 51 "AimToTen.cxx"
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

class AimToTen {
	public:
		int need(vector <int> marks) 
		{		
			return accumulate(marks.begin(), marks.end(), 0)/double(marks.sz) >= 9.5 ? 0 : 19*marks.sz-2*accumulate(marks.begin(), marks.end(), 0);
		}
};
