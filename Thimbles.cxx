// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
Thimbles is a hazard game with the following rules. The dealer puts three identical thimbles on the table, with a small ball underneath the first one. Then, he repeatedly selects a pair of thimbles and swaps their positions. Finally, he asks you "Where is the ball?". You win if you point to the right thimble and lose otherwise. 


You are writing the computer version of this game, and in this problem, you must write the module that determines the position of the ball after all the thimble swaps have been done. 
You will be given a vector <string> swaps which describes the swaps made, in order. Each element of swaps will be in the format "X-Y" (quotes for clarity), which means that the thimble in position X was swapped with the thimble in position Y. The positions are 1, 2 or 3. Your method should return the position of the thimble with the ball after all the swaps. 


DEFINITION
Class:Thimbles
Method:thimbleWithBall
Parameters:vector <string>
Returns:int
Method signature:int thimbleWithBall(vector <string> swaps)


CONSTRAINTS
-swaps will contain between 1 and 50 elements, inclusive.
-Each element of swaps will be in the format "X-Y" (quotes for clarity) where X and Y are distinct digits between 1 and 3, inclusive.


EXAMPLES

0)
{"1-2", "3-1"}

Returns: 2

Initially the ball is under the first thimble. After the first swap it moves to the second position. The second swap doesn't affect the ball. So, the final position of the ball is 2.


1)
{"3-1", "2-3", "3-1", "3-2"}

Returns: 3

The path of the ball is:
1->3->2->2->3.

2)
{"2-3", "1-3", "2-3", "2-1", "3-1"}

Returns: 3

3)
{"1-2", "3-2", "1-2", "2-1", "2-1", "3-2", "1-3", "3-1", "1-2"}

Returns: 1



// END CUT HERE
#line 56 "Thimbles.cxx"
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

class Thimbles {
	public:
		int thimbleWithBall(vector <string> swaps) 
		{		
			int pos = 1;
			forv(i, swaps)
			{
				int x, y;
				sscanf(swaps[i].c_str(), "%d-%d", &x, &y);
				if(pos == x || pos == y)
					pos = pos == x ? y : x;
			}
			return pos;
		}
};
