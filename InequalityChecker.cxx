// BEGIN CUT HERE
// PROBLEM STATEMENT
// Using mathematical induction it is possible to prove the following inequality when n>1:
	s = 13 + 23 + ... + (n-1)3 < n4/4 < 13 + 23 + ... + n3 = S
  Given n return (S+s)/2 - n4/4 as a vector <int> with 2 elements.  Elements 0 and 1 denote the numerator and denominator of the return value, respectively, when written in least terms (reduced).

DEFINITION
Class:InequalityChecker
Method:getDifferences
Parameters:int
Returns:vector <int>
Method signature:vector <int> getDifferences(int n)


CONSTRAINTS
-n will be between 2 and 100 inclusive.


EXAMPLES

0)
2

Returns: { 1,  1 }

We have 
s = 1^3 = 1
S = 1^3 + 2^3 = 9
(S+s)/2 = (1+9)/2 = 5
n^4/4 = 16/4 = 4 
Since 5-4 = 1, we return the fraction 1/1.

1)
3

Returns: { 9,  4 }

We have 
s = 1^3 + 2^3 = 9
S = 1^3 + 2^3 + 3^3 = 36
(S+s)/2 = 45/2
n^4/4 = 81/4
We return the fraction 9/4.

2)
100

Returns: { 2500,  1 }

Largest case.

// END CUT HERE
#line 54 "InequalityChecker.cxx"
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

class InequalityChecker {
	public:
		vector <int> getDifferences(int n) 
		{		
			vector <int> ret(2, 1);
			if(n%2)
			{
				ret[0] = n*n;
				ret[1] = 4;
			}
			else
				ret[0] = (n/2)*(n/2);
			return ret;
		}
};
