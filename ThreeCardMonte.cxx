// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
You come across an apparently respectable man on the street who makes you a seemingly legitimate proposition: the opportunity to play a game of Three Card Monte.  He has a table with three face-up cards in a row: two jokers and one ace, with the ace in the middle.  After you make a small wager, he turns the cards face-down and begins to manipulate the cards, swapping cards two at a time.  After he completes the swaps, you are then to guess which card is the ace.


The series of card swaps will be given to you in order as a string swaps, containing only the characters 'L', 'R', 'E', and 'F'.  swaps[0] indicates the first swap.  The 4 characters indicate the following moves:


L: swap the left and middle cards
R: swap the right and middle cards
E: swap the cards on the ends (the left and right cards)
F: fake swap (no cards actually change position)


Write a method that returns the final position of the ace, after all the swaps have been performed.  Your method should return "L" if the left card is the ace, "R" if the right card is the ace, and "M" if the ace is in the middle.


DEFINITION
Class:ThreeCardMonte
Method:position
Parameters:string
Returns:string
Method signature:string position(string swaps)


CONSTRAINTS
-swaps will contain beween 0 and 50 characters, inclusive.
-swaps will contain only the characters 'L', 'R', 'E', and 'F'.


EXAMPLES

0)
"L"

Returns: "L"

1)
"REL"

Returns: "M"

The first swap moves the ace from the middle to the right side.  The second swap moves the ace from the right side to the left side.  The third swap moves the ace from the right side back to the middle.

2)
"RFRFR"

Returns: "R"

Ignoring the two fake swaps, the middle and right cards are swapped three times.  Therefore, the ace ends up on the right side.

3)
""

Returns: "M"

No cards move -- the ace remains in the middle.

4)
"FLRELFLRELLFRLFEELFLRFLELRFLRFREFRFLLRFERLFLREFRFL"

Returns: "L"

// END CUT HERE
#line 67 "ThreeCardMonte.cxx"
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

class ThreeCardMonte {
	public:
		string position(string swaps) 
		{		
			char left = 'J', middle = 'A', right = 'J';
			forn(i, swaps.sz)
			{
				switch(swaps[i])
				{
					case 'L':
						swap(left, middle);
						break;
					case 'R':
						swap(right, middle);
						break;
					case 'E':
						swap(left, right);
						break;
				}
			}
			return left == 'A' ? "L" : (middle == 'A' ? "M" : "R");
		}
};
