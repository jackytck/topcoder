// BEGIN CUT HERE
// PROBLEM STATEMENT
// You are in a mountainous area which is represented by a vector <string> areaMap. The j-th character of the i-th element of the areaMap is a digit '0'-'9' representing the height of cell (i, j). You perform a walk in the area according to the following rules:

You start from cell (0, 0).
If you are in cell (i, j), you examine cells (i+1, j), (i, j-1), (i-1, j), (i, j+1) in this order. You go to the first of these cells you can enter. You can enter a cell if it is still on the map, you haven't been to it before and the difference between the heights of your current cell and the cell you want to enter is no bigger (in absolute value) than heightDifference.
You end your walk if you can not make another move, i.e., if you can not enter any neighboring cell.

You must return the number of cells that you visit while performing your walk. You visit cell (i, j) if and only if you enter cell (i, j) at some point during your walk (the starting cell (0, 0) also counts as entered, i.e., you definitely visit (0, 0)). Note that you will visit each cell at most once since you never enter the same cell twice.

DEFINITION
Class:MountainWalk
Method:cellsVisited
Parameters:vector <string>, int
Returns:int
Method signature:int cellsVisited(vector <string> areaMap, int heightDifference)


CONSTRAINTS
-areaMap will contain between 1 and 50 elements, inclusive.
-All the elements of areaMap will contain the same number of characters.
-Each element of areaMap will contain between 1 and 50 digits ('0' - '9'), inclusive.
-heightDifference will be between 0 and 9, inclusive.


EXAMPLES

0)
{"056",
 "135",
 "234"}
1

Returns: 5

Your path goes (0, 0) --> (1, 0) --> (2, 0) --> (2, 1) --> (1, 1) and so you visit 5 cells.

1)
{"056",
 "195",
 "234"}
1

Returns: 8

Now you can not enter the cell (1, 1) because of the cell difference so your path goes (0, 0) --> (1, 0) --> (2, 0) --> (2, 1) --> (2, 2) --> (1, 2) --> (0, 2) --> (0, 1).

2)
{"865",
 "123",
 "111"}
3

Returns: 9

Your path is (0, 0) --> (0, 1) --> (0, 2) --> (1, 2) --> (2, 2) --> (2, 1) --> (2, 0) --> (1, 0) --> (1, 1).

3)
{"00009876543210",
 "00009876543210",
 "00009876543210",
 "00009876543210"}
8

Returns: 16



4)
{"0000",
 "0000",
 "0000",
 "0000",
 "9999",
 "8888",
 "7777",
 "6666",
 "5555",
 "4444",
 "3333",
 "2222",
 "1111",
 "0000"}
3

Returns: 16



5)
{"173642855131893831828253420",
 "126290035950506994475683704",
 "381277675415026563959463393",
 "019782700912864681764582260",
 "496448425114634806770407597",
 "049628433145840178727435051",
 "117194708226266248973780562",
 "398138380998246682323622510",
 "408178777661559971959512111"}
8

Returns: 135



6)
{"9"}
0

Returns: 1



// END CUT HERE
#line 116 "MountainWalk.cxx"
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

class MountainWalk {
	public:
		int cellsVisited(vector <string> areaMap, int heightDifference) 
		{		
			int cnt = 1, i = 0, j = 0; 
			char temp = areaMap[0][0];
			bool die = false;
			areaMap[0][0] = '#';
			while(!die)
			{
				if(i+1 >= 0 && i+1 < areaMap.sz && areaMap[i+1][j] != '#' && max(areaMap[i+1][j], temp) - min(areaMap[i+1][j], temp) <= heightDifference)
				{
					cnt++;
					i += 1;
					temp = areaMap[i][j];
					areaMap[i][j] = '#';
				}
				else if(j-1 >= 0 && j-1 < areaMap[0].sz && areaMap[i][j-1] != '#' && max(areaMap[i][j-1], temp) - min(areaMap[i][j-1], temp) <= heightDifference)
				{
					cnt++;
					j -= 1;
					temp = areaMap[i][j];
					areaMap[i][j] = '#';
				}
				else if(i-1 >= 0 && i-1 < areaMap.sz && areaMap[i-1][j] != '#' && max(areaMap[i-1][j], temp) - min(areaMap[i-1][j], temp) <= heightDifference)
				{
					cnt++;
					i -= 1;
					temp = areaMap[i][j];
					areaMap[i][j] = '#';
				}
				else if(j+1 >= 0 && j+1 < areaMap[0].sz && areaMap[i][j+1] != '#' && max(areaMap[i][j+1], temp) - min(areaMap[i][j+1], temp) <= heightDifference)
				{
					cnt++;
					j += 1;
					temp = areaMap[i][j];
					areaMap[i][j] = '#';
				}
				else
					die = true;
			}
			return cnt;
		}
};
