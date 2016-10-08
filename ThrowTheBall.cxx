// BEGIN CUT HERE
// PROBLEM STATEMENT
// There are N friends sitting in a circle, numbered clockwise in increasing order from 1 to N. At the beginning of the game, player 1 receives a ball. The players take turns passing the ball to each other. At the beginning of the game and before each next pass the following actions are performed. If the player with the ball has already received the ball M times, the game is over. Otherwise, if the player has received the ball p times, he'll pass the ball directly to the person L places to his left if p is even, or L places to his right if p is odd (see examples for clarification). 

Given N, M and L, return the number of times that the ball is passed.

DEFINITION
Class:ThrowTheBall
Method:timesThrown
Parameters:int, int, int
Returns:int
Method signature:int timesThrown(int N, int M, int L)


CONSTRAINTS
-N will be between 3 and 50, inclusive.
-M will be between 1 and 50, inclusive.
-L will be between 1 and N-1, inclusive.


EXAMPLES

0)
5
3
2

Returns: 10

First, player 1 gets the ball.  Since he has held the ball 1 time, he passes the ball to player 4, who is two places to his right.  This is player 4's first time holding the ball, so he gives it to player 2, who passes it to player 5.  Player 5 then passes the ball to player 3, who passes it back to player 1.  Since player 1 has now held the ball 2 times, he passes it to player 3, who passes it to player 5, who then passes the ball to player 2.  Finally, player 2 passes the ball to player 4, who then passes it to player 1.  Player 1 has now held the ball 3 times, and the game ends.

1)
4
1
3

Returns: 0

Here, the ball is never passed.

2)
10
3
5

Returns: 4



3)
15
4
9

Returns: 15



// END CUT HERE
#line 61 "ThrowTheBall.cxx"
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

class ThrowTheBall {
	public:
		int timesThrown(int N, int M, int L) 
		{		
			vector <int> p(N, 0);
			int cnt = 0, hold = 0;
			p[0] = 1;
			while(!over(p, M))
			{
				if(p[hold] % 2 == 0)
					hold -= L;
				else
					hold += L;
				hold += N;
				hold %= N;
				p[hold] += 1;
				cnt++;
			}
			return cnt;
		}
		bool over(vector <int> p, int M)
		{
			bool o = false;
			forv(i, p)
				if(p[i] == M)
					o = true;
			return o;
		}
};
