// BEGIN CUT HERE
// PROBLEM STATEMENT
// In a chess tournament, each pair of distinct players played a single match against each other.  Each match resulted in one of three outcomes: the first player won, the second player won, or there was a draw.  The ambiguity number of the tournament is defined as the number of distinct triples of players (a, b, c) such that player a defeated b, player b defeated player c, and player c defeated player a.

You are given the results of all the matches as a vector <string> table.  The j-th character of the i-th element of table is '1' (one) if player i defeated player j, '0' (zero) if player j defeated player i, or '-' if the match between players i and j resulted in a draw.  Return the ambiguity number of the given tournament.

DEFINITION
Class:TournamentsAmbiguityNumber
Method:scrutinizeTable
Parameters:vector <string>
Returns:int
Method signature:int scrutinizeTable(vector <string> table)


CONSTRAINTS
-table will contain between 1 and 50 elements, inclusive.
-Each element of table will contain exactly n characters, where n is the number of elements in table.
-Each character in each element of table will be '1' (one), '0' (zero), or '-'.
-The i-th character of the j-th element of table will be '1' if and only if the j-th character of the i-th element of table is '0'.
-The i-th character of the j-th element of table will be '-' if and only if the j-th character of the i-th element of table is '-'.
-The i-th character of the i-th element of table will be '-'.


EXAMPLES

0)
{"-10",
 "0-1",
 "10-"}

Returns: 3

Player 0 defeated player 1, player 1 defeated player 2, and player 2 defeated player 0.

1)
{"----",
 "----",
 "----",
 "----"}

Returns: 0

All matches ended in a draw.

2)
{"-1",
 "0-"}

Returns: 0

Too few players to form a triple.

3)
{"--1-10-1---1--1-00",
 "--0110000--0---10-",
 "01--00000100-00011",
 "-0---0010-11110100",
 "001--01-00-0001-1-",
 "11111--100--1-1-01",
 "-1110--00110-11-01",
 "0110-01--100110-10",
 "-111111---01--0-01",
 "--0-1100----10011-",
 "--10--011--1--101-",
 "01101-110-0--1-0-1",
 "---010-0-0---00-11",
 "--101-00-1-01-0-0-",
 "0-110001110-11-110",
 "-010-----011--0--0",
 "11010110100-010--0",
 "1-01-0010--00-111-"}

Returns: 198



// END CUT HERE
#line 79 "TournamentsAmbiguityNumber.cxx"
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

class TournamentsAmbiguityNumber {
	public:
		int scrutinizeTable(vector <string> table) 
		{		
			int count = 0;
			forv(i, table)
				forv(j, table)
					forv(k, table)
					{
						if( table[i][j] == '1' && table[j][k] == '1' && table[k][i] == '1')
							count++;
					}
			return count;
		}
};
