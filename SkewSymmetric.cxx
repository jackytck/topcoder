// BEGIN CUT HERE
// PROBLEM STATEMENT
// A skew symmetric matrix M satisfies MT = -M, where MT denotes the transpose of the matrix M and -M denotes the matrix obtained by multiplying each entry of M by -1. The transpose of a matrix M is obtained by replacing the element in the i'th row and j'th column of M with the element in the j'th row and i'th column of M. Note that this requires the diagonal elements of a skew-symmetric matrix to be equal to 0.
Create a class SkewSymmetric which contains a method minChanges. The method will take a vector <string> M, each element of which is a single space separated list of integers. The j'th number in the i'th element of M represents the value at row i and column j of the matrix. The method should return the minimum number of values in M that must be changed such that the resulting matrix is skew symmetric.

DEFINITION
Class:SkewSymmetric
Method:minChanges
Parameters:vector <string>
Returns:int
Method signature:int minChanges(vector <string> M)


CONSTRAINTS
-M will contain between 2 and 10 elements, inclusive.
-Each element of M will be a single space separated list of exactly n integers, where n is the number of elements in M.
-Each element of M will contain between 1 and 50 characters, inclusive.
-Each integer in M will be between -99 and 99 inclusive, with no extra leading zeros.
-The integer zero will be represented as '0' (quotes for clarity) only, and not '-0' (quotes for clarity) in M.


EXAMPLES

0)
{"1 2 8", "-2 1 0", "3 99 3"}

Returns: 5

One possible skew-symmetric matrix obtained by changing 5 elements in M is:

  0  2  -3
 -2  0 -99
  3 99   0

Note that the diagonal elements must be 0.

1)
{"0 1 1 1 1 1", "-1 0 1 1 1 1", "-1 -1 0 1 1 1", 
"-1 -1 -1 0 1 1", "-1 -1 -1 -1 0 1", "0 0 0 0 0 0"}

Returns: 5



2)
{"0 0 0 0", "0 0 0 0", "0 0 0 0", "0 0 0 0"}

Returns: 0



3)
{"1 0", "0 1"}

Returns: 2



// END CUT HERE
#line 61 "SkewSymmetric.cxx"
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

class SkewSymmetric {
	public:
		int minChanges(vector <string> M) 
		{		
			int ret = 0;
			vector < vector <int> > m;
			forv(i, M)
			{
				vector <int> row;
				int input;
				istringstream is(M[i]);
				while(is >> input)
					row.PB(input);
				m.PB(row);
			}
			forv(i, m)
			{
				For(j, i, m.sz)
				{
					if(i == j && m[i][j] != 0)
						ret++;
					else if(m[i][j] != -m[j][i])
						ret++;
				}
			}
			return ret;
		}
};
