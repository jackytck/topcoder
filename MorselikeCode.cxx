// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
Marge is rather concerned about the hoodlums that her son has been spending time with.  Aside from all of the time spent at the arcade, they communicate with each other through encrypted messages.  As a concerned parent, Marge wants to discover what the boys are talking about.

Marge knows parts of the boys' code library, given as a vector <string>.  Each element is formatted as "C SEQUENCE" (quotes for clarity), where C is an uppercase letter, SEQUENCE consists of only '-' and '.' characters, and exactly one space separates the two.  When writing their message, the boys will replace C with SEQUENCE, separating multiple letters with spaces.  So, if O is represented as "---" and S is represented as "...", then the message "SOS" can be encoded as "... --- ...".

Marge has recovered an encoded message that she would like to decode.  Unfortunately, she does not have a full copy of the library, so there may be some SEQUENCEs that do not correspond to any entries in the library; if this happens, you are to replace it with a '?' (Marge is a smart mom, and might be able to figure out what the word is with only partial information).  You are to return a string containing the decoded message.


DEFINITION
Class:MorselikeCode
Method:decrypt
Parameters:vector <string>, string
Returns:string
Method signature:string decrypt(vector <string> library, string message)


CONSTRAINTS
-library will contain between 1 and 50 elements, inclusive.
-Each element of library will contain between 3 and 50 characters, inclusive.
-Each element of library will be formatted as "C SEQUENCE" as described in the problem statement.
-In each element of library, C will be an uppercase letter ('A'-'Z').
-In each element of library, SEQUENCE will consist only of '.' and '-'.
-There will be no duplicate SEQUENCEs in library.
-message will contain between 1 and 50 characters, inclusive.
-Each character of message will be '-', '.', or a space (' ').
-There will be no leading, trailing, or consecutive spaces in message.


EXAMPLES

0)
{"O ---",
 "S ..."}
"... --- ..."

Returns: "SOS"

The example from the problem statement.

1)
{"O ---"}
"... --- ..."

Returns: "?O?"

This time we don't have the S, so we replace the three dashes with question marks.

2)
{"H -",
 "E .",
 "L --",
 "L ..",
 "O -."}
"- . -- .. -."

Returns: "HELLO"

Note that the clever boys can have multiple ways to encode the same letter.

3)
{"H -.-.-.-.-.-.-.-.-.-.",
 "I .-.-.-.-.-.-.-.-.-.-",
 "K -.-.-.-.-.",
 "E .-.-.-.-.-"}
"-.-.-.-.-.-.-.-.-.-. .-.-.-.-.-.-.-.-.-.-"

Returns: "HI"

A long message doesn't always mean a long word.

4)
{"O ---",
 "S ...",
 "B -...",
 "T -",
 "R .-.",
 "E .",
 "N -.",
 "X -..-",
 "D -.." }
"-... --- ... - --- -. .-. . -.. ... --- -..-"

Returns: "BOSTONREDSOX"



5)
{"B -...",
 "N -.",
 "H ....",
 "O --",
 "Z --..",
 "G ---",
 "I ..",
 "J .---" }
"--- -- -... .- -. .- -. .-"

Returns: "GOB?N?N?"



6)
{"A --",
 "B -.",
 "N ...-",
 "I --..",
 "F -.-.-."}
"-. -- -.-.-. -.-.-. --- --.. ...- .-..--."

Returns: "BAFF?IN?"



// END CUT HERE
#line 118 "MorselikeCode.cxx"
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

class MorselikeCode {
	public:
		string decrypt(vector <string> library, string message) 
		{		
			istringstream is(message);
			string ic, re;
			while( is >> ic)
			{
				bool exist = false;
				forv(i, library)
				{
					istringstream is2(library[i]);
					string a, b;
					is2 >> a;
					is2 >> b;
					if(b == ic)
					{
						re += a;
						exist = true;
						break;
					}
				}
				if(!exist)
					re += '?';
			}
			return re;
		}
};
