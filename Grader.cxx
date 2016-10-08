// BEGIN CUT HERE
// PROBLEM STATEMENT
// For the International Baccalaureate (IB) diploma, students are assigned integer grades between 1 and 7 inclusive, based on exams taken at the end of high school. Unfortunately, these results are never available in time to assist universities with admissions decisions. To counteract this problem, IB teachers are required to predict in advance how well each student will perform on the exams. As these predictions can have an enormous impact on a student's future, schools are naturally very interested in evaluating their accuracy.

Create a class Grader that contains a method grade, which is given a vector <int> predictedGrades and a vector <int> actualGrades. Corresponding elements in these arrays will represent the predicted and final grades, respectively, achieved by each student. The method should return a vector <int> with 7 elements, giving the percentage (rounded down) of predicted grades that differ from the actual grades by each value between 0 and 6 inclusive. Thus, element 0 of the return value should be the percentage of predictions that were correct, element 1 should be the percentage of predictions that differed by 1, etc.


DEFINITION
Class:Grader
Method:grade
Parameters:vector <int>, vector <int>
Returns:vector <int>
Method signature:vector <int> grade(vector <int> predictedGrades, vector <int> actualGrades)


CONSTRAINTS
-predictedGrades and actualGrades will each contain between 1 and 50 elements inclusive.
-predictedGrades and actualGrades will contain the same number of elements.
-Each element of predictedGrades will be between 1 and 7 inclusive.
-Each element of actualGrades will be between 1 and 7 inclusive.


EXAMPLES

0)
{1,5,7,3}
{3,5,4,5}

Returns: {25, 0, 50, 25, 0, 0, 0 }

The grade distribution is shown below.



Student | Predicted grade | Actual grade | Difference
--------+-----------------+--------------+-----------
   1    |        1        |       3      |     2
   2    |        5        |       5      |     0
   3    |        7        |       4      |     3
   4    |        3        |       5      |     2



Out of four predictions, one (25%) is off by 0 points, two (50%) are off by 2 points, and one (25%) is off by 3 points.

1)
{1,1,1}
{5,6,7}

Returns: {0, 0, 0, 0, 33, 33, 33 }

Note that percentages are rounded down.

2)
{3}
{3}

Returns: {100, 0, 0, 0, 0, 0, 0 }

3)
{1,5,3,5,6,4,2,5,7,6,5,2,3,4,1,4,6,5,4,7,6,6,1}
{5,1,3,2,6,4,1,7,5,2,7,4,2,6,5,7,3,1,4,6,3,1,7}

Returns: {17, 13, 21, 17, 21, 4, 4 }

// END CUT HERE
#line 68 "Grader.cxx"
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

class Grader {
	public:
		vector <int> grade(vector <int> predictedGrades, vector <int> actualGrades) 
		{		
			vector <int> diff(7, 0);
			forv(i, predictedGrades)
				diff[abs(predictedGrades[i]-actualGrades[i])]++;
			forv(i, diff)
				diff[i] = int(floor(diff[i]/double(actualGrades.sz)*100));
			return diff;
		}
};
