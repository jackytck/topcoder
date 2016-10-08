// BEGIN CUT HERE
// PROBLEM STATEMENT
// In the English language, the plural form of a noun is created according to many difficult rules, but for the most part, a noun can be transformed into its plural form using four simple rules. These rules are: 


If the word ends in 's', 'z', 'x', 'ch' or 'sh', add 'es' to the end of the word;


If the word ends in 'ay', 'ey', 'iy', 'oy' or 'uy', add 's' to the end of the word;


If the word ends in 'y', but doesn't satisfy the previous rule, replace the trailing 'y' with 'ies';


In all other cases, just add 's' to the end of the word.





You will be given a vector <string> nouns. Transform each element of nouns into its plural form using the rules above and return the resulting vector <string>. 



DEFINITION
Class:NounReform
Method:makePlural
Parameters:vector <string>
Returns:vector <string>
Method signature:vector <string> makePlural(vector <string> nouns)


CONSTRAINTS
-nouns will contain between 1 and 50 elements, inclusive. 
-Each element of nouns will contain between 1 and 20 characters, inclusive. 
-Each element of nouns will consist of only lower-case letters ('a'-'z'). 


EXAMPLES

0)
{"box", "church", "elephant", "stereo"}

Returns: {"boxes", "churches", "elephants", "stereos" }

1)
{"tray", "key", "enemy", "baby"}

Returns: {"trays", "keys", "enemies", "babies" }

2)
{"a", "s", "oy", "y", "yy"}

Returns: {"as", "ses", "oys", "ies", "yies" }

// END CUT HERE
#line 58 "NounReform.cxx"
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

class NounReform {
	public:
		vector <string> makePlural(vector <string> nouns) 
		{		
			forv(i, nouns)
			{
				char lc = nouns[i][nouns[i].sz-1];
				if(lc == 'y')
				{
					string v = "aeiou";
					if(nouns[i].sz >= 2 && v.find(nouns[i][nouns[i].sz-2]) != string::npos)
						nouns[i] += "s";
					else
					{
						nouns[i][nouns[i].sz-1] = 'i';
						nouns[i] += "es";
					}
				}
				else if(lc == 's' || lc == 'z' || lc == 'x')
					nouns[i] += "es";
				else if(lc == 'h' && nouns[i].sz >= 2 && (nouns[i][nouns[i].sz-2] == 'c' || nouns[i][nouns[i].sz-2] == 's'))
					nouns[i] += "es";
				else
					nouns[i] += "s";
			}
			return nouns;
		}
};
