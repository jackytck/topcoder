// BEGIN CUT HERE
// PROBLEM STATEMENT
// You are given a vector <int> A. An integer K is irreducible with respect to A if K cannot be represented as a sum of one or more elements from A, where each element of A may be used at most once.  Return the smallest positive integer that is irreducible with respect to A.

DEFINITION
Class:IrreducibleNumber
Method:getIrreducible
Parameters:vector <int>
Returns:int
Method signature:int getIrreducible(vector <int> A)


CONSTRAINTS
-A will contain between 1 and 3 elements, inclusive.
-Each element of A will be between 1 and 100, inclusive.


EXAMPLES

0)
{1,1}

Returns: 3

1 can be expressed as 1, and 2 can be expressed as 1+1.

1)
{1,2}

Returns: 4



2)
{1,3}

Returns: 2



3)
{4, 1, 3}

Returns: 2



// END CUT HERE
#line 50 "IrreducibleNumber.cxx"
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

class IrreducibleNumber {
	public:
		int getIrreducible(vector <int> A) 
		{		
			int sum = accumulate(A.begin(), A.end(), 0), ret = 0;
			vector <int> a(sum+2, 0);
			forv(i, A)
				a[A[i]] = 1;
			a[sum] = 1;
			if(A.sz == 3)
			{
				a[A[0]+A[1]] = 1;
				a[A[0]+A[2]] = 1;
				a[A[1]+A[2]] = 1;
			}
			For(i, 1, a.sz)
				if(a[i] == 0)
				{
					ret = i;
					break;
				}
			return ret;
		}
};
