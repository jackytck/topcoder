// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
CSS property names are typically all lowercase and written in dash-separated notation, which means that each pair of adjacent words is separated by a single dash.  For example, "z-index", "padding-left", and "border-collapse" are typical names.  However, if you use JavaScript to set CSS style properties, you need to use camel notation, where each word except the first starts with an uppercase letter, and adjacent words are not separated. All other letters are lowercase. For example, "z-index" would become "zIndex" in camel notation.


You are given a String cssPropertyName containing a property name written in dash-separated notation.  Convert cssPropertyName to camel notation and return the result.



DEFINITION
Class:CssPropertyConverter
Method:getCamelized
Parameters:string
Returns:string
Method signature:string getCamelized(string cssPropertyName)


CONSTRAINTS
-cssPropertyName will contain between 1 and 50 characters, inclusive.
-cssPropertyName will contain only lowercase letters ('a'-'z') and dashes ('-').
-Each dash in cssPropertyName will be surrounded by two letters.


EXAMPLES

0)
"z-index"

Returns: "zIndex"



1)
"border-collapse"

Returns: "borderCollapse"



2)
"top-border-width"

Returns: "topBorderWidth"



// END CUT HERE
#line 50 "CssPropertyConverter.cxx"
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

class CssPropertyConverter {
	public:
		string getCamelized(string cssPropertyName) 
		{		
			string ret;
			vector <string> bv;
			char buf[51], *p;
			strcpy(buf, cssPropertyName.c_str());
			for(p = strtok(buf, "-"); p != NULL; p = strtok(NULL, "-"))
				bv.PB(p);
			ret += bv[0];
			For(i, 1, bv.sz)
			{
				string t = bv[i];
				t[0] = toupper(t[0]);
				ret += t;
			}
			return ret;
		}
};
