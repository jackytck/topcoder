// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
Let N1 = {1, 2, 3, 4, 5, ..., 1000} (the set of all positive integers between 1 and 1000, inclusive).


Delete every second number in N1. The result is N2 = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, ..., 999}.


Delete every third number in N2. The result is N3 = {1, 3, 7, 9, 13, 15, 19, 21, 25, ..., 999}.


Delete every fourth number in N3. The result is N4 = {1, 3, 7, 13, 15, 19, 25, 27, ...}.


...


Delete every tenth number in N9. The result is N10. Find and return the n-th element of sequence N10, where n is a 1-based index.



DEFINITION
Class:EratosthenSieve2
Method:nthElement
Parameters:int
Returns:int
Method signature:int nthElement(int n)


NOTES
-N10 will contain exactly 101 elements.


CONSTRAINTS
-n will be between 1 and 100, inclusive.


EXAMPLES

0)
3

Returns: 7

1)
1

Returns: 1

2)
10

Returns: 79

3)
25

Returns: 223

// END CUT HERE
#line 63 "EratosthenSieve2.cxx"
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

class EratosthenSieve2 {
	public:
		int nthElement(int n) 
		{		
			vector <int> N10(1000, 0);
			forv(i, N10)
				N10[i] = i+1;
			for(int i=2; i<=10; i++)
			{
				int nsize = N10.sz;
				For(j, 1, nsize)
					if((j+1) % i == 0)
						N10[j] = 0;
				N10.erase(remove(N10.begin(), N10.end(), 0), N10.end());
			}
			return N10[n-1];
		}
};
