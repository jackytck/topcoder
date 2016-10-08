// BEGIN CUT HERE
// PROBLEM STATEMENT
// A 8x8 chessboard is usually marked as follows: rows are marked by digits, 1 through 8, and columns are marked by letters, 'a' through 'h'. A cell is described by its column mark and then its row mark, like "e4".

While working on a chess program, you need to convert these descriptions into your internal cell numbers and back. Internally, cells are numbered row-by-row from 1 to 64 in your program, i.e., cell "a1" has number 1, cell "b1" has number 2, cell "c1" has number 3, ..., cell "h8" has number 64.

Given a String cell, describing either the cell mark or the cell number, change the notation (i.e., if you're given the mark you need to return the number, and vice versa).

DEFINITION
Class:Chessboard
Method:changeNotation
Parameters:string
Returns:string
Method signature:string changeNotation(string cell)


CONSTRAINTS
-cell will contain either a cell mark or a cell number.
-If cell contains a cell mark, it will contain exactly 2 characters: a lowercase letter between 'a' and 'h', inclusive, followed by a digit between '1' and '8', inclusive.
-If cell contains a cell number, it will be an integer between 1 and 64, inclusive, without leading zeros.


EXAMPLES

0)
"1"

Returns: "a1"

1)
"2"

Returns: "b1"

2)
"26"

Returns: "b4"

3)
"c1"

Returns: "3"

4)
"e4"

Returns: "29"

5)
"h8"

Returns: "64"

// END CUT HERE
#line 57 "Chessboard.cxx"
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

class Chessboard {
	public:
		string changeNotation(string cell) 
		{		
			char ret[3];
			int cn;
			if(cell[0]-'a' >= 0 && cell[0]-'h' <= 0)
				sprintf(ret, "%d", (cell[1]-'1') * 8 + cell[0]-'a'+1);
			else
			{
				sscanf(cell.c_str(), "%d", &cn);
				sprintf(ret, "%c%d", char((cn-1)%8 + 'a'), (cn-1)/8+1);
			}
			return ret;
		}
};
