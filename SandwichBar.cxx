// BEGIN CUT HERE
// PROBLEM STATEMENT
// It's time to get something to eat and I've come across a sandwich bar. Like most people, I prefer certain types of sandwiches. In fact, I keep a list of the types of sandwiches I like.

The sandwich bar has certain ingredients available. I will list the types of sandwiches I like in order of preference and buy the first sandwich the bar can make for me. In order for the bar to make a sandwich for me, it must include all of the ingredients I desire.

Given a vector <string> available, a list of ingredients the sandwich bar can use, and a vector <string> orders, the types of sandwiches I like, in order of preference (most preferred first), return the 0-based index of the sandwich I will buy. Each element of orders represents one type of sandwich I like as a space-separated list of ingredients in the sandwich. If the bar can make no sandwiches I like, return -1.

DEFINITION
Class:SandwichBar
Method:whichOrder
Parameters:vector <string>, vector <string>
Returns:int
Method signature:int whichOrder(vector <string> available, vector <string> orders)


CONSTRAINTS
-available will contain between 1 and 50 elements, inclusive.
-Each element of available will contain between 1 and 50 lowercase letters ('a' - 'z'), inclusive.
-orders will contain between 1 and 50 elements, inclusive.
-Each element of orders will contain between 1 and 50 lowercase letters ('a' - 'z') and spaces, inclusive.
-Each element of orders will represent a list of desired ingredients separated by single spaces, with no leading or trailing spaces.


EXAMPLES

0)
{ "ham", "cheese", "mustard" }
{ "ham cheese" }

Returns: 0

I only like plain ham and cheese sandwiches, and since both ham and cheese are available, I'll take that.

1)
{ "cheese", "mustard", "lettuce" }
{ "cheese ham", "cheese mustard lettuce", "ketchup", "beer" }

Returns: 1

They've run out of ham, but I'll consider other options now.

2)
{ "cheese", "cheese", "cheese", "tomato" }
{ "ham ham ham", "water", "pork", "bread", "cheese tomato cheese", "beef" }

Returns: 4

Ignore any duplicate elements in the lists.

3)
{ "foo", "bar", "baz", "gazonk", "quux", "bat", "xyzzy",
  "shme", "hukarz", "grault", "waldo", "bleh" }
{ "kalatehas", "spam eggs", "needle haystack", "bleh blarg", "plugh", 
  "the best sandwich in the universe" }

Returns: -1

// END CUT HERE
#line 61 "SandwichBar.cxx"
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

class SandwichBar {
	public:
		int whichOrder(vector <string> available, vector <string> orders) 
		{		
			int ret = -1;
			forv(i, orders)
			{
				stringstream ss(orders[i]);
				string ingredient;
				bool ok = true;
				while(ss >> ingredient)
				{
					bool present = false;
					forv(j, available)
						if(available[j] == ingredient)
						{
							present = true;
							break;
						}
					ok = ok && present;
				}
				if(ok)
				{
					ret = i;
					break;
				}
			}
			return ret;
		}
};
