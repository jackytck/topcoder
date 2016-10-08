// BEGIN CUT HERE
// PROBLEM STATEMENT
// You are in the process of creating a crossword puzzle. You've already designed the board, but now you need to come up with words of various sizes to put in the puzzle. An empty crossword puzzle consists of filled squares ('X') and empty squares ('.').  Here is an example of a board with 5 rows and 6 columns:

X....XX.XX.X...X..X.XX.X..X...

A "slot" of length N is defined as exactly N empty squares in a row, surrounded on either side by either a filled square or the edge of the board.  N must be at least 2.  There are five horizontal slots in the example puzzle above:
First row, length = 4
Third row, length = 3
Third row, length = 2
Fifth row, length = 2
Fifth row, length = 3

Given a vector <string> board, representing an empty crossword puzzle, and an int size, your method should return the number of horizontal slots in the puzzle that are exactly size characters in length. Each element of board represents one row of the puzzle.

DEFINITION
Class:CrossWordPuzzle
Method:countWords
Parameters:vector <string>, int
Returns:int
Method signature:int countWords(vector <string> board, int size)


CONSTRAINTS
-board will contain between 3 and 50 elements, inclusive.
-Each element of board will contain between 3 and 50 characters, inclusive.
-Each element of board will be the same length.
-board will consist of only '.' and 'X' characters, and will contain at least two '.' characters.
-All '.' characters in board will be connected horizontally or vertically.
-size will be between 2 and 50, inclusive.


EXAMPLES

0)
{"X....X",
 "X.XX.X",
 "...X..",
 "X.XX.X",
 "..X..."}
3

Returns: 2

The example from above. Note that there are two horizontal slots with length = 3.

1)
{"...X...",
 ".X...X.",
 "..X.X..",
 "X..X..X",
 "..X.X..",
 ".X...X.",
 "...X..."}
3

Returns: 6

There are two slots of length 3 on both the first and seventh rows, and one slot each on the second and sixth rows, for a total of 6.

2)
{".....X....X....",
 ".....X....X....",
 "..........X....",
 "....X....X.....",
 "...X....X....XX",
 "XXX...X....X...",
 ".....X....X....",
 ".......X.......",
 "....X....X.....",
 "...X....X...XXX",
 "XX....X....X...",
 ".....X....X....",
 "....X..........",
 "....X....X.....",
 "....X....X....."}

5

Returns: 8

3)
{"...",
 "...",
 "..."}
50

Returns: 0

4)
{"....",
 "....",
 "...."}
3

Returns: 0

// END CUT HERE
#line 100 "CrossWordPuzzle.cxx"
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

class CrossWordPuzzle {
	public:
		int countWords(vector <string> board, int size) 
		{		
			int ret = 0;
			forv(i, board)
			{
				int slotSize = 0;
				forn(j, board[i].sz)
				{
					if(board[i][j] == 'X')
					{
						if(slotSize == size)
							ret++;
						slotSize = 0;
					}
					else if(j == board[i].sz-1)
					{
						if(slotSize == size-1)
							ret++;
					}
					else
						slotSize++;
				}
			}
			return ret;
		}
};
