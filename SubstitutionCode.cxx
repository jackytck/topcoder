// BEGIN CUT HERE
// PROBLEM STATEMENT
// A simple, easy to remember system for encoding integer amounts can be very useful.
For example, dealers at flea markets put the information about an item on a card 
that they let potential buyers see.  They find it advantageous to encode the 
amount they originally paid for the item on the card.

A good system is to use a substitution code, in which each digit is encoded by a 
letter.  An easy to remember 10-letter word or phrase, the key, is chosen. Every
'1' in the value is replaced by the first letter of the key, every '2' is replaced by the
second letter of the key, and so on. Every '0' is replaced by the last letter of
the key.  Letters that do not appear in the key can be inserted anywhere without affecting the value represented by the code..  This
helps to make the resulting code much harder to break (without knowing the key).

Create a class SubstitutionCode that contains the method getValue that is given the 
strings key and code as input and that returns the decoded value.



DEFINITION
Class:SubstitutionCode
Method:getValue
Parameters:string, string
Returns:int
Method signature:int getValue(string key, string code)


CONSTRAINTS
-code contains between 1 and 9 characters inclusive, all uppercase letters 'A'-'Z'
-code contains at least one letter that is found in key
-key contains exactly 10 uppercase letters 'A'-'Z', all distinct from each other


EXAMPLES

0)
"TRADINGFEW"
"LGXWEV"

Returns: 709

 

The L,X, and V are ignored since they do not appear in the key. G is the
seventh letter in the key, W is the 10th letter, and E is the 9th letter.

 

1)
"ABCDEFGHIJ"
"XJ"

Returns: 0

2)
"CRYSTALBUM"
"MMA"

Returns: 6

// END CUT HERE
#line 63 "SubstitutionCode.cxx"
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

class SubstitutionCode {
	public:
		int getValue(string key, string code) 
		{		
			string ret;
			key = key[key.sz-1] + key;
			forn(i, code.sz)
			{
				forn(j, key.sz-1)
				{
					if(code[i] == key[j])
					{
						stringstream ss;
						ss << j;
						char digit;
						ss >> digit;
						ret += digit;
					}
				}
			}
			stringstream ss(ret);
			int ret2;
			ss >> ret2;
			return ret2;
		}
};
