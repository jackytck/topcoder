// BEGIN CUT HERE
// PROBLEM STATEMENT
// Rumor has it that Russians don't obey speed limits. That may be because
the speed limits are sometimes specified implicitly in Russia.
More specifically, every road in a city has a default speed
limit of 60 kilometers per hour, and usually doesn't have any road
signs to remind drivers of that. Analogously, every road outside the city
has a default speed limit of 90 kilometers per hour.
The speed limit can still be specified with
road signs, like '30' or '95'. There is also a special road sign,
'start of default speed limit zone', that tells you that the default speed limit is now in place. The signs are sometimes also used to remind
drivers of the current speed limit, so you can meet several same signs in a row.
To summarize, one should pay attention to the following road signs
to monitor the speed limit changes:

Speed limit X - marks the start of a zone with speed limit X kilometers per hour.
Start of default speed limit zone - marks the start of a zone with the default speed limit, either 60 if inside a city or 90 if outside.
City boundary - means the default speed limit changes from 60 to 90 or vice versa. If
you are inside a special speed limit zone, this zone also ends, so the speed limit always becomes equal to the new default.

Given the list of road signs you met on your way as a vector <string> signs
(in the order you met them), return the current speed limit. Each element of
signs will be either a positive integer number X without leading zeros,
denoting the sign 'Speed limit X', a string "default" denoting the
sign 'start of default speed limit zone', or a string "city", denoting the sign
'city boundary' (quotes for clarity only). You start your journey inside a city, and outside any special speed
limit zone.


DEFINITION
Class:RussianSpeedLimits
Method:getCurrentLimit
Parameters:vector <string>
Returns:int
Method signature:int getCurrentLimit(vector <string> signs)


CONSTRAINTS
-signs will contain between 1 and 50 elements, inclusive.
-Each element of signs will be "default", "city" or a positive integer without leading zeros, between 1 and 100, inclusive (quotes for clarity only).


EXAMPLES

0)
{"80"}

Returns: 80

On highways, speed limits may be above the default value.

1)
{"40", "70", "default", "20", "50"}

Returns: 50

The limits are specified in the order you meet them, so you're interested in the last one.

2)
{"40", "70", "default"}

Returns: 60

The default limit is still 60.

3)
{"40", "80", "city"}

Returns: 90

The first "city" means we've left the city, thus the 90 limit.

4)
{"city", "60"}

Returns: 60

Speed limits can be overridden outside the city too.

5)
{"city", "50", "default"}

Returns: 90

The default value changes when outside the city.

6)
{"city", "city", "city", "city"}

Returns: 60

You've crossed four city boundaries.  The first time, you left a city.  Then, you entered a city.  Then, you left that city.  Finally, you entered another city.

7)
{"20", "city", "city", "50", "60"}

Returns: 60

The default speed limit may be specified with a usual sign.

// END CUT HERE
#line 103 "RussianSpeedLimits.cxx"
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
#define For(i, st, en) for(__typeof(en) i = (st); i < (en); i++)

using namespace std;

class RussianSpeedLimits {
	public:
		int getCurrentLimit(vector <string> signs) 
		{		
			int c;
			bool inCity = true;
			forn(i, signs.sz)
			{
				if(signs[i] == "city")
				{
					inCity = !inCity;
					c = inCity ? 60 : 90;
				}
				if(signs[i] == "default")
				{
					c = inCity ? 60 : 90;
				}
				else if(signs[i] != "city")
				{
					istringstream is(signs[i]);
					is >> c;
				}
			}
			return c;
		}
};
