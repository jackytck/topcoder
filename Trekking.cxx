// BEGIN CUT HERE
// PROBLEM STATEMENT
// You are planning a small trek over at the local mountain range.  It will involve walking for several days and spending the nights in a tent.  The mountains are not very friendly (they're steep and rocky), and therefore many locations are not suitable for setting up a camp.  You will be given a string trail which represents the locations in the order in which you are visiting them.  trail[i] is '.' if it's possible to camp at the i-th location, and '^' otherwise.

You have several alternative plans to follow, given in the vector <string> plans.  plans[i][j] is lowercase 'w' if according to the i-th plan you are going to walk through location j, and uppercase 'C' if you are going to camp there.  A plan is invalid if it involves camping at a location that's not suitable for it.

Given trail and plans return the minimum number of nights that must be spent in the mountains, according to one of the valid plans.  If all plans are invalid, return -1

DEFINITION
Class:Trekking
Method:findCamps
Parameters:string, vector <string>
Returns:int
Method signature:int findCamps(string trail, vector <string> plans)


CONSTRAINTS
-trail will contain between 2 and 50 characters, inclusive.
-trail will contain only the characters '.' and '^'.
-plans will contain between 2 and 50 elements, inclusive.
-Each element of plans will contain the same number of characters as trail.
-Each element of plans will contain only the characters 'w' and 'C'.


EXAMPLES

0)
"^^....^^^..."
{"CwwCwwCwwCww",
 "wwwCwCwwwCww",
 "wwwwCwwwwCww"}

Returns: 2

The first plan is not valid because it involves camping in the first visited location, which is not suitable for camping.  The other two plans are valid, but the third involves only two camps, so it's the best one.

1)
"^^^^"
{"wwww",
 "wwwC"
}

Returns: 0



2)
"^^.^^^^"
{"wwCwwwC",
 "wwwCwww",
 "wCwwwCw"}

Returns: -1



3)
"^^^^....^.^.^."
{"wwwwCwwwwCwCwC",
 "wwwwCwwCwCwwwC",
 "wwwCwwwCwwwCww",
 "wwwwwCwwwCwwwC"}

Returns: 3



4)
".............."
{"CwCwCwCwCwCwCw",
 "CwwCwwCwwCwwCw"}

Returns: 5



// END CUT HERE
#line 79 "Trekking.cxx"
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

class Trekking {
	public:
		int findCamps(string trail, vector <string> plans) 
		{		
			int ret = -1, cnt;
			forv(i, plans)
			{
				cnt = 0;
				bool invalid = false;
				forn(j, trail.sz)
				{
					if(plans[i][j] == 'C' && trail[j] == '^')
						invalid = true;
					if(plans[i][j] == 'C')
						cnt++;
				}
				if(ret == -1 && !invalid)
					ret = cnt;
				if(!invalid)
					ret = min(ret, cnt);
			}
			return ret;
		}
};
