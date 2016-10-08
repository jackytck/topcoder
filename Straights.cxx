// BEGIN CUT HERE
// PROBLEM STATEMENT
// You are playing a game of cards in which the number of straights, i.e., sets of consecutive-valued cards, determines the strength of your hand. You will be given a vector <int> hand, where the i-th element of hand is the number of cards of value i in your hand. You should return the number of straights of length k. For example, suppose you have the hand:

2 of spades
2 of diamonds
2 of clubs
3 of clubs
4 of hearts
4 of clubs

You would be given hand = { 0, 3, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0 }. The number of two-card straights is 5:

2 of spades, 3 of clubs
2 of diamonds, 3 of clubs
2 of clubs, 3 of clubs
3 of clubs, 4 of hearts
3 of clubs, 4 of clubs


DEFINITION
Class:Straights
Method:howMany
Parameters:vector <int>, int
Returns:int
Method signature:int howMany(vector <int> hand, int k)


NOTES
-Straights do not wrap around: if hand is {1,0,0,0,0,0,0,0,0,0,0,0,1}, you have no straights of length 2.


CONSTRAINTS
-hand will contain exactly 13 elements.
-Each element of hand will be between 0 and 4 inclusive.
-k will be between 1 and 13 inclusive.


EXAMPLES

0)
{0,3,1,2,0,0,0,0,0,0,0,0,0}
2

Returns: 5

The example given.

1)
{1,1,1,1,1,1,1,1,1,1,1,1,1}
5

Returns: 9

Say hand[0] references Aces. There are 9 ways to make a straight of length 5: Ace-Five up to Nine-King.

2)
{4,4,4,4,4,4,4,4,4,4,4,4,4}
13

Returns: 67108864

3)
{4,0,4,0,4,0,4,0,4,0,4,0,4}
2

Returns: 0

Straights do not wrap around; we have no straights here.

4)
{1,2,3,4,1,2,3,4,1,2,3,4,1}
1

Returns: 31

// END CUT HERE
#line 79 "Straights.cxx"
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

class Straights {
	public:
		int howMany(vector <int> hand, int k) 
		{		
			int ret = 0;
			forn(i, hand.sz-k+1)
			{
				int part = 1;
				For(j, i, i+k)
					part *= hand[j];
				ret += part;
			}
			return ret;
		}
};
