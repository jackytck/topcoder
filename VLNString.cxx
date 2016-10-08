// BEGIN CUT HERE
// PROBLEM STATEMENT
// An acronym is a sequence of characters that is used to refer to something with a very long name. An acronym is generated from a long name by capitalizing the first letter of every word in the name and concatenating them together. There are three exceptions: the common words "and", "the", and "of" are ignored when generating the acronym. In this problem, a word is defined as one or more non-space characters preceded by either a space or the beginning of the string and followed by either a space or the end of the string. Write a class VLNString with a method makeAcronym that takes a string longName and returns a string with its acronym generated as described above.

DEFINITION
Class:VLNString
Method:makeAcronym
Parameters:string
Returns:string
Method signature:string makeAcronym(string longName)


NOTES
-longName may contain leading and trailing spaces, and there may be more than one space between words.
-The return value may be an empty string.


CONSTRAINTS
-longName will contain between 1 and 50 characters, inclusive.
-longName will contain only lowercase English letters ('a' to 'z') and space characters.


EXAMPLES

0)
"dance dance revolution"

Returns: "DDR"

1)
"  return  of  the king   "

Returns: "RK"

2)
"the united states of america"

Returns: "USA"

3)
" of  the   and    "

Returns: ""

4)
" "

Returns: ""

// END CUT HERE
#line 52 "VLNString.cxx"
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

class VLNString {
	public:
		string makeAcronym(string longName) 
		{		
			string ret = "";
			stringstream ss(longName);
			string word;
			while(ss >> word)
				if(word != "and" && word != "the" && word != "of" && word.sz != 0)
					ret += toupper(word[0]);
			return ret;
		}
};
