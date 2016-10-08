// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
In the new boardgame Medici, you play an aristocrat in 15th-century Florence.  On each turn, you gather
points in three categories: fame, fortune, and dirty secrets with which you can blackmail other players.  The
winner is the player with the most points in his weakest category at the end of the game.  
For example, suppose there are three players with the following points:


    NAME       FAME  FORTUNE  SECRETS
    ---------------------------------
    Salvestro   20      60       40
    Giovanni    30      80       30
    Cosimo      50      40       50

Salvestro's weakest category is Fame, in which he has 20 points.  Giovanni's weakest categories are Fame and Secrets, with 30 points in both.  Cosimo's weakest category is Fortune, with 40 points.  Cosimo is the winner.


You will be given three vector <int>s, fame, fortune, and secrets.  The points for player i are 
given as the i-th elements of the three vector <int>s.  You are to return the (zero-based) index of the winning player.  If there
is a tie for the winning score, the game is declared a draw and replayed, in which case you should return -1.


DEFINITION
Class:Medici
Method:winner
Parameters:vector <int>, vector <int>, vector <int>
Returns:int
Method signature:int winner(vector <int> fame, vector <int> fortune, vector <int> secrets)


CONSTRAINTS
-fame contains between 2 and 20 elements, inclusive.
-fortune and secrets each contain the same number of elements as fame.
-All elements of fame, fortune, and secrets are between 0 and 100, inclusive.


EXAMPLES

0)
{ 20, 30, 50 }
{ 60, 80, 40 }
{ 40, 30, 50 }

Returns: 2

The example above.  Salvestro is player 0, Giovanni is player 1, and Cosimo is player 2.

1)
{   0, 100, 100, 100 }
{ 100,   0, 100,  50 }
{  50,  50,  50, 100 }

Returns: -1

Players 2 and 3 both have 50 points in their weakest categories (Secrets and Fortune,
respectively).  The game is a draw.

2)
{ 1, 0 }
{ 1, 99 }
{ 1, 99 }

Returns: 0

Player 0 wins even though he scored 195 fewer total points than player 1.
Total points is irrelevant in determining the winner.

3)
{ 39, 42, 57 }
{ 42, 39, 57 }
{ 57, 39, 42 }

Returns: 2

Players 0 and 1 tie for second place, but that does
not cause the game to be declared a draw.

4)
{ 3, 98, 0, 71, 81, 85, 99, 58, 93, 79, 100, 98, 73, 83, 52, 100, 37, 93, 39, 27 }
{ 96, 34, 45, 20, 72, 71, 7, 18, 47, 35, 54, 51, 52, 21, 49, 20, 44, 72, 90, 93 }
{ 15, 72, 50, 84, 41, 49, 35, 71, 20, 29, 73, 18, 35, 61, 70, 34, 59, 68, 90, 18 }

Returns: 17

// END CUT HERE
#line 88 "Medici.cxx"
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

class Medici {
	public:
		int winner(vector <int> fame, vector <int> fortune, vector <int> secrets) 
		{		
			vector <int> ret;
			forv(i, fame)
				ret.PB(min(fame[i], min(fortune[i], secrets[i])));
			int maxscore = *max_element(ret.begin(), ret.end()), n = 0;
			forv(i, ret)
				if(ret[i] == maxscore)
					n++;
			return n > 1 ? -1 : max_element(ret.begin(), ret.end()) - ret.begin();
		}
};
