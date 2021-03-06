// BEGIN CUT HERE
// PROBLEM STATEMENT
// You are thinking of using the following betting strategy: in the first round, you bet one dollar.  If you win the bet, you win the dollar and bet another dollar in the next round.  Otherwise you lose the dollar and bet two dollars in the second round (provided you still have at least two dollars in your account).  If you win, you get the two dollars and bet one dollar in the third round, otherwise you lose the two dollars and bet four dollars in the third round (provided you have at least that amount in your account) and so on.  In other words, whenever you lose a bet, you double the value of the bet for the next round.  Whenever you win, the bet for the next round will be one dollar.

For example, if you start with 10 dollars, and you win the bet in the first round, lose the bet in the next two rounds and then win the bet in the fourth round, you will end up with 10+1-1-2+4 = 12 dollars.

You will be given an int initSum giving the amount of money you initially have.  You will also be given a string outcome.  The ith character of outcome will be either 'W' (win) or 'L' (lose), denoting the outcome of the ith round.  Return the amount of money you will have after all the rounds are played.  If at some point you don't have enough money in your account to cover the value of the bet, you must stop and return the sum you have at that point.


DEFINITION
Class:BettingStrategy
Method:finalSum
Parameters:int, string
Returns:int
Method signature:int finalSum(int initSum, string outcome)


CONSTRAINTS
-initSum will be between 1 and 1000, inclusive.
-outcome will contain between 1 and 50 characters, inclusive.
-Each character of outcome will be either 'W' or 'L'.


EXAMPLES

0)
12
"WWWWWWWW"

Returns: 20

You are really lucky.  You win one dollar in each round, so you end up with 20 dollars.

1)
15
"LLLWLLLL"

Returns: 1

After losing 7 dollars in the first three rounds, you have just enough money to cover your bet for the fourth round.  You win 8 dollars in this round, but lose another 15 in the last four, so your final sum will be one dollar.

2)
20
"WLWLWLWL"

Returns: 23

You win one dollar in each odd numbered round and lose one dollar in the last round.

3)
925
"WLLLLLWLLLLLLWWWWWLWLLWLLLLLLWL"

Returns: 934

// END CUT HERE
#line 58 "BettingStrategy.cxx"
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

class BettingStrategy {
	public:
		int finalSum(int initSum, string outcome) 
		{		
			int ret = initSum, nextBet = 1;
			forn(i, outcome.sz)
			{
				if(ret < nextBet)
					break;
				if(outcome[i] == 'W')
				{
					ret += nextBet;
					nextBet = 1;
				}
				else
				{
					ret -= nextBet;
					nextBet *= 2;
				}
			}
			return ret;
		}
};
