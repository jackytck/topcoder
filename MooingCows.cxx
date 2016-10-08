// BEGIN CUT HERE
// PROBLEM STATEMENT
// The cows in Byterland are mooing loudly, annoying the residents very much.  Mrs. Darcy of the villa Pemberley is planning to resolve this problem by allowing only one cow to moo.  She will pick the cow whose mooing is the least offensive to all the other cows.

The farmland in Pemberley is divided into n*m squares of grassland.  Each square is either empty or occupied by a single cow.  When a cow at (x,y) moos, the dissatisfaction of a cow at (i,j) is equal to the square of the distance between them: ((x-i)2 + (y-j)2).  The total dissatisfaction is the sum of the dissatisfaction of all the cows.

Return the minimal total dissatisfaction that can be achieved by allowing only a single cow to moo.  The farmland will be given as a vector <string>, where '.' characters denote empty squares, and 'C' characters denote squares occupied by cows.

DEFINITION
Class:MooingCows
Method:dissatisfaction
Parameters:vector <string>
Returns:int
Method signature:int dissatisfaction(vector <string> farmland)


CONSTRAINTS
-farmland will contain between 1 and 50 elements, inclusive.
-Each element of farmland will contain between 1 and 50 characters, inclusive.
-Each element of farmland will contain the same number of characters.
-Each character in farmland will be either uppercase 'C' or '.'.
-farmland will contain at least one uppercase 'C'.


EXAMPLES

0)
{"C..",
 ".C.",
 ".C."}

Returns: 3


If we set the uppermost cow to moo, the total dissatisfaction will be 2+5;
If we set the middle cow to moo, the total dissatisfaction will be 2+1;
If we set the bottommost cow to moo, the total dissatisfaction will be 1+5.

Certainly we will choose the second plan.

1)
{"CCCC",
 "CCCC",
 "CCCC"}

Returns: 26



2)
{"C"}

Returns: 0

3)
{"CCC....",
 "C......",
 "....C.C",
 ".C.CC..",
 "C......"}

Returns: 81



// END CUT HERE
#line 68 "MooingCows.cxx"
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

class MooingCows {
	public:
		int dissatisfaction(vector <string> farmland) 
		{		
			int ret = -1;
			forv(i, farmland)
			{
				forn(j, farmland[i].sz)
				{
					if(farmland[i][j] == 'C')
					{
						int degree = 0;
						forv(k, farmland)
							forn(l, farmland[k].sz)
								if((k != i || l != j) && farmland[k][l] == 'C')
									degree += (i-k)*(i-k) + (j-l)*(j-l);
						if(ret == -1)
							ret = degree;
						ret = min(ret, degree);
					}
				}
			}
			return ret;
		}
};
