// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
A careless worker planted several poles in a row to build a fence. 
They all should be the same height, but they were cut at different sizes. 
The owner wants them not only all at the same height, but also as tall as possible. 



Our solution will be to cut the tops of taller poles and "glue" those tops on top of the shorter ones. 
To do this, we will first sort the poles from tallest to shortest, and proceed as follows:

 Cut the tip of the tallest pole, leaving its height equal to the average height of the poles (so we do not cut it anymore).
 "glue" this piece on top of the shortest pole.
 Re-sort the poles, and continue from the first step until all poles are the same height.



Write a class CuttingPoles with a method countCuts that takes a vector <int> 
of pole heights and returns the number of cuts needed to make them all the same height using
the algorithm described.



DEFINITION
Class:CuttingPoles
Method:countCuts
Parameters:vector <int>
Returns:int
Method signature:int countCuts(vector <int> poles)


CONSTRAINTS
-poles will contain between 1 and 50 elements, inclusive.
-Each element of poles must be between 1 and 1000, inclusive.
-The average value of poles will be an integer.


EXAMPLES

0)
{1,3}

Returns: 1

Cropping the taller pole to a height of 2 and gluing its top piece onto the shorter pole leaves them both with the same height.

1)
{10,10,10}

Returns: 0

No cuts needed.

2)
{1,1,3,3}

Returns: 2

3)
{10,10,10,10,10,10,10,18}

Returns: 7

// END CUT HERE
#line 67 "CuttingPoles.cxx"
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

class CuttingPoles {
	public:
		int countCuts(vector <int> poles) 
		{		
			int ret = 0;
			sort(poles.begin(), poles.end());
			int average = accumulate(poles.begin(), poles.end(), 0)/poles.sz;
			while(poles[poles.sz-1] != average)
			{
				poles[0] += poles[poles.sz-1]-average;
				poles[poles.sz-1] = average;
				sort(poles.begin(), poles.end());
				ret++;
			}
			return ret;
		}
};
