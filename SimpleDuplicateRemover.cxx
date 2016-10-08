// BEGIN CUT HERE
// PROBLEM STATEMENT
// We have a sequence of integers. We want to remove duplicate elements from it.
You will be given a vector <int> sequence. For each element that occurs more than once leave only its rightmost occurrence. All unique elements must be copied without changes.


DEFINITION
Class:SimpleDuplicateRemover
Method:process
Parameters:vector <int>
Returns:vector <int>
Method signature:vector <int> process(vector <int> sequence)


CONSTRAINTS
-sequence will have between 1 and 50 elements, inclusive. 
-Each element of sequence will be between 1 and 1000, inclusive. 


EXAMPLES

0)
{1,5,5,1,6,1}

Returns: {5, 6, 1 }

We left the third 1, the second 2 and the only 6.

1)
{2,4,2,4,4}

Returns: {2, 4 }

2)
{6,6,6,6,6,6}

Returns: {6 }

3)
{1,2,3,4,2,2,3}

Returns: {1, 4, 2, 3 }

4)
{100,100,100,99,99,99,100,100,100}

Returns: {99, 100 }

// END CUT HERE
#line 51 "SimpleDuplicateRemover.cxx"
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

class SimpleDuplicateRemover {
	public:
		vector <int> process(vector <int> sequence) 
		{		
			vector <int> ret;
			reverse(sequence.begin(), sequence.end());
			forv(i, sequence)
			{
				bool repeat = false;
				forv(j, ret)
					if(sequence[i] == ret[j])
						repeat = true;
				if(!repeat)
					ret.PB(sequence[i]);
			}
			reverse(ret.begin(), ret.end());
			return ret;
		}
};
