// BEGIN CUT HERE
// PROBLEM STATEMENT
// We have some baskets containing apples, and we would like to perform the following procedure in a way that maximizes the number of remaining apples.  First, we discard some (or none) of the baskets completely.  Then, if the remaining baskets do not all contain the same number of apples, we remove excess apples from the baskets until they do.
You will be given a vector <int> apples where the i-th element of apples is the number of apples in the i-th basket. Return the number of apples remaining after the procedure described above is performed.


DEFINITION
Class:BasketsWithApples
Method:removeExcess
Parameters:vector <int>
Returns:int
Method signature:int removeExcess(vector <int> apples)


CONSTRAINTS
-apples will contain between 1 and 50 elements, inclusive.
-Each element in apples will be between 0 and 1000, inclusive.


EXAMPLES

0)
{1, 2, 3}

Returns: 4

We should remove the first basket and leave two apples in each of the two remaining baskets.

1)
{5, 0, 30, 14}

Returns: 30

We should leave only the third basket.

2)
{51, 8, 38, 49}

Returns: 114

3)
{24, 92, 38, 0, 79, 45}

Returns: 158

// END CUT HERE
#line 48 "BasketsWithApples.cxx"
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

class BasketsWithApples {
	public:
		int removeExcess(vector <int> apples) 
		{		
			int ret = 0;
			sort(apples.begin(), apples.end());
			forv(i, apples)
				if(apples[i]*(apples.sz-i) > ret)
					ret = apples[i]*(apples.sz-i);
			return ret;
		}
};
