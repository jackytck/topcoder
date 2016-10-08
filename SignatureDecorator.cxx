// BEGIN CUT HERE
// PROBLEM STATEMENT
// Some people like to have a particular custom signature following their emails or posts on online message boards.  These signatures usually contain the handle by which they are known, but then are decorated by various punctuation marks to make them look more interesting.  You, as administrator of a popular message board, would like to allow such decorations in people's signatures while enforcing a rule that the signature they use contains their name.  In order to do this, you allow people to set up a series of rules to apply to their handles to automatically generate their signatures.

You will be given a user's handle as a string, which will be made up of upper- and lower-case letters, numbers or underscores ('_').  You will also be given two vector <string>s representing a series of formatting commands.  Each element in commands is "prepend", "append" or "surround".  Each element of decorations is a series of punctuation characters (out of ,./;'<>?:"\|[]{}-=_+!@#$%^&*()~` ) to use.  The ith element of commands corresponds to the ith element of decorations.

Each instruction should be executed as follows:

	For a "prepend" command, put the decoration at the beginning of the name.
	For an "append" command, put the decoration at the end of the name.
	For a "surround" command, put the decoration at the beginning of the name and backwards at the end of the name.


The instructions should be executed in the order in which they appear, so if name is "Bob", commands is {"surround", "append", "prepend"}, and decorations is {"-=", "(", ")"} name would progressively go from "Bob" to "-=Bob=-" to "-=Bob=-(" to ")-=Bob=-(".

DEFINITION
Class:SignatureDecorator
Method:applyDecoration
Parameters:string, vector <string>, vector <string>
Returns:string
Method signature:string applyDecoration(string name, vector <string> commands, vector <string> decorations)


CONSTRAINTS
-name will be between 1 and 50 characters long, inclusive.
-commands and decorations and will have between 0 and 50 elements, inclusive.
-commands and decorations will have the same number of elements.
-Each element of decorations will have between 1 and 50 characters, inclusive.
-Each element of decorations will contain only the following characters: ,./;'<>?:"\|[]{}-=_+!@#$%^&*()~`
-Each element of commands will be either "prepend", "append", or "surround".
-name will be made up of only upper- or lower-case letters, numbers, and underscores ('_').


EXAMPLES

0)
"Bob"
{"surround", "append", "prepend"}
{"-=", "(", ")"}

Returns: ")-=Bob=-("

The example from the problem statement.

1)
"Super_Man_01"
{}
{}

Returns: "Super_Man_01"

2)
"4BcD3FgHIjklMN0pqrS7uVWxYZ_"
{"append", "prepend", "surround"}
{"`{[(", ")]}'", ",.;<>?:|-=_+!@#$%^&*~"}

Returns: ",.;<>?:|-=_+!@#$%^&*~)]}'4BcD3FgHIjklMN0pqrS7uVWxYZ_`{[(~*&^%$#@!+_=-|:?><;.,"

3)
"RacEcaR"
{"surround"}
{"([{/"}

Returns: "([{/RacEcaR/{[("

Turning the punctuation around backwards doesn't mean flipping individual characters.

// END CUT HERE
#line 70 "SignatureDecorator.cxx"
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

class SignatureDecorator {
	public:
		string applyDecoration(string name, vector <string> commands, vector <string> decorations) 
		{		
			forv(i, commands)
			{
				if(commands[i] == "append")
					name += decorations[i];
				else if(commands[i] == "prepend")
					name = decorations[i] + name;
				else
				{
					name = decorations[i] + name;
					forv(j, decorations[i])
						name += decorations[i][decorations[i].sz-1-j];
				}
			}
			return name;
		}
};
