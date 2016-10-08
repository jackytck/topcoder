// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Given the width and height of a rectangular grid, return the total number of rectangles (NOT counting squares) that can be found on this grid.
For example, width = 3, height = 3 (see diagram below):

 __ __ __
|__|__|__|
|__|__|__|
|__|__|__|

In this grid, there are 4 2x3 rectangles, 6 1x3 rectangles and 12 1x2 rectangles. Thus there is a total of 4 + 6 + 12 = 22 rectangles. Note we don't count 1x1, 2x2 and 3x3 rectangles because they are squares.


DEFINITION
Class:RectangularGrid
Method:countRectangles
Parameters:int, int
Returns:long long
Method signature:long long countRectangles(int width, int height)


NOTES
-rectangles with equals sides (squares) should not be counted.


CONSTRAINTS
-width and height will be between 1 and 1000 inclusive.


EXAMPLES

0)
3
3

Returns: 22

See above

1)
5
2

Returns: 31


 __ __ __ __ __
|__|__|__|__|__|
|__|__|__|__|__|

In this grid, there is one 2x5 rectangle, 2 2x4 rectangles, 2 1x5 rectangles, 3 2x3 rectangles, 4 1x4 rectangles, 6 1x3 rectangles and 13 1x2 rectangles. Thus there is a total of 1 + 2 + 2 + 3 + 4 + 6 + 13 = 31 rectangles.

2)
10
10

Returns: 2640

3)
1
1

Returns: 0

4)
592
964

Returns: 81508708664

*/
// END CUT HERE
#line 75 "RectangularGrid.cxx"
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

class RectangularGrid
{
	public:
	long long countRectangles(int width, int height)
	{	 	 
        long long ret = 0;
        For(i, 1, width+1)
            For(j, 1, height+1)
                if(i != j)
                    ret += (width-i+1) * (height-j+1);
        return ret;
	} 
        	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 3; long long Arg2 = 22LL; verify_case(0, Arg2, countRectangles(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 2; long long Arg2 = 31LL; verify_case(1, Arg2, countRectangles(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 10; long long Arg2 = 2640LL; verify_case(2, Arg2, countRectangles(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 1; long long Arg2 = 0LL; verify_case(3, Arg2, countRectangles(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 592; int Arg1 = 964; long long Arg2 = 81508708664LL; verify_case(4, Arg2, countRectangles(Arg0, Arg1)); }

// END CUT HERE
 
}; 
// BEGIN CUT HERE 
int main()
{
	RectangularGrid ___test; 
        	___test.run_test(-1); 
}
// END CUT HERE 
