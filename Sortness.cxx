// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
The sortness of a sequence of distinct numbers is the average of the sortness of each element. The sortness of an element is the number of higher elements that come before it in the sequence plus the number of lower elements that come after it in the sequence. The lower the sortness of a sequence, the closer it is to being sorted. Only a sorted sequence has a sortness of 0.

For example, in the sequence {3,2,1,4,6,7,5,8} the numbers 1,2,3 and 5 have a sortness of 2, numbers 6 and 7 have a sortness of 1 and numbers 4 and 8 have a sortness of 0. The sortness of the sequence is the average of all those sortness values: (2+2+2+2+1+1+0+0)/8 = 1.25.

You will be given a sequence of distinct numbers a as a vector <int>. Return the sortness of a.


DEFINITION
Class:Sortness
Method:getSortness
Parameters:vector <int>
Returns:double
Method signature:double getSortness(vector <int> a)


CONSTRAINTS
-a will contain between 1 and 50 elements, inclusive.
-a will contain exactly one occurrence of each integer between 1 and the number of elements in a, inclusive.


EXAMPLES

0)
{3,2,1,4,6,7,5,8}

Returns: 1.25

The example in the problem statement.

1)
{1,2,3}

Returns: 0.0

A sorted sequence has a sortness of zero.

2)
{5,4,3,2,1}

Returns: 4.0

A reversed sequence has maximum sortness.

3)
{1,5,8,7,9,6,10,12,11,3,4,2}

Returns: 5.166666666666667



// END CUT HERE
#line 56 "Sortness.cxx"
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

class Sortness {
	public:
		double getSortness(vector <int> a) 
		{		
			int av = 0;
			forv(i, a)
			{
				int sort = 0;
				forn(j, i)
					if(a[j] > a[i])
						sort++;
				For(j, i+1, a.sz)
					if(a[j] < a[i])
						sort++;
				av += sort;
			}
			return double(av) / a.sz;
		}
};
