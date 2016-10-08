// BEGIN CUT HERE
// PROBLEM STATEMENT
// In the game of blackjack, if the player scores higher than the dealer or the dealer goes over 21, and the player does not go over 21, then he wins his bet (in addition to keeping his original wager).  If he scores 21 or less, and the same as the dealer, the hand is a push, and he keeps his bet.  Otherwise, if he scores lower than the dealer, or goes over 21 (regardless of whether or not the dealer also does so), then he loses his bet.

A "blackjack" is a special kind of 21 point hand that beats all other hands.  In such a case, the player wins 1.5 times his original bet.  If both dealer and player have a blackjack, then the hand is a push.  Note that if the dealer has a blackjack, and the player has a 21 (but does not have blackjack), then the dealer wins, and the player loses his wager.

You are given an int bet indicating the players wager, an int dealer indicating the dealer's score, and an int player indicating the player's score.  Finally, you are given an int blackjack, which will be equal to 1 if the player has a blackjack, or 0 otherwise.  Likewise, you are given the int dealerBlackjack.

You are to return the amount of money the player wins or loses on the hand.  A win should return a positive number, either the player's bet, or 1.5 times his bet.  A loss should be returned as a negative number.  A push should return 0.




DEFINITION
Class:BlackjackWinner
Method:winnings
Parameters:int, int, int, int, int
Returns:int
Method signature:int winnings(int bet, int dealer, int dealerBlackjack, int player, int blackjack)


CONSTRAINTS
-bet will be between 2 and 100, inclusive, and will be even.
-dealer will be between 17 and 26, inclusive.
-dealerBlackjack will be 0 or 1.
-dealerBlackjack may only be 1 if dealer is 21.
-player will be between 4 and 30, inclusive.
-blackjack will be 0 or 1.
-blackjack may only be 1 if player is 21.


EXAMPLES

0)
10
20
0
21
0

Returns: 10

Here, the player beats the dealer (without blackjack), and wins his bet.

1)
26
21
1
21
0

Returns: -26

Here, the player loses... even though both dealer and player have 21, the dealer has a blackjack.

2)
100
25
0
21
1

Returns: 150

Here, the dealer went over, so as long as the player didn't go over, he's a winner.  In fact, since he has a blackjack, he wins 1.5 times his original bet.

3)
78
22
0
23
0

Returns: -78

Even though the dealer went over, so did the player, so the player loses.

// END CUT HERE
#line 80 "BlackjackWinner.cxx"
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

class BlackjackWinner {
	public:
		int winnings(int bet, int dealer, int dealerBlackjack, int player, int blackjack) 
		{		
			double win = 0;
			if(dealer <= 21 && player <= 21)
				win = player > dealer ? (blackjack ? 1.5 : 1) : (player == dealer ? (blackjack > dealerBlackjack ? 1.5 : (dealerBlackjack > blackjack ? -1 : 0)) : -1);
			else
			{
				if(dealer > 21 && player <= 21)
					win = blackjack ? 1.5 : 1;
				else
					win = -1;
			}
			return int(bet*win);
		}
};
