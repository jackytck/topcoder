// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
Given a sequence of K elements, we can calculate its difference sequence by taking the difference between each pair of adjacent elements.  For instance, the difference sequence of {5,6,3,9,-1} is {6-5,3-6,9-3,-1-9} = {1,-3,6,-10}. Formally, the difference sequence of the sequence a1, a2, ... , ak is b1, b2, ... , bk-1, where bi = ai+1 - ai.

The derivative sequence of order N of a sequence A is the result of iteratively applying the above process N times. For example, if A = {5,6,3,9,-1}, the derivative sequence of order 2 is: {5,6,3,9,-1} -> {1,-3,6,-10} -> {-3-1,6-(-3),-10-6} = {-4,9,-16}.

You will be given a sequence a as a vector <int> and the order n. Return a vector <int> representing the derivative sequence of order n of a.



DEFINITION
Class:DerivativeSequence
Method:derSeq
Parameters:vector <int>, int
Returns:vector <int>
Method signature:vector <int> derSeq(vector <int> a, int n)


NOTES
-The derivative sequence of order 0 is the original sequence. See example 4 for further clarification.


CONSTRAINTS
-a will contain between 1 and 20 elements, inclusive.
-Each element of a will be between -100 and 100, inclusive.
-n will be between 0 and K-1, inclusive, where K is the number of elements in a.


EXAMPLES

0)
{5,6,3,9,-1}
1

Returns: {1, -3, 6, -10 }

The first example given in the problem statement.

1)
{5,6,3,9,-1}
2

Returns: {-4, 9, -16 }

The second example given in the problem statement.

2)
{5,6,3,9,-1}
4

Returns: {-38 }



3)
{4,4,4,4,4,4,4,4}
3

Returns: {0, 0, 0, 0, 0 }

After 1 step, they all become 0.

4)
{-100,100}
0

Returns: {-100, 100 }



// END CUT HERE
#line 74 "DerivativeSequence.cxx"
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

class DerivativeSequence {
	public:
		vector <int> derSeq(vector <int> a, int n) 
		{		
			For(k, 1, n+1)
				forn(i, a.sz-k)
					a[i] = a[i+1] - a[i];
			return vector <int> (a.begin(), a.end()-n);
		}
};
