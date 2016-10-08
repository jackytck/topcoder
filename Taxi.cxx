// BEGIN CUT HERE
// PROBLEM STATEMENT
// The "taxicab distance" between two points in space is defined to be the distance
that would need to be travelled to get from one to the other using segments
that are parallel to the axes.  This is generally longer than the (straight-line)
distance between the two points.

We know the taxicab distance between two points. We want to know the maximum
straight-line distance between them if they lie in the
rectangular region { (x,y) |  0<=x<=maxX, 0<=y<=maxY }. 
Create a class Taxi that contains a method maxDis that is given maxX, maxY,
and taxiDis and that returns the largest possible straight-line distance between
the two points. If no two points within the given region have the given taxicab
distance, return -1.0.



DEFINITION
Class:Taxi
Method:maxDis
Parameters:int, int, int
Returns:double
Method signature:double maxDis(int maxX, int maxY, int taxiDis)


NOTES
-A return value with either an absolute or relative error of less than 1.0E-9 is considered correct.


CONSTRAINTS
-maxX and maxY are both between 1 and 1,000,000, inclusive.
-taxiDis is between 0 and 1,000,000, inclusive.


EXAMPLES

0)
10
3
3

Returns: 3.0



   The two points could lie in a straight line parallel to one of the axes. Then
   the straight-line distance would be the same as the taxicab distance.




1)
10
3
24

Returns: -1.0



   No two points with 0<=x<=10, 0<=y<=3, have a taxicab distance between them
   that is as big as 24.


2)
7
10
13

Returns: 10.44030650891055



   (5,0) and (2,10) are two points in this region whose taxicab distance is |2-5| + |10-0| = 13 and whose straight-line distance is sqrt(3*3 + 10*10) = sqrt(109).

3)
4
4
7

Returns: 5.0

4)
976421
976421
1000000

Returns: 976705.6560100387

// END CUT HERE
#line 92 "Taxi.cxx"
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

class Taxi {
	public:
		double maxDis(int maxX, int maxY, int taxiDis) 
		{		
			double ret = -1; 
		        int a = maxX+1, b = maxY;
			if(taxiDis <= maxX+maxY)
			{
				for(int i=0; i<=maxX; i++)
					if(taxiDis-i >= 0 && taxiDis-i <= maxY && (long long)i*(taxiDis-i) < (long long)a*b)
					{
						a = i;
						b = taxiDis-i;
					}
				ret = sqrt(pow(a,2.) + pow(b,2.));
				//ret = sqrt(a*a + b*b);
			}
			return ret;
		}
};
