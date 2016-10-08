// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
A chessboard is an 8 x 8 grid of cells. Within each column and within each row, cells alternate between black and white. The cell in the upper left corner (0, 0) is white. You are given a vector <string> board, where the j-th character of the i-th element is 'F' if the cell in the j-th column from the left and i-th row from the top is occupied, or '.' if it is empty. Return the number of occupied white cells on the board.



DEFINITION
Class:WhiteCells
Method:countOccupied
Parameters:vector <string>
Returns:int
Method signature:int countOccupied(vector <string> board)


CONSTRAINTS
-board will contain exactly 8 elements.
-Each element of board will contain exactly 8 characters.
-board will contain only the characters '.' and 'F'.


EXAMPLES

0)
{"........",
 "........",
 "........",
 "........",
 "........",
 "........",
 "........",
 "........"}

Returns: 0



1)
{"FFFFFFFF",
 "FFFFFFFF",
 "FFFFFFFF",
 "FFFFFFFF",
 "FFFFFFFF",
 "FFFFFFFF",
 "FFFFFFFF",
 "FFFFFFFF"}

Returns: 32



2)
{".F.F...F",
 "F...F.F.",
 "...F.F.F",
 "F.F...F.",
 ".F...F..",
 "F...F.F.",
 ".F.F.F.F",
 "..FF..F."}

Returns: 1



3)
{"........",
 "..F.....",
 ".....F..",
 ".....F..",
 "........",
 "........",
 ".......F",
 ".F......"}

Returns: 2



// END CUT HERE
#line 82 "WhiteCells.cxx"
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

class WhiteCells {
	public:
		int countOccupied(vector <string> board) 
		{		
			int cnt = 0;
			forv(i, board)
				forv(j, board)
					if( (i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1) )
						if(board[i][j] == 'F')
								cnt++;
			return cnt;
		}
};
