// BEGIN CUT HERE
// PROBLEM STATEMENT
// You are taking your car on a long trip and have only a limited amount of fuel. You know how many liters of fuel your car uses per hour for certain speeds and you'd like to know how far a certain amount of fuel will take you when travelling at the optimal speed.


You will be given a vector <int> velocities and a vector <int> consumptions. velocities specifies a number of velocities in kilometers per hour. The ith element of consumptions is the amount of fuel (in milliliters) the car will consume in 1 hour, if your speed is equal to the ith element of velocities. In addition, you will be given an int fuel specifying the total amount of fuel in milliliters.
Your method should return a double, equal to the maximum distance that the car can travel (in kilometers) with the given amount of fuel, and travelling at a constant velocity equal to one of the elements of velocities.

DEFINITION
Class:FuelConsumption
Method:maximalDistance
Parameters:vector <int>, vector <int>, int
Returns:double
Method signature:double maximalDistance(vector <int> velocities, vector <int> consumptions, int fuel)


NOTES
-The returned value must be accurate to within a relative or absolute value of 1E-9. 


CONSTRAINTS
-velocities and consumptions will contain the same number of elements.
-velocities and consumptions will each contain between 1 and 50 elements, inclusive.
-Each element of velocities will be between 5 and 250, inclusive.
-Each element of consumptions will be between 1000 and 20000, inclusive.
-fuel will be between 100 and 50000, inclusive.
-velocities will not contain duplicate elements.


EXAMPLES

0)
{100}
{10000}
10000

Returns: 100.0

At 100 km/hour, you consume 10 liters of fuel per hour. You have 10 liters, so you can cover 100 kilometers.

1)
{70, 80, 90, 100, 60, 110}
{4000, 4000, 4000, 4000, 4000, 4000}
40000

Returns: 1100.0

Here, your car consumes the same amount of fuel at different velocities. In such cases the faster you drive the further you go.

2)
{250, 240, 230, 220, 210, 211}
{5000, 4500, 4000, 3500, 3000, 3000}
50000

Returns: 3516.6666666666665

3)
{5, 10, 20, 40, 80}
{1000, 2500, 6250, 9000, 18000}
47832

Returns: 239.16

4)
{5, 10, 20, 40, 80, 160}
{1000, 2500, 6250, 8000, 9500, 20000}
47832

Returns: 402.79578947368424

5)
{240, 195, 130, 133, 15, 160, 111, 206, 72, 149,
 146, 115, 235, 183, 102, 96, 163, 61, 196, 52,
 87, 139, 33, 7, 90, 67, 118, 227, 197, 114}
{14837, 2981, 17292, 18591, 4832, 7461, 17991, 18369, 18291, 9400,
 15179, 3317, 2595, 2441, 6936, 8028, 14973, 18981, 12503, 7816,
 2883, 6385, 6230, 18157, 16567, 9310, 2866, 4687, 14171, 4477}
31710

Returns: 2871.6184971098264

// END CUT HERE
#line 84 "FuelConsumption.cxx"
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

class FuelConsumption {
	public:
		double maximalDistance(vector <int> velocities, vector <int> consumptions, int fuel) 
		{		
			double ret = velocities[0]/double(consumptions[0]);
			forv(i, velocities)
				ret >?= velocities[i]/double(consumptions[i]);
			return fuel*ret;
		}
};
