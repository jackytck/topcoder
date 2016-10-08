// BEGIN CUT HERE
// PROBLEM STATEMENT
// Consider the following grid of numbers:

 1 0  3  4   1
 4 5  8  15  20
 1 10 23 46  81
 0 11 44 113 240
 3 14 69 226 579

Aside from the top row and left column, each number is equal to the sum of the three numbers immediately left, above, and above-left of it.  You will be given a vector <int>, row, representing the first row of a similar grid, and a vector <int>, col, representing the first column of the grid.  Your task is to return the value of the lower rightmost location when the values are calculated in the same way.  Hence, the above example would be represented by the input row = {1,0,3,4,1}, col = {1,4,1,0,3}.

DEFINITION
Class:GridGenerator
Method:generate
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int generate(vector <int> row, vector <int> col)


CONSTRAINTS
-row and col will contain the same number of elements.
-row and col will contain between 2 and 10 elements, inclusive.
-Each element of row and col will be between 0 and 9, inclusive.
-The first element of row will be the same as the first element of col.


EXAMPLES

0)
{1,0,3,4,1}
{1,4,1,0,3}

Returns: 579

The example above.

1)
{9,9,9,9,9,9,9,9,9,9}
{9,9,9,9,9,9,9,9,9,9}

Returns: 13163067

The largest possible return.

2)
{0,0,0,0,0,0,0,0,0}
{0,0,0,0,0,0,0,0,0}

Returns: 0

// END CUT HERE
#line 54 "GridGenerator.cxx"
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

class GridGenerator {
	public:
		int generate(vector <int> row, vector <int> col) 
		{		
			vector <vector <int> > table(row.sz, vector <int> (col.sz, 0));
			forv(i, row)
				table[0][i] = row[i];
			forv(i, col)
				table[i][0] = col[i];
			For(i, 1, row.sz)
				For(j, 1, col.sz)
					table[i][j] = table[i-1][j]+table[i][j-1]+table[i-1][j-1];
			return table[row.sz-1][col.sz-1];
		}
};
