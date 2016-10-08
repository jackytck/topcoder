// BEGIN CUT HERE
// PROBLEM STATEMENT
// SMS messages are short messages sent between mobile phones.  The maximum length of a single message is 160 characters, so it is often necessary to abbreviate words.

You are given a string text, and your task is to translate it to SMS language according to the following rules:

  Remove all punctuation symbols ('.', ',', '?' and '!').
  Replace all uppercase letters with their lowercase equivalents.
  Replace all occurrences of "and" with '&'.
  Replace all occurrences of "ate" with '8'.
  Replace all occurrences of "at" with '@'.
  Replace all occurrences of "you" with 'U'.

All quotes are for clarity only.  The rules must be applied in the order they appear in the list. For example, "I HATE rats, and you?" will be translated to "i h8 r@s & U".
Return the resulting translation as a string.

DEFINITION
Class:SMSLanguage
Method:translate
Parameters:string
Returns:string
Method signature:string translate(string text)


CONSTRAINTS
-text will contain between 1 and 50 characters, inclusive.
-text will contain only letters ('a'-'z', 'A'-'Z'), the characters ',', '.', '!', '?', and spaces (' ').


EXAMPLES

0)
"I HATE rats, and you?"

Returns: "i h8 r@s & U"

The example from the problem statement.

1)
"What is the weather like today?"

Returns: "wh@ is the we@her like today"



2)
"It is not too late to.."

Returns: "it is not too l8 to"



3)
"this text is already in sms language"

Returns: "this text is already in sms language"



// END CUT HERE
#line 62 "SMSLanguage.cxx"
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

class SMSLanguage {
	public:
		string translate(string text) 
		{		
			string sms;
			forn(i, text.sz)
				if(!(text[i] == '.' || text[i] == ',' || text[i] == '?' || text[i] == '!'))
					sms += text[i];
			forn(i, sms.sz)
				if(sms[i] - 'A' >= 0 && 'Z' - sms[i] >= 0)
					sms[i] = sms[i] - 'A' + 'a';
			while(sms.find("and") != string::npos)
				sms.replace(sms.find("and"), 3, "&");
			while(sms.find("ate") != string::npos)
				sms.replace(sms.find("ate"), 3, "8");
			while(sms.find("at") != string::npos)
				sms.replace(sms.find("at"), 2, "@");
			while(sms.find("you") != string::npos)
				sms.replace(sms.find("you"), 3, "U");
			return sms;
		}
};
