// BEGIN CUT HERE
// PROBLEM STATEMENT
// Your company is working on writing a piece of software to compress a text document.  As part
of the software development team, you have been asked to write a function that will find the
longest repeated sub-string within a piece of text, such that the two chosen occurrences of the sub-string do not overlap.  Your software is case sensitive, so two sub-strings are not the same if their capitalization differs.  You have been instructed that, in a case where more than one such sub-string is the longest, the one that occurs earliest in the source string should be chosen.
For instance, given the string "ABCDABCFG", the longest repeated sub-string is "ABC".  In the
string "ABABA", both "AB" and "BA" are repeated substrings, however, we choose "AB", since it occurs earlier.  (Even though "ABA" appears twice as a
sub-string, the two occurrences overlaps, so that can not be used.)
You are given a string sourceText.  You are to return a string
that is the longest repeated sub-string.  If more than one substring of equal maximum length is repeated, return the one that occurs first in the string.  If no sub-string repeats itself, return "".

DEFINITION
Class:TextCompressor
Method:longestRepeat
Parameters:string
Returns:string
Method signature:string longestRepeat(string sourceText)


CONSTRAINTS
-sourceText will contain between 1 and 50 characters, inclusive.
-Each character of sourceText will be 'A'-'Z', 'a'-'z', '0'-'9', '.' or ' '.


EXAMPLES

0)
"ABCDABCFG"

Returns: "ABC"

The first example from the problem statement.

1)
"ABABA"

Returns: "AB"

The second example from the problem statement.  Notice in particular that the two occurrences cannot overlap.  Also, notice that "BA" is repeated as well, but "AB" occurs earlier in the string.

2)
"This is a test."

Returns: "is "

Notice here that the longest repeated substring is not restricted to just being a complete word, or part of a word, and may include spaces.

3)
"Testing testing 1 2 3."

Returns: "esting "

Notice here that although the word "testing" appears twice, the capitalization is different, so it's not actually a repeated substring.

4)
"The quick brown fox jumps over the lazy dog."

Returns: "he "

// END CUT HERE
#line 62 "TextCompressor.cxx"
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

class TextCompressor {
	public:
		string longestRepeat(string sourceText) 
		{		
			for(int i=sourceText.sz/2; i>=1; i--)
				for(int j=0; j<sourceText.sz && j+i<=sourceText.sz; j++)
					for(int k=j+i; k<sourceText.sz && k+i<=sourceText.sz; k++)
						if(sourceText.substr(j, i) == sourceText.substr(k, i))
							return sourceText.substr(j, i);
			return "";
		}
};
