// BEGIN CUT HERE
// PROBLEM STATEMENT
// Jane tries her best to stay fit. Knowing this, her sister decided to play a prank on Jane: after Jane's old scale broke down, her sister got her a new scale that shows the square of a person's weight, instead of the real weight.

Not noticing the change, Jane has been using the scale for a while. One morning she screamed "Oh no! I gained apparentGain pounds!". Given an int apparentGain (the difference between the square of Jane's current weight and the square of her previous weight), return a vector <int> containing Jane's possible real weights after the latest measurement, sorted in ascending order.

All weights (displayed and real, previous and current) are positive integers.


DEFINITION
Class:Prank
Method:realWeight
Parameters:int
Returns:vector <int>
Method signature:vector <int> realWeight(int apparentGain)


CONSTRAINTS
-apparentGain will be between 1 and 100000, inclusive.


EXAMPLES

0)
233

Returns: {117 }

If Jane had previously weighed 116 pounds, the scale would have shown 116^2 = 13456. If she gained 1 pound, the scale would show 117^2 = 13689, for an apparent gain of 13689 - 13456 = 233.


1)
15

Returns: {4, 8 }

Assuming in this example Jane is actually a small animal, she could have gone from 1 to 4 or from 7 to 8.


2)
1440

Returns: {38, 39, 42, 46, 49, 53, 66, 77, 94, 123, 182, 361 }



3)
100000

Returns: {325, 350, 550, 665, 1025, 1270, 2510, 3133, 5005, 6254, 12502, 25001 }

This is the largest input.

4)
93301

Returns: {3595, 46651 }

Watch out for overflow!

5)
16

Returns: {5 }



// END CUT HERE
#line 70 "Prank.cxx"
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

class Prank {
	public:
		vector <int> realWeight(int apparentGain) 
		{		
			vector <int> factors;
			vector <int> rw;
			For(i, 1, apparentGain + 1)
			{
				if(apparentGain % i == 0)
					factors.PB(i);
			}
			forn(i, factors.sz)
			{
				if( (apparentGain / factors[i] - factors[i]) % 2 == 0 && (apparentGain / factors[i] > factors[i])) 
					rw.PB((apparentGain / factors[i] - factors[i]) / 2 + factors[i]);
			}
			std::sort(rw.begin(), rw.end());
			//rw.erase(std::unique(rw.begin(), rw.end()), rw.end());
			return rw;
		}
};
