// BEGIN CUT HERE
// PROBLEM STATEMENT
// A common word-processing task is capitalizing the first letter of each word in a title.  Write a class TitleString with a method toFirstUpperCase that takes a string title containing lowercase words separated by one or more space characters and returns a string that is identical to title except with the first character of each word capitalized.

DEFINITION
Class:TitleString
Method:toFirstUpperCase
Parameters:string
Returns:string
Method signature:string toFirstUpperCase(string title)


NOTES
-title may have leading or trailing spaces.


CONSTRAINTS
-title will contain between 0 and 50 characters, inclusive.
-Each character of title will either be a space or a lowercase letter ('a' to 'z').


EXAMPLES

0)
"introduction to algorithms"

Returns: "Introduction To Algorithms"

1)
"more than  one   space    between     words"

Returns: "More Than  One   Space    Between     Words"

2)
"  lord of the rings   the fellowship of the ring  "

Returns: "  Lord Of The Rings   The Fellowship Of The Ring  "

3)
"  "

Returns: "  "

4)
"i"

Returns: "I"

5)
"the king and i"

Returns: "The King And I"

6)
""

Returns: ""

// END CUT HERE
#line 61 "TitleString.cxx"
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

class TitleString {
	public:
		string toFirstUpperCase(string title) 
		{		
			forv(i, title)
			{
				if(i==0 && title[i] != ' ')
					title[i] = toupper(title[i]);
				else
					if(title[i] != ' ' && title[i-1] == ' ')
						title[i] = toupper(title[i]);
			}
			return title;
		}
};
