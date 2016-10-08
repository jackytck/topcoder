// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
A chessboard pattern is a pattern that satisfies the following conditions:



The pattern has a rectangular shape.
The pattern contains only the characters '.' (a dot) and 'X' (an uppercase letter X). 
No two symbols that are horizontally or vertically adjacent are the same.
The symbol in the lower left corner of the pattern is '.' (a dot).



You are given two ints rows and columns. 
Write a method that computes the chessboard pattern with these dimensions, and returns
it in a vector <string>. The elements of the return value correspond to
rows of the pattern. Specifically, the first character of the last element of the return value represents the lower left corner (see example 0).


DEFINITION
Class:ChessboardPattern
Method:makeChessboard
Parameters:int, int
Returns:vector <string>
Method signature:vector <string> makeChessboard(int rows, int columns)


CONSTRAINTS
-rows will be between 1 and 50, inclusive.
-columns will be between 1 and 50, inclusive.


EXAMPLES

0)
8
8

Returns: {"X.X.X.X.", ".X.X.X.X", "X.X.X.X.", ".X.X.X.X", "X.X.X.X.", ".X.X.X.X", "X.X.X.X.", ".X.X.X.X" }

A standard chessboard. Note that the last element starts with a dot.

1)
1
20

Returns: {".X.X.X.X.X.X.X.X.X.X" }

A single row is a special case of a rectangle.

2)
5
1

Returns: {".", "X", ".", "X", "." }

And so is a single column.

3)
5
13

Returns: {".X.X.X.X.X.X.", "X.X.X.X.X.X.X", ".X.X.X.X.X.X.", "X.X.X.X.X.X.X", ".X.X.X.X.X.X." }



// END CUT HERE
#line 70 "ChessboardPattern.cxx"
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

class ChessboardPattern {
	public:
		vector <string> makeChessboard(int rows, int columns) 
		{		
			string cross;
			forn(i, columns)
				cross += "X";
			vector <string> ret(rows, cross);
			forv(i, ret)
			{
				forn(j, columns)
				{
					if((i%2 == 0 && j%2 == 0) || (i%2 == 1 && j%2 == 1))
						ret[i][j] = '.';
				}
			}
			reverse(ret.begin(), ret.end());
			return ret;
		}
};
