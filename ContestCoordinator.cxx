// BEGIN CUT HERE
// PROBLEM STATEMENT
// You are the coordinator of a contest, and you have been presented with the final scores of all the contestants. It is now your job to determine the quality of the contest. To do this, you will compute the average score after eliminating the k highest scoring contestants and the k lowest scoring contestants. k is a non-negative integer (it can be 0), and you will choose a value for k that yields the maximum average score. Return a double representing this maximum average score. You are not allowed to eliminate all the scores.


DEFINITION
Class:ContestCoordinator
Method:bestAverage
Parameters:vector <int>
Returns:double
Method signature:double bestAverage(vector <int> scores)


NOTES
-The returned value must be accurate to 1e-9 relative or absolute.


CONSTRAINTS
-scores will contain between 1 and 50 elements, inclusive.
-Each element of scores will be between 1 and 1000, inclusive.


EXAMPLES

0)
{1}

Returns: 1.0

There's nothing to remove here.

1)
{1,2,3,4}

Returns: 2.5

Eliminating the first and the last score yields an average score of 2.5

2)
{1,1,999,999,1000,1000}

Returns: 999.0

Keep only the scores equal to 999.

3)
{1,13,8,6,7,9}

Returns: 7.5

4)
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}

Returns: 1.0

// END CUT HERE
#line 58 "ContestCoordinator.cxx"
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

class ContestCoordinator {
	public:
		double bestAverage(vector <int> scores) 
		{		
			double ret = scores.sz == 1 ? scores[0] : 0;
			int k = scores.sz%2 == 0 ? scores.sz/2-1 : scores.sz/2;
			sort(scores.begin(), scores.end());
			forn(i, k+1)
			{
				double sum = 0;
				For(j, i, scores.sz-i)
					sum += scores[j];
				if(sum/(scores.sz-2*i) > ret)
					ret = sum/(scores.sz-2*i);
			}
			return ret;
		}
};
