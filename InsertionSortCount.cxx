// BEGIN CUT HERE
// PROBLEM STATEMENT
// A sequence of distinct numbers A is going to be sorted using insertion sort. Insertion sort works as follows:

insertion-sort(A)
   initialize a new empty sequence R
   for each number N in A (in the original order) do:
      determine the index i in R where N should be inserted so that R remains sorted
      move each element in R with index greater than or equal to i to the following index
      set R[i]=N
   return R

For example, an insertion sort on {20,40,30,10} would produce the following states for R after each step:
20          (first element is inserted at index 0)
20,40       (inserting 40 at index 1 requires no moves)
20,30,40    (30 is inserted at index 1, so 40 has to be moved)
10,20,30,40 (10 is inserted at index 0, so 20, 30 and 40 have to be moved)
In total, 4 moves were needed.
Given a vector <int> A, which contains a sequence of distinct numbers, return the number of moves that would be performed by an insertion sort on A.


DEFINITION
Class:InsertionSortCount
Method:countMoves
Parameters:vector <int>
Returns:int
Method signature:int countMoves(vector <int> A)


CONSTRAINTS
-A will have between 1 and 50 elements, inclusive.
-Each element of A will be between -1000 and 1000, inclusive.
-All elements of A will be distinct.


EXAMPLES

0)
{20,40,30,10}

Returns: 4

The example from the problem statement.

1)
{-1,1,0}

Returns: 1

Only one move needed to insert 0.

2)
{-1000,0,1000}

Returns: 0

Since elements are inserted in sorted order, all of them are appended at the end of R. Therefore, there's no need to move anything.

// END CUT HERE
#line 61 "InsertionSortCount.cxx"
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

class InsertionSortCount {
	public:
		int countMoves(vector <int> A) 
		{		
			int ret = 0;
			forv(i, A)
				forn(j, i)
					if(A[j] > A[i])
						ret++;
			return ret;
		}
};
