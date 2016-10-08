// BEGIN CUT HERE
// PROBLEM STATEMENT
// You will be given a vector <string>, conflicts, where each element represents a single player in a multiplayer game.  Element i represents player i, and character j of element i represents whether player i will win ('W'), tie ('T'), or lose ('L') against player j. 
Your task is to ensure that each player wins against at least p% of the other players, and loses against at least q% of the other players.  You should return the 0-based index of the first player in the input (lowest index) that does not meet these requirements, or -1 if all players meet them.  Note that if there are N players total, then at least ceil((N-1)*p/100) of the characters in element i must be 'W' for player i to meet the requirements.  The formula for losses is analogous.


DEFINITION
Class:BalancedGame
Method:result
Parameters:vector <string>, int, int
Returns:int
Method signature:int result(vector <string> conflicts, int p, int q)


NOTES
-The i-th character of the i-th element of conflicts will always be 'T' and can be ignored.
-The function 'ceil' in ceil((N-1)*p/100) returns the least integer greater than or equal to its argument. For example, ceil(1.5)=2 and ceil(4)=4.


CONSTRAINTS
-p and q will be between 0 and 100, inclusive.
-conflicts will have between 2 and 50 elements, inclusive.
-Each element of conflicts will have the same number of characters ('W', 'L' and 'T') as the number of elements in conflicts.
-If the j-th character of the i-th element of conflicts is 'W', 'L', or 'T' then the i-th character of the j-th element will be 'L', 'W' or 'T' respectively.
-The i-th character of the i-th element of conflicts will always by 'T'.


EXAMPLES

0)
{"TWWW",
 "LTWW",
 "LLTW",
 "LLLT"}
20
20

Returns: 0

Player 0 cannot lose and player 3 cannot win, so these players are not balanced. Return the lowest index of an unbalanced player.

1)
{"TWWW",
 "LTWW",
 "LLTW",
 "LLLT"}
0
0

Returns: -1

Now there are no balancing constraints, so even though player 0 cannot lose and player 3 cannot win, the characters are balanced.

2)
{"TTT",
 "TTT",
 "TTT"}
1
1

Returns: 0

Even with such lax balancing constraints, a perfectly matched set of characters is not balanced in the sense we are looking for.

3)
{"TLLLLLTWWWWTLLWWWT",
 "WTTWTTLLWLLWWLTLWW",
 "WTTWWTLWTWLWWWWLTW",
 "WLLTLTWWWTWLWLLWLT",
 "WTLWTLWWWWLLWLLWTW",
 "WTTTWTWLLWTLLWWWLW",
 "TWWLLLTLLWTWWWLLWW",
 "LWLLLWWTWLLWWLLLWT",
 "LLTLLWWLTTWLTWTLWT",
 "LWLTLLLWTTTLLLLWTW",
 "LWWLWTTWLTTTLLWWLL",
 "TLLWWWLLWWTTLWTTLL",
 "WLLLLWLLTWWWTWLLWW",
 "WWLWWLLWLWWLLTTWLL",
 "LTLWWLWWTWLTWTTTWT",
 "LWWLLLWWWLLTWLTTLW",
 "LLTWTWLLLTWWLWLWTW",
 "TLLTLLLTTLWWLWTLLT"}
18
6

Returns: 17

// END CUT HERE
#line 91 "BalancedGame.cxx"
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

class BalancedGame {
	public:
		int result(vector <string> conflicts, int p, int q) 
		{		
			int ret = -1;
			forv(i, conflicts)
			{
				int lost = 0, win = 0, tie = 0;
				forn(j, conflicts[i].sz)
				{
					if(j != i)
					{
						switch(conflicts[i][j])
						{
							case 'L':
								lost++;
								break;
							case 'W':
								win++;
								break;
							case 'T':
								tie++;
						}
					}
				}
				if(win < ceil((lost+win+tie)*p/100.0) || lost < ceil((lost+win+tie)*q/100.0))
				{
					ret = i;
					break;
				}
			}
			return ret;
		}
};
