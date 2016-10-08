// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
Most modern text editors are able to give some statistics about the text they are editing.  One nice statistic is the average word length in the text.


A word is a maximal continuous sequence of letters ('a'-'z', 'A'-'Z').  Words can be separated by spaces, digits, and punctuation marks.


The average word length is the sum of all the words' lengths divided by the total number of words.  For example, in the text "This is div2 easy problem.", there are 5 words: "This", "is", "div", "easy", and "problem".  The sum of the word lengths is 4+2+3+4+7=20, so the average word length is 20/5=4.


Given a string text, return the average word length in it.  If there are no words in the text, return 0.0.



DEFINITION
Class:TextStatistics
Method:averageLength
Parameters:string
Returns:double
Method signature:double averageLength(string text)


NOTES
-The returned value must be accurate to within a relative or absolute value of 1E-9.


CONSTRAINTS
-text will contain between 0 and 50 characters, inclusive.
-text will contain only letters ('a'-'z', 'A'-'Z'), digits ('0'-'9'), spaces, and the following punctuation marks: ',', '.', '?', '!', '-'.


EXAMPLES

0)
"This is div2 easy problem."

Returns: 4.0

The example from the problem statement.

1)
"Hello, world!"

Returns: 5.0

In this case all words have the same length.

2)
"Simple"

Returns: 6.0

One word.

3)
""

Returns: 0.0

No words here, so return 0.

4)
"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"

Returns: 50.0



// END CUT HERE
#line 73 "TextStatistics.cxx"
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

class TextStatistics {
	public:
		double averageLength(string text) 
		{		
			int characters = 0, words = 0;
			forn(i, text.sz)
			{
				if((text[i]-'a' >= 0 && 'z'-text[i] >= 0) || (text[i]-'A' >= 0 && 'Z'-text[i] >= 0))
					characters++;
			}
			char buf[51], *p;
			strcpy(buf, text.c_str());
			for(p = strtok(buf, "0123456789 ,.?!-"); p != NULL; p = strtok(NULL, "0123456789 ,.?!-"))
				words++;
			return words == 0 ? 0.0: double(characters) / words;
		}
};
