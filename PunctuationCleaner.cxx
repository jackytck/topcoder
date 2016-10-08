// BEGIN CUT HERE
// PROBLEM STATEMENT
// Some writers like to super-emphasize certain points by using multiple exclamation points instead of one.  For example, "This cheese is really great!!!  I like exclamation points!!!!!!!!"  Other times, writers express surprise by mixing exclamation points and question marks.  For example, "You really like THIS cheese!?!?!?!!!?".
?

You are editing a document for publication, and you'd like to get rid of some of the extra punctuation.  Wherever you see a group of multiple consecutive exclamation points, replace it with a single exclamation point.  Wherever you see a group of multiple consecutive punctuation characters containing at least one question mark and zero or more exclamation points (and no other characters), replace that group with a single question mark.  See the examples for further clarification.  Return the string after these changes have been made.

DEFINITION
Class:PunctuationCleaner
Method:clearExcess
Parameters:string
Returns:string
Method signature:string clearExcess(string document)


CONSTRAINTS
-document will contain between 1 and 50 characters, inclusive.
-document will contain only letters ('a'-'z', 'A'-'Z'), spaces (' '), question marks ('?'), and exclamation points ('!').


EXAMPLES

0)
"This cheese is really great!!!!!"

Returns: "This cheese is really great!"



1)
"You really like THIS cheese!?!?!?!!!?"

Returns: "You really like THIS cheese?"



2)
" !!?X! ?? This is delicious!!! ??!a!?!"

Returns: " ?X! ? This is delicious! ?a?"

Sometimes writers get very carried away.  Remember to preserve spaces and other characters from the input.

// END CUT HERE
#line 46 "PunctuationCleaner.cxx"
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

class PunctuationCleaner {
	public:
		string clearExcess(string document) 
		{		
			string re = "";
			bool ex = false, qu = false;
			forn(i, document.sz)
			{
				if(document[i] == '!' && !qu)
				{
					ex = true;
				}
				else if(document[i] == '?')
				{
					qu = true;
					ex = false;
				}
				if(document[i] != '!' && document[i] != '?')
				{
					if(ex)
					{
						re += '!';
						ex = false;
					}
					else if(qu)
					{
						re += '?';
						qu = false;
					}
					re += document[i];
				}
			}
			if(ex)
				re += '!';
			else if(qu)
				re += '?';
			return re;
		}
};
