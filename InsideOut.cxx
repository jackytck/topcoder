// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
Your printer has been infected by a virus and is printing gibberish.  After staring at several printed pages for a while, you realize that it is printing every line inside-out.  In other words, the left half of each line is being printed starting in the middle of the page and proceeding out toward the left margin.  Similarly, the right half of each line is being printed starting at the right margin and proceeding in toward the middle of the page.
For example, the line


    THIS LINE IS GIBBERISH

is being printed as

    I ENIL SIHTHSIREBBIG S

Your task is to unscramble a string line from its printed form back into its original order.
You can assume that line contains an even number of characters.

DEFINITION
Class:InsideOut
Method:unscramble
Parameters:string
Returns:string
Method signature:string unscramble(string line)


CONSTRAINTS
-line contains between 2 and 50 characters, inclusive.
-line contains an even number of characters.
-line contains only uppercase letters ('A'-'Z') and spaces (' ').


EXAMPLES

0)
"I ENIL SIHTHSIREBBIG S"

Returns: "THIS LINE IS GIBBERISH"

The example above.

1)
"LEVELKAYAK"

Returns: "LEVELKAYAK"

2)
"H YPPAHSYADILO"

Returns: "HAPPY HOLIDAYS"

3)
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"

Returns: "MLKJIHGFEDCBAZYXWVUTSRQPON"

4)
"RUT OWT SNEH HCNERF EERHTEGDIRTRAP A DNA  SEVODELT"

Returns: "THREE FRENCH HENS TWO TURTLEDOVES  AND A PARTRIDGE"

// END CUT HERE
#line 62 "InsideOut.cxx"
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

class InsideOut {
	public:
		string unscramble(string line) 
		{		
			reverse(line.begin(), line.begin()+line.sz/2);
			reverse(line.begin()+line.sz/2, line.end());
			return line;
		}
};
