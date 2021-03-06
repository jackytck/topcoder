// BEGIN CUT HERE
// PROBLEM STATEMENT
// Your friend was born on "leap day" and has always been troubled by the fact that he just turned 24 this year on his 5th birthday.  You would like to write him a nice program for his birthday to help him and other leap-day-born people keep track of how many birthdays they've had so far.

You will be given two years as ints, year represents the current year and born represents the year the person was born.  You are to return the number of leap days that have occurred in that time span, not including the first year if it is a leap year, but including the current year if it's a leap year.

A leap year is any year that is a multiple of 4, unless it is divisible by 100 and not 400.  For example, 1984 was a leap year, but 1900 wasn't, because it was divisible by 100 and not 400.  2000 was a leap year, because it was divisible by both 100 and 400.

DEFINITION
Class:LeapAge
Method:getAge
Parameters:int, int
Returns:int
Method signature:int getAge(int year, int born)


NOTES
-It is possible that year and born are not actually leap years.


CONSTRAINTS
-year and born will both be between 1582 and 10000 (1582 is when the Gregorian Calendar started, so there were no leap years before then).
-year will be greater than born.


EXAMPLES

0)
2004
1980

Returns: 6

This is the case in the first paragraph of the problem statement.

1)
10000
1582

Returns: 2042

This is about as old as you get in this problem.  Note that while the Gregorian Calendar (and therefore, leap years) started in 1582, 1582 wasn't a leap year.

2)
2007
1981

Returns: 6

You really don't know why your lying friend asked you to write this...

3)
1981
1980

Returns: 0

4)
1984
1983

Returns: 1

5)
9700
5795

Returns: 947

// END CUT HERE
#line 72 "LeapAge.cxx"
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

class LeapAge {
	public:
		int getAge(int year, int born) 
		{		
			int ret = 0;
			for(int i=born+1; i<=year; i++)
			{
				if(i%4 == 0)
				{
					if(i%100 == 0 && i%400 != 0)
						continue;
					ret++;
				}
			}
			return ret;
		}
};
