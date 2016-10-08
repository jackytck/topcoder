// BEGIN CUT HERE
// PROBLEM STATEMENT
// You are sitting in front of a mirror and looking at the image of a clock located behind you. You want to know what time it is. The clock is a traditional clock with a 12-hour board (without numbers written on it), a minute and an hour hand (the hour hand is shorter, so that you can distuniguish them). You are given a string time denoting the time as it is seen in the mirror. The time will be formatted as "HH:MM" (quotes for clarity), where HH is the two digit hour and MM is the two digit minute. The hour will be between 00 and 11, inclusive, where 00 represents 12 o' clock. Return a string in the same format denoting the actual time. See examples for further clarification.

DEFINITION
Class:MirroredClock
Method:whatTimeIsIt
Parameters:string
Returns:string
Method signature:string whatTimeIsIt(string time)


CONSTRAINTS
-time will be formatted as "HH:MM" (quotes for clarity), where HH is a two digit integer between 00 and 11, inclusive, and MM is a two digit integer between 00 and 59, inclusive.


EXAMPLES

0)
"10:00"

Returns: "02:00"



1)
"01:15"

Returns: "10:45"



2)
"03:40"

Returns: "08:20"



3)
"00:00"

Returns: "00:00"

Although it doesn't happen often, sometimes we can see the actual time right in the mirror.

4)
"11:53"

Returns: "00:07"



// END CUT HERE
#line 56 "MirroredClock.cxx"
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

class MirroredClock {
	public:
		string whatTimeIsIt(string time) 
		{		
			int hr,min;
			sscanf(time.c_str(), "%d:%d", &hr, &min);
			int diff = 12 * 60 - hr * 60 - min;
			hr = diff / 60;
			if(hr == 12)
				hr = 0;
			min = diff % 60;
			char re[5];
			sprintf(re, "%02d:%02d", hr, min);
			return re;
		}
};
