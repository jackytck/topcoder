// BEGIN CUT HERE
// PROBLEM STATEMENT
// You have received the transcript of an online chat.  Each element of transcript corresponds to a line.  You want to know how many times name said something.  To do this, count how many lines begin with name immediately followed by a colon.  This comparison is case sensitive.

DEFINITION
Class:ChatTranscript
Method:howMany
Parameters:vector <string>, string
Returns:int
Method signature:int howMany(vector <string> transcript, string name)


CONSTRAINTS
-transcript will contain between 1 and 50 elements inclusive.
-Each element of transcript will contain between 1 and 50 characters inclusive.
-Each character in each element of transcript will have ASCII value between 32 and 126 inclusive.
-name will contain between 1 and 50 characters inclusive.
-Each character in name will be a letter (A-Z, a-z) or a digit (0-9).


EXAMPLES

0)
{
"Bob: Hello Tim.",
"Tim: Hello Bob.",
"Bob: How are ya Tim?",
"Frank: Stop chatting!"
}
"Bob"

Returns: 2

Bob managed to say two things before Frank entered the conversation.

1)
{
"Bob: This is a long",
"sentence that takes 2 lines.",
"Tim: Yes it is.",
"Bob : I am not Bob.",
"Frank: No you aren't!",
" Bob: Neither am I."
}
"Bob"

Returns: 1

Only one line begins with "Bob:" (quotes for clarity).

2)
{
"Crazy1010: !@LK%#L%K @#L%K @#L%K@#L%K2kl53k2",
"Bob: You are crazy.",
"Crazy1010 Yup #@LK%$L!K%LK%!K% !K afmas,"
}
"Crazy1010"

Returns: 1

3)
{
"A:A:A:A:A:A:A:A:A",
"b:b:b:b:b:b:b:b:b"
}
"B"

Returns: 0

4)
{"A:A:A:A:A:A:A:A:A"}
"A"

Returns: 1

// END CUT HERE
#line 78 "ChatTranscript.cxx"
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

class ChatTranscript {
	public:
		int howMany(vector <string> transcript, string name) 
		{		
			int ret = 0;
			name += ':';
			forv(i, transcript)
			{
				bool speaks = true;
				forn(j, name.sz)
					if(j >= transcript[i].sz || transcript[i][j] != name[j])
						speaks = false;
				if(speaks)
					ret++;
			}
			return ret;
		}
};
