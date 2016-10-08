// BEGIN CUT HERE
// PROBLEM STATEMENT
// Given an integer sequence a[0], a[1], ..., a[N-1], find a contiguous subsequnce a[i], a[i+1], ..., a[j] such that:

The length of the subsequence (j-i+1) is at least K.
The average value in the subsequence (a[i] + a[i+1] + ... + a[j])/(j-i+1) is maximized.



You are given a vector <int> a containing the original sequence, and an int K. Return a vector <int> containing exactly two elements.  The first element is the first index of the contiguous subsequence described above, and the second element is the last index. Both indices are 0-based. If there are multiple subsequences that satisfy the conditions above, return the longest one among them. If there are still multiple subsequences, return the one among them with the smallest first index.



DEFINITION
Class:ContiguousSubsequences
Method:findMaxAverage
Parameters:vector <int>, int
Returns:vector <int>
Method signature:vector <int> findMaxAverage(vector <int> a, int K)


CONSTRAINTS
-a will contain between 1 and 50 elements, inclusive.
-Each element of a will be between 0 and 1000000, inclusive.
-K will be between 1 and number of elements in a, inclusive.


EXAMPLES

0)
{1,3,7}
2

Returns: {1, 2 }

There are 3 possible contiguous subsequences:

{1,3}, average = 2.
{1,3,7}, average = 11/3.
{3,7}, average = 5.

So {3,7} is the best case.

1)
{5,1,3,4}
2

Returns: {2, 3 }



2)
{10}
1

Returns: {0, 0 }

There is only one possible subsequence - the whole sequence.

3)
{381,921,513,492,135,802,91,519}
1

Returns: {1, 1 }

When K = 1, we can select the subsequence containing only the maximal elements.

4)
{381,921,513,492,135,802,91,519}
4

Returns: {0, 3 }



5)
{3,5,7,7,2,5,4,7,7,2,4}
1

Returns: {2, 3 }



6)
{3, 1, 3, 3, 3, 1, 3, 3, 3}
1

Returns: {2, 4 }



7)
{1, 3, 2, 1, 1, 2, 2, 2, 2}
3

Returns: {5, 8 }



// END CUT HERE
#line 102 "ContiguousSubsequences.cxx"
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
#define For(i, st, en) for(__typeof(en) i = (st); i < (en); i++)

using namespace std;

class ContiguousSubsequences {
	public:
		vector <int> findMaxAverage(vector <int> a, int K) 
		{		
			int len = a.sz;
			int maxi, maxj;
			double av, max = -1;
			while(len >= K)
			{
				forn(i, a.sz - len + 1)
				{
					int sum = 0;
					forn(j, len)
					{
						sum += a[i + j];
					}
					av = double(sum) / len;
					if(av > max)
					{
						max = av;
						maxi = i;
						maxj = i + len - 1;
					}
				}
				len--;
			}	
			vector<int> re;
			re.push_back(maxi);
			re.push_back(maxj);
			return re;
		}
};
