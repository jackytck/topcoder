// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
An integer arithmetic progression is a sequence defined by two positive integers, p and q, where p is the first element in the sequence, and all other elements are obtained by adding q to the previous element.  For example, if p = 1 and q = 2, the sequence would be: 1, 3, 5, 7, ...



An integer geometric progression is a sequence defined by two positive integers, p and q, where p is the first element in the sequence, and all other elements are obtained by multiplying the previous element by q.  For example, if p = 3 and q = 2, the sequence would be: 3, 6, 12, ...



You are given a vector <int> A, which contains either an integer arithmetic or geometric progression. Determine which one it is and return the next element in the sequence. It is guaranteed that A will uniquely represent either an arithmetic or geometric progression and that result will fit in a 32-bit signed integer.



DEFINITION
Class:GuessingNextElement
Method:guess
Parameters:vector <int>
Returns:int
Method signature:int guess(vector <int> A)


CONSTRAINTS
-A will contain between 3 and 50 elements, inclusive.
-Each element of A will be between 1 and 10^6, inclusive.
-A will be sorted in ascending order.
-A will uniquely represent either an arithmetic or geometric progression.


EXAMPLES

0)
{364,843,1322,1801}

Returns: 2280

This sequence represents an arithmetic progression where p = 364 and q = 479. The next element is 1801 + 479 = 2280.

1)
{394,1172,1950,2728,3506,4284,5062,5840}

Returns: 6618

2)
{13,117,1053,9477,85293}

Returns: 767637

This sequence represents a geometric progression where p = 13 and q = 9. The next element is 85293 * 9 = 76737.


3)
{22,220,2200,22000}

Returns: 220000

4)
{250000, 500000, 1000000}

Returns: 2000000



// END CUT HERE
#line 67 "GuessingNextElement.cxx"
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
#define clr(x) memset(x, 0, sizeof(x))
#define forn(i,n) for(__typeof(n) i = 0; i < (n); i++)
#define ford(i,n) for(int i = (n) - 1; i >= 0; i--)
#define For(i, st, en) for(__typeof(en) i = (st); i <= (en); i++)

using namespace std;

class GuessingNextElement {
	public:
		int guess(vector <int> A) 
		{
			bool as = false;
			if(A[2]-A[1] == A[1]-A[0])
				as = true;
			if(as)
				return A[A.sz-1] + (A[2] - A[1]);
			else
				return A[A.sz-1] * (A[2] / A[1]);
		}
};
