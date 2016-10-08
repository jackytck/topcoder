// BEGIN CUT HERE
// PROBLEM STATEMENT
// We have a collection of strings, and we want to right justify them.
Given a vector <string> text, your task is to return
a vector <string> containing the same strings, right justified, in the same order as they
appear in text.

The returned strings should be padded on the left with space characters 
so that they are all the same length as the longest string in textIn.




DEFINITION
Class:JustifyText
Method:format
Parameters:vector <string>
Returns:vector <string>
Method signature:vector <string> format(vector <string> text)


CONSTRAINTS
-text will contain between 1 and 50 elements inclusive
-each element of text will contain only uppercase letters 'A'-'Z'
-each element of text will contain between 1 and 50 characters inclusive


EXAMPLES

0)
{"BOB","TOMMY","JIM"}

Returns: {"  BOB", "TOMMY", "  JIM" }

The longest string is "TOMMY" which has 5 characters. So the returned strings all contain exactly 5 characters. 

1)
{"JOHN","JAKE","ALAN","BLUE"}

Returns: {"JOHN", "JAKE", "ALAN", "BLUE" }

No padding is necessary since they all contain the same number of characters.

2)
{"LONGEST","A","LONGER","SHORT"}

Returns: {"LONGEST", "      A", " LONGER", "  SHORT" }

// END CUT HERE
#line 51 "JustifyText.cxx"
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

class JustifyText {
	public:
		vector <string> format(vector <string> text) 
		{		
			int maxln = 0;
			forv(i, text)
				maxln >?= text[i].sz;
			forv(i, text)
			{
				if(text[i].sz<maxln)
				{
					string right;
					forn(j, maxln-text[i].sz)
						right += ' ';
					right += text[i];
					text[i] = right;
				}
			}
			return text;
		}
};
