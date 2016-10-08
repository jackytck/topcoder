// BEGIN CUT HERE
// PROBLEM STATEMENT
// You are converting old code for a new compiler version. Each "->" string should be replaced by ".", but this replacement shouldn't be done inside comments. A comment is a string that starts with "//" and terminates at the end of the line.
You will be given a vector <string> program containing the old code.  Return a vector <string> containing the converted version of the code.


DEFINITION
Class:AccessChanger
Method:convert
Parameters:vector <string>
Returns:vector <string>
Method signature:vector <string> convert(vector <string> program)


CONSTRAINTS
-program will have between 1 and 50 elements, inclusive. 
-Each element of program will contain between 1 and 50 characters, inclusive. 
-Each character in program will have ASCII value between 32 and 127, inclusive.


EXAMPLES

0)
{"Test* t = new Test();", 
 "t->a = 1;", 
 "t->b = 2;", 
 "t->go(); // a=1, b=2 --> a=2, b=3"}

Returns: {"Test* t = new Test();", "t.a = 1;", "t.b = 2;", "t.go(); // a=1, b=2 --> a=2, b=3" }

1)
{"---> // the arrow --->",
 "---",
 "> // the parted arrow"}

Returns: {"--. // the arrow --->", "---", "> // the parted arrow" }

2)
{"->-> // two successive arrows ->->"}

Returns: {".. // two successive arrows ->->" }

// END CUT HERE
#line 45 "AccessChanger.cxx"
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

class AccessChanger {
	public:
		vector <string> convert(vector <string> program) 
		{		
			vector <string> ret;
			forv(i, program)
			{
				bool comment = false;
				string line;
				program[i] += ' ';
				forn(j, program[i].sz-1)
				{
					if(program[i][j] == '/' && program[i][j+1] == '/')
						comment = true;
					if(comment)
						line += program[i][j];
					else if(program[i][j] == '-' && program[i][j+1] == '>')
					{
						line += '.';
						j++;
					}
					else
						line += program[i][j];
				}
				ret.PB(line);
			}
			return ret;
		}
};
