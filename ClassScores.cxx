// BEGIN CUT HERE
// PROBLEM STATEMENT
// A teacher has just finished grading the test papers for his class.  To get an idea of how difficult the test was, he would now like to determine the most common score on the test.  In statistics, this is called the "mode" of a set of data points.  For instance, if the scores were {65, 70, 88, 70}, then the mode would be 70, since it appears twice while all others appear once.

Sometimes, in the case of a tie, the mode will be more than one number.  For instance, if the scores were {88, 70, 65, 70, 88}, then the mode would be {70, 88}, since they both appear most frequently.

You are given a vector <int> scores.  You are to return a vector <int> representing the mode of the set of scores.  In the case of more than one number, they should be returned in increasing order.




DEFINITION
Class:ClassScores
Method:findMode
Parameters:vector <int>
Returns:vector <int>
Method signature:vector <int> findMode(vector <int> scores)


CONSTRAINTS
-scores will contain between 1 and 50 elements, inclusive.
-Each element of scores will be between 0 and 100, inclusive.


EXAMPLES

0)
{65, 70, 88, 70}

Returns: {70 }

The first example from the problem statement.

1)
{88, 70, 65, 70, 88}

Returns: {70, 88 }

The second example from the problem statement.

2)
{92, 56, 14, 73, 22, 38, 93, 45, 55}

Returns: {14, 22, 38, 45, 55, 56, 73, 92, 93 }

With no duplicates, all of the elements are the most frequent (appearing once each).

// END CUT HERE
#line 50 "ClassScores.cxx"
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

class ClassScores {
	public:
		vector <int> findMode(vector <int> scores) 
		{		
			sort(scores.begin(), scores.end());
			map <int, int> M;
			forv(i, scores)
				M[scores[i]]++;
			vector <int> ret;
			int max = 0;
			for(map <int, int>::iterator it = M.begin(); it != M.end(); ++it)
				max >?= it->second;
			for(map <int, int>::iterator it = M.begin(); it != M.end(); ++it)
				if(it->second == max)
					ret.PB(it->first);
			return ret;
		}
};
