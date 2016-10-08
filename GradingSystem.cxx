// BEGIN CUT HERE
// PROBLEM STATEMENT
// A certain professor has come up with two grading schemes. Each of his students has received a definite score in the course between 0 and 100 points, inclusive. The scores for all the students are given in the vector <int> scores, which will be sorted from least to greatest. Students will end up with an integer grade between 0 and 8 points. He has mentally assigned desired grades to each student. The i-th element of scores corresponds to the i-th element of grades. Grades corresponding to equal scores will be sorted greatest to least.
In the first scheme, if he desires a certain student to have a grade of X, then every student scoring as high or higher than that student must receive a grade of at least X. Aside from this constraint, students will be given the lowest possible grade.
For example, suppose 3 students had scores of {60,80,80} and the professor desired them to have grades of {3,8,6}. They would then recieve grades of {3,8,8}, since the third student scored at least as high as the second.
In the second scheme, if he desires a certain student to have a grade of X, then every student scoring as low or lower than that student must receive a grade of at most X. Aside from this constraint, students will be given the highest possible grade.
In the above example, the students would recieve grades of {3,6,6} now, since the second student scored at least as low as the third.
You should apply both schemes, and for each student, determine the absolute difference between the final grades obtained from the two schemes. Return the sum of those differences.

DEFINITION
Class:GradingSystem
Method:fairness
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int fairness(vector <int> scores, vector <int> grades)


CONSTRAINTS
-scores will contain between 1 and 50 elements, inclusive.
-scores and grades will contain the same number of elements.
-Each element of scores will be between 0 and 100, inclusive.
-Each element of grades will be between 0 and 8, inclusive.
-scores will be sorted least to greatest.
-Elements of grades corresponding to equal elements of scores will be sorted greatest to least. 


EXAMPLES

0)
{60,80,80}
{3,8,6}

Returns: 4

The example in the description.

1)
{0,25,50,75,100}
{0,1,3,6,8}

Returns: 0

Here the professor's expectations are exactly in line with the students' performances.

2)
{0,25,50,75,100}
{8,6,3,1,0}

Returns: 40

Here the performances and the expectations are severely different.

// END CUT HERE
#line 55 "GradingSystem.cxx"
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

class GradingSystem {
	public:
		int fairness(vector <int> scores, vector <int> grades) 
		{		
			int sum = 0, temp = 0;
			forn(i, scores.sz)
			{
				if(grades[i] > temp)
					temp = grades[i];
				sum += temp; 
			}
			temp = 8;
			ford(i, scores.sz)
			{
				if(grades[i] < temp)
					temp = grades[i];
				sum -= temp;
			}
			return sum;
		}
};
