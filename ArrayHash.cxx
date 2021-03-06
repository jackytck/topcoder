// BEGIN CUT HERE
// PROBLEM STATEMENT
// You will be given a vector <string> input.  The value of each character in input is computed as follows:
   Value = (Alphabet Position) + (Element of input) + (Position in Element) 

All positions are 0-based.  'A' has alphabet position 0, 'B' has alphabet position 1, ... The returned hash is the sum of all character values in input. 
For example, if 
input = {"CBA",
         "DDD"}
then each character value would be computed as follows: 
2 =   2 + 0 + 0   :  'C' in element 0 position 0
2 =   1 + 0 + 1   :  'B' in element 0 position 1
2 =   0 + 0 + 2   :  'A' in element 0 position 2
4  =  3 + 1 + 0   :  'D' in element 1 position 0
5  =  3 + 1 + 1   :  'D' in element 1 position 1
6  =  3 + 1 + 2   :  'D' in element 1 position 2
 The final hash would be 2+2+2+4+5+6 = 21.

DEFINITION
Class:ArrayHash
Method:getHash
Parameters:vector <string>
Returns:int
Method signature:int getHash(vector <string> input)


CONSTRAINTS
-input will contain between 1 and 50 elements inclusive.
-Each character in each element of input will be a capital letter ('A'-'Z').
-Each element of input will contain between 1 and 50 characters inclusive.
-Each element of input will contain the same number of characters.


EXAMPLES

0)
{"CBA",
 "DDD"}

Returns: 21

From the problem statement.

1)
{"Z"}

Returns: 25

A very small example.

2)
{"A",
 "B",
 "C",
 "D",
 "E",
 "F"}

Returns: 30

Tall and narrow.

3)
{"ABCDEFGHIJKLMNOPQRSTUVWXYZ",
 "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
 "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
 "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
 "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
 "ABCDEFGHIJKLMNOPQRSTUVWXYZ"}


Returns: 4290

4)
{"ZZZZZZZZZZ"}

Returns: 295

// END CUT HERE
#line 81 "ArrayHash.cxx"
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

class ArrayHash {
	public:
		int getHash(vector <string> input) 
		{		
			int ret = 0;
			forv(i, input)
				forv(j, input[i])
					ret += input[i][j]-'A' + i + j;
			return ret;
		}
};
