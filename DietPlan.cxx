// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
The doctor has given you your diet, in which each character corresponds to some food that you should eat.  You also know what you have eaten for breakfast and lunch, in which each character corresponds to a type of food that you have already eaten that day.  You have decided that you will eat all of the remaining food in your diet during dinner, and you want to return that as a string (sorted in alphabetical order).  If you have cheated in anyway (either by eating too much of one type of food, or by eating some food that is not in the dietPlan), you should return the string "CHEATER" (quotes for clarity).


DEFINITION
Class:DietPlan
Method:chooseDinner
Parameters:string, string, string
Returns:string
Method signature:string chooseDinner(string diet, string breakfast, string lunch)


CONSTRAINTS
-diet will contain between 0 and 26 characters, inclusive.
-Each character in diet will be an uppercase letter ('A'-'Z').
-There will be no duplicate characters in diet.
-breakfast will contain between 0 and 26 characters, inclusive.
-Each character in breakfast will be an uppercase letter ('A'-'Z').
-lunch will contain between 0 and 26 characters, inclusive.
-Each character in lunch will be an uppercase letter ('A'-'Z').
-There will be no duplicate characters in breakfast.
-There will be no duplicate characters in lunch.
-No character will appear in both breakfast and lunch.


EXAMPLES

0)
"ABCD"
"AB"
"C"

Returns: "D"

Here, you have eaten most of your food for the day.  So, you can only eat a single 'D' for dinner.

1)
"ABEDCS"
""
""

Returns: "ABCDES"

Here you've saved all of your food for dinner.

2)
"EDSMB"
"MSD"
"A"

Returns: "CHEATER"

You cheated at lunch time by eating an 'A'!

3)
""
""
""

Returns: ""



4)
"IWANTSODER"
"SOW"
"RAT"

Returns: "DEIN"



// END CUT HERE
#line 77 "DietPlan.cxx"
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
#define For(i, st, en) for(__typeof(en) i = (st); i < (en); i++)

using namespace std;

class DietPlan {
	public:
		string chooseDinner(string diet, string breakfast, string lunch) 
		{		
			vector<char> d, e;
			forn(i, diet.sz)
			{
				d.PB(diet[i]);
			}
			forn(i, breakfast.sz)
			{
				e.PB(breakfast[i]);
			}
			forn(i, lunch.sz)
			{
				e.PB(lunch[i]);
			}
			sort(d.begin(), d.end());
			sort(e.begin(), e.end());
			vector<char> l(max(d.sz, e.sz));
			vector<char>::iterator it = set_difference( e.begin(), e.end(), d.begin(), d.end(), l.begin());
			if(it != l.begin())
				return "CHEATER";
			else
				it = set_difference( d.begin(), d.end(), e.begin(), e.end(), l.begin());
			string re = "";
			for(vector<char>::iterator i = l.begin(); i != it; ++i)
			{
				re += *i;
			}
			return re;
		}
};
