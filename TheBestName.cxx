// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
As some of you may know, there is no name better than JOHN. Let's define the rules for comparing names. Each letter has a weight ('A' - 1, 'B' - 2, ..., 'Z' - 26). The weight of a name is the sum of the weights of all its letters. For example, the name MARK has weight 13 + 1 + 18 + 11 = 43.



When comparing two names, the one with the larger weight is considered better. In case of a tie, the one that comes earlier lexicographically is better. But there is one exception - the name JOHN is the best name of all.



You are given a vector <string> names, each element of which contains a single name. Sort the names from best to worst and return the sorted vector <string>.



DEFINITION
Class:TheBestName
Method:sort
Parameters:vector <string>
Returns:vector <string>
Method signature:vector <string> sort(vector <string> names)


CONSTRAINTS
-names will contain between 1 and 50 elements, inclusive.
-Each element of names will contain between 1 and 50 characters, inclusive.
-Each element of names will contain only uppercase letters ('A'-'Z').


EXAMPLES

0)
{"JOHN", "PETR", "ACRUSH"}

Returns: {"JOHN", "ACRUSH", "PETR" }

PETR has weight 59, ACRUSH has weight 70 and JOHN has a weight of only 47. But nevertheless JOHN is the best name, ACRUSH takes second place and PETR is the last.

1)
{"GLUK", "MARGARITKA"}

Returns: {"MARGARITKA", "GLUK" }

MARGARITKA is definitely better than GLUK.


2)
{"JOHN", "A", "AA", "AAA", "JOHN", "B", "BB", "BBB", "JOHN", "C", "CC", "CCC", "JOHN"}

Returns: {"JOHN", "JOHN", "JOHN", "JOHN", "CCC", "BBB", "CC", "BB", "AAA", "C", "AA", "B", "A" }

AA and B both have the same weight, but AA is better as it comes earlier lexicographically. For the same reason, AAA is better than C and BBB is better than CC.

3)
{"BATMAN", "SUPERMAN", "SPIDERMAN", "TERMINATOR"}

Returns: {"TERMINATOR", "SUPERMAN", "SPIDERMAN", "BATMAN" }

Here are some superheroes sorted by their names.

// END CUT HERE
#line 63 "TheBestName.cxx"
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
#define clr(x) memset(x, 0, sizeof(x))
#define forn(i,n) for(__typeof(n) i = 0; i < (n); i++)
#define ford(i,n) for(int i = (n) - 1; i >= 0; i--)
#define For(i, st, en) for(__typeof(en) i = (st); i < (en); i++)

using namespace std;

bool cmp(string a, string b)
	{
		if(a == "JOHN") return true;
		if(b == "JOHN") return false;
		int wa = 0, wb = 0;
		forn(i, a.sz)
		{
			wa += a[i] - 'A' + 1;
		}
		forn(i, b.sz)
		{
			wb += b[i] - 'A' + 1;
		}
		if(wa < wb)
		{
			return false;
		}
		else if(wa > wb)
		{
			return true;
		}
		else
		{
			return a < b;
		}
	}

class TheBestName {
	public:
		vector <string> sort(vector <string> names) 
		{		
			std::sort(names.begin(), names.end(), cmp); 
			return names;
		}
};
