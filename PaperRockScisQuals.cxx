// BEGIN CUT HERE
// PROBLEM STATEMENT
// A very exciting Paper-Rock-Scissors tournament has just begun! In qualifications, each player must face all his opponents in head to head games consisting of 5 throws. On each throw, each player will choose one of the following: Paper ('P'), Rock ('R') or Scissors ('S'). The winner of a throw is determined as follows:

Paper always wins against Rock
Rock always wins against Scissors
Scissors always win against Paper
In case both players make the same choice, it's a tie and no one wins.

The winner of a game is the player who wins more throws. If both players win the same number of throws, the game ends in a tie (since these are qualifications, ties are allowed). To determine who passed the qualifications, a scoring system is implemented as follows:

For every game won, the player is awarded one point.
For every game tied, the player is awarded half of a point.
For every game lost, the player is awarded zero points.

Only a single player will pass the qualifications, namely the player with the most points.
If several players have the same amount of points, the player which comes first in the input wins.

All players observe a simple strategy: each of them prepares a sequence of throws and plays the same sequence in every game. Write a program that will receive a vector <string> players representing the sequence of throws for all players and returns the 0-based index of the player who will pass the qualifications. Each element of players will contain exactly 5 characters. Character 'P' represents a Paper throw, 'S' represents a Scissors throw, and 'R' represents a Rock throw.

DEFINITION
Class:PaperRockScisQuals
Method:whoPassed
Parameters:vector <string>
Returns:int
Method signature:int whoPassed(vector <string> players)


CONSTRAINTS
-players will contain between 1 and 50 elements, inclusive.
-Each element of players will contain exactly 5 characters.
-Each element of players will contain only the characters 'P', 'R' and 'S'.


EXAMPLES

0)
{"PPRRS","PPRRP","PPRSP","PPSSP"}

Returns: 0

Player 0 will defeat players 1, 2 and 3 with 1, 2 and 3 throws won respectively so he gets 3 points. 
Player 1 will defeat players 2 and 3 with 1 and 2 throws won respectively so he gets 2 points. 
Player 2 defeats player 3 with 1 throw won so gets 1 point. 
Player 3 does not win a single game so he gets 0 points. 

The winner is player 0 with 3 points.

1)
{"RRRRR","PPPPP","RRRRR","PPPPP"}

Returns: 1

Players 1 and 3 both defeat players 0 and 2 and have a tied game between themselves so they have 2.5 points in total.
Players 0 and 2 lose to players 1 and 3 and have a tied game between themselves so they have 0.5 points in total.
Since player 1 is before player 3 in input, the tie is resolved in his favor and he wins the qualifications.

2)
{"RRRRR","PPPPP","SSSSS","PPPPP"}

Returns: 2

Now player 2 defeats players 1 and 3 and loses to player 0 and has 2 points in total. 
Players 1 and 3 defeat player 0 and tie each other ending with 1.5 points. 
Player 0 defeats player 2 for 1 point in total. 


3)
{"RRRRR","PPPPP","SSSSS","SSSSS","RRRRR","RRRRR"}

Returns: 0

Players 0, 1, 4 and 5 have 3 points. Since player 0 comes first in the input, he wins.

4)
{"PPRPS","RRRPR","SSPRS","SSPRR","PPRSP","SPRPS","SPRSP","PRSPR","PRSPR"}

Returns: 6

// END CUT HERE
#line 82 "PaperRockScisQuals.cxx"
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

class PaperRockScisQuals {
	public:
		int whoPassed(vector <string> players) 
		{		
			int ret = 0;
			vector <float> score(players.sz, 0.);
			forn(i, players.sz-1)
			{
				for(int j=i+1; j<players.sz; j++)
				{
					int iwin = 0, jwin = 0;
					forn(k, 5)
					{
						switch(players[i][k])
						{
							case 'P':
								switch(players[j][k])
								{
									case 'P':
										break;
									case 'R':
										iwin++;
										break;
									case 'S':
										jwin++;
										break;
								}
								break;
							case 'R':
								switch(players[j][k])
								{
									case 'P':
										jwin++;
										break;
									case 'R':
										break;
									case 'S':
										iwin++;
										break;
								}
								break;
							case 'S':
								switch(players[j][k])
								{
									case 'P':
										iwin++;
										break;
									case 'R':
										jwin++;
										break;
									case 'S':
										break;
								}
								break;
						}
					}
					if(iwin > jwin)
						score[i] += 1;
					else if(jwin > iwin)
						score[j] += 1;
					else
					{
						score[i] += .5;
						score[j] += .5;
					}
				}
			}
			float maxScore = *max_element(score.begin(), score.end());
			for(ret=0; ret<players.sz; ret++)
				if(score[ret] == maxScore)
					break;
			return ret;
		}
};
