// BEGIN CUT HERE
// PROBLEM STATEMENT
// A sentence is called dancing if its first letter is uppercase and the case of each subsequent letter is the opposite of the previous letter. Spaces should be ignored when determining the case of a letter.  For example, "A b  Cd" is a dancing sentence because the first letter ('A') is uppercase, the next letter ('b') is lowercase, the next letter ('C') is uppercase, and the next letter ('d') is lowercase.
You will be given a string sentence. Turn the sentence into a dancing sentence by changing the cases of the letters where necessary.  All spaces in the original sentence must be preserved.

DEFINITION
Class:DancingSentence
Method:makeDancing
Parameters:string
Returns:string
Method signature:string makeDancing(string sentence)


CONSTRAINTS
-sentence will contain between 1 and 50 characters, inclusive.
-Each character in sentence will be a letter ('A'-'Z','a'-'z') or a space (' ').
-sentence will contain at least one letter ('A'-'Z','a'-'z').


EXAMPLES

0)
"This is a dancing sentence"

Returns: "ThIs Is A dAnCiNg SeNtEnCe"

1)
" This   is         a  dancing   sentence  "

Returns: " ThIs   Is         A  dAnCiNg   SeNtEnCe  "

Spaces should be ignored when determining the cases of the letters, but they should be preserved in the return value.

2)
"aaaaaaaaaaa"

Returns: "AaAaAaAaAaA"

3)
"z"

Returns: "Z"

// END CUT HERE
#line 46 "DancingSentence.cxx"
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

class DancingSentence {
	public:
		string makeDancing(string sentence) 
		{		
			bool up = true;
			forn(i, sentence.sz)
			{
				if(sentence[i] == ' ')
					continue;
				sentence[i] = up ? toupper(sentence[i]) : tolower(sentence[i]);
				up = !up;
			}
			return sentence;
		}
};
