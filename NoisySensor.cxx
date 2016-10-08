// BEGIN CUT HERE
// PROBLEM STATEMENT
// You are processing data obtained from a temperature sensor in a physics experiment. The data consists of an array of integers that represents the measured temperature as a function of time. Unfortunately, the sensor is of poor quality and has introduced some random noise into the data. You have decided to apply a median filter to the temperature data in order to reduce the effect of this noise.

In the context of this problem, median filtering is an operation on an array that replaces each element i except the first and last with the median value of itself and its two immediate neighbors (the three elements i, i-1, and i+1). The first and last elements are missing a neighbor, so median filtering does not affect them.

Write a class NoisySensor with a method medianFilter that takes a vector <int> data with the noisy sensor values at each time point and returns a vector <int> with the median-filtered version of data.

DEFINITION
Class:NoisySensor
Method:medianFilter
Parameters:vector <int>
Returns:vector <int>
Method signature:vector <int> medianFilter(vector <int> data)


NOTES
-The median of 3 numbers is the "middle number".  To find the median, sort the 3 numbers, and then look at the second element.


CONSTRAINTS
-data will contain between 1 and 50 elements, inclusive.
-Each element of data will be between -2147483648 and 2147483647, inclusive.


EXAMPLES

0)
{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}

Returns: {1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }

Here the median filter produces no change.

1)
{10, 1, 9, 2, 8}

Returns: {10, 9, 2, 8, 8 }

Here are the medians computed: 
Median of 10, 1, 9 : 9
Median of 1, 9, 2  : 2
Median of 9, 2, 8  : 8

2)
{500, 500, 500, 500, 500}

Returns: {500, 500, 500, 500, 500 }

3)
{-2147483648, 2147483647}

Returns: {-2147483648, 2147483647 }

4)
{432296535, 1983848899, -434724194, 135703525, -1146336142,
-680568092, -1183352724, 1337550909, -1597342716, -1901441857,
1726722019, -558651015, 649930787, 1889036519, 1752815826,
930647381, -852547667, 2028345278, -1835531493, -1040566300,
-1566043783, -1282411107, -1123988603, 2132078516, -1169614369,
-523503536, 1466102514, -2003903121, -779001645, 1919742042,
1210980485, -9273881, 1033032137, -1474003783, 296280591,
920184999, -1235054743, -1329769514, -1727085135}

Returns: {432296535, 432296535, 135703525, -434724194, -680568092, -1146336142, -680568092, -1183352724, -1597342716, -1597342716, -558651015, 649930787, 649930787, 1752815826, 1752815826, 930647381, 930647381, -852547667, -1040566300, -1566043783, -1282411107, -1282411107, -1123988603, -1123988603, -523503536, -523503536, -523503536, -779001645, -779001645, 1210980485, 1210980485, 1033032137, -9273881, 296280591, 296280591, 296280591, -1235054743, -1329769514, -1727085135 }

// END CUT HERE
#line 69 "NoisySensor.cxx"
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

class NoisySensor {
	public:
		vector <int> medianFilter(vector <int> data) 
		{		
			vector <int> ret;
			forv(i, data)
			{
				if(i == 0 || i == data.sz-1)
					ret.PB(data[i]);
				else
				{
					int x = min(data[i-1], min(data[i], data[i+1]));
					int y = max(data[i-1], max(data[i], data[i+1]));
					ret.PB(data[i-1]+data[i]+data[i+1]-x-y);
				}
			}
			return ret;
		}
};
