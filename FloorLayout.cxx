// BEGIN CUT HERE
// PROBLEM STATEMENT
// You are building a house and are about to lay the floorboards in a particular room. Your architect has designed the layout of the floorboards and you now want to know how many boards you need to buy. Each board is 1 unit wide and can be of any positive integer length. The room is rectangular and the boards are to be laid out on a unit-square grid inside the room, parallel to the walls of the room.
You are given a vector <string> layout describing the layout of the floorboards. Character j of element i of layout describes the grid-square at position (i, j) and will either be a '-' or a '|', depending on which direction the floorboard covering that square is oriented. If two '-' characters are adjacent at the same value of i, then they form part of the same east/west-oriented floorboard. Similarly, if two '|' characters are adjacent at the same value of j, they are part of the same north/south-oriented floorboard. Return an int containing the number of distinct floorboards in the layout.

DEFINITION
Class:FloorLayout
Method:countBoards
Parameters:vector <string>
Returns:int
Method signature:int countBoards(vector <string> layout)


CONSTRAINTS
-layout will contain between 1 and 50 elements, inclusive.
-Each element of layout will contain between 1 and 50 characters, inclusive.
-Each element of layout will contain the same number of characters.
-Each character in layout will be a '-' or a '|'.


EXAMPLES

0)
{"----"
,"----"
,"----"
,"----"}

Returns: 4

This layout contains 4 boards laid east/west.

1)
{"-||--||--"
,"--||--||-"
,"|--||--||"
,"||--||--|"
,"-||--||--"
,"--||--||-"}

Returns: 31

This is an aesthetic pattern made up of boards of lengths 1 and 2.

2)
{"--------"
,"|------|"
,"||----||"
,"|||--|||"
,"||----||"
,"|------|"
,"--------"}

Returns: 13



3)
{"||-||-|||-"
,"||--||||||"
,"-|-|||||||"
,"-|-||-||-|"
,"||--|-||||"
,"||||||-||-"
,"|-||||||||"
,"||||||||||"
,"||---|--||"
,"-||-||||||"}

Returns: 41



4)
{"-||--|"
,"||||||"
,"|||-|-"
,"-||||-"
,"||||-|"
,"||-||-"}

Returns: 19



// END CUT HERE
#line 88 "FloorLayout.cxx"
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
#define For(i, st, en) for(__typeof(en) i = (st); i < (en); i++)

using namespace std;

class FloorLayout {
	public:
		int countBoards(vector <string> layout) 
		{		
			int count = 0;
			forn(i, layout.sz)
			{
				vector<int> temp;
				forn(j, layout[0].sz)
				{
					if(layout[i][j] == '-')
					{
						temp.PB(j);
					}
				}
				int t = 0;
				forn(j, temp.sz)
				{
					if(j == 0 || temp[j] != t + 1)
					{
						count++;
					}
					t = temp[j];
				}
			}
			forn(i, layout[0].sz)
			{
				vector<int> temp;
				forn(j, layout.sz)
				{
					if(layout[j][i] == '|')
					{
						temp.PB(j);
					}
				}
				int t = 0;
				forn(j, temp.sz)
				{
					if(j == 0 || temp[j] != t + 1)
					{
						count++;
					}
					t = temp[j];
				}
			}
			return count;
		}
};
