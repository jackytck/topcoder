// BEGIN CUT HERE
// PROBLEM STATEMENT
// Numbers are far easier to spell in Esperanto than in English.  Numbers 1 through 10 are spelled as follows: "unu", "du", "tri", "kvar", "kvin", "ses", "sep", "ok", "nau", "dek".  Numbers 11 through 19 are spelled: "dek unu", "dek du", ..., "dek nau" - a "dek" followed by a single space and the number for the last digit.  Numbers 20 through 29 are spelled: "dudek", "dudek unu", "dudek du", ..., "dudek nau".  Similarly, 30 is "tridek", ..., 90 is "naudek" - we just join together the number of tens and "dek".  There are no exceptions like "twelve" or "thirty" in English.

Given an int x between 1 and 99, inclusive, return its Esperanto spelling.

DEFINITION
Class:EsperantoNumbers
Method:nameThisNumber
Parameters:int
Returns:string
Method signature:string nameThisNumber(int x)


CONSTRAINTS
-x will be between 1 and 99, inclusive.


EXAMPLES

0)
1

Returns: "unu"



1)
90

Returns: "naudek"



2)
11

Returns: "dek unu"



3)
57

Returns: "kvindek sep"



// END CUT HERE
#line 51 "EsperantoNumbers.cxx"
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

class EsperantoNumbers {
	public:
		string nameThisNumber(int x) 
		{		
			string ret;
			string Esperanto[] = {"unu", "du", "tri", "kvar", "kvin", "ses", "sep", "ok", "nau", "dek"};
			if(x<11)
				ret = Esperanto[x-1];
			else if(x<20)
				ret = "dek " + Esperanto[x%10-1];
			else
			{
				ret = Esperanto[x/10-1] + "dek";
			       	if(x%10 != 0)
				       ret += " " + Esperanto[x%10-1];
			}
			return ret;
		}
};
