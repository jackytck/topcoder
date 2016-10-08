// BEGIN CUT HERE
// PROBLEM STATEMENT
// A teacher has graded a test, and you are given a vector <int> scores representing each student's raw score on the test.  The teacher wants to convert the scores into grades such that a raw score of 0 receives a grade of 0, and the highest raw score achieved by any student receives a grade of 100.  All other scores in between are calculated proportionally, always rounded down.  You are to return a vector <int> (with the same number of elements as scores) containing the calculated grade for each student.  Element i of the return should be the grade for scores[i].

DEFINITION
Class:TestCurve
Method:determineGrades
Parameters:vector <int>
Returns:vector <int>
Method signature:vector <int> determineGrades(vector <int> scores)


CONSTRAINTS
-scores will contain between 1 and 50 elements, inclusive.
-Each element of scores will be between 0 and 10000, inclusive.
-At least one element of scores will be greater than 0.


EXAMPLES

0)
{15, 27, 8, 33, 19, 50}

Returns: {30, 54, 16, 66, 38, 100 }

Since the highest score is a 50, which gets scaled to a grade of 100, everyone's grade is exactly twice their raw score.

1)
{0, 0, 0, 3}

Returns: {0, 0, 0, 100 }

All but one person did poorly on this test.

2)
{67, 89, 72, 100, 95, 88}

Returns: {67, 89, 72, 100, 95, 88 }

With a highest score of 100, the grade is exactly the raw score.

3)
{1234, 3483, 234, 5738, 3421, 5832, 4433}

Returns: {21, 59, 4, 98, 58, 100, 76 }

4)
{8765}

Returns: {100 }

// END CUT HERE
#line 54 "TestCurve.cxx"
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

class TestCurve {
	public:
		vector <int> determineGrades(vector <int> scores) 
		{	
			int max = *max_element(scores.begin(), scores.end());	
			double scale = 100.0 / max;
			forv(i, scores)
				scores[i] = scores[i] == max ? 100 : int(scores[i]*scale);
			return scores;
		}
};
