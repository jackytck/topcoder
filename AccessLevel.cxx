// BEGIN CUT HERE
// PROBLEM STATEMENT
// In many computer systems and networks, different users are granted different levels of access to different resources.  In this case, you are given a vector <int> rights, indicating the privilege level of each user to use some system resource.  You are also given a int minPermission, which is the minimum permission a user must have to use this resource.

You are to return a string indicating which users can and cannot access this resource.  Each character in the return value corresponds to the element of users with the same index.  'A' indicates the user is allowed access, while 'D' indicates the user is denied access.


DEFINITION
Class:AccessLevel
Method:canAccess
Parameters:vector <int>, int
Returns:string
Method signature:string canAccess(vector <int> rights, int minPermission)


NOTES
-If users is empty, then a zero-length string ("") should be returned.


CONSTRAINTS
-users will contain between 0 and 50 elements, inclusive.
-Each element of users will be between 0 and 100, inclusive.
-minPermission will be between 0 and 100, inclusive.


EXAMPLES

0)
{0,1,2,3,4,5}
2

Returns: "DDAAAA"

Here, the first two users don't have sufficient privileges, but the remainder do.

1)
{5,3,2,10,0}
20

Returns: "DDDDD"

Unfortunately, nobody has sufficient access.

2)
{}
20

Returns: ""

It makes no difference what permission is required, since there are no users to check.

3)
{34,78,9,52,11,1}
49

Returns: "DADADD"

// END CUT HERE
#line 60 "AccessLevel.cxx"
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

class AccessLevel {
	public:
		string canAccess(vector <int> rights, int minPermission) 
		{		
			string ret = "";
			forv(i, rights)
				ret += rights[i] >= minPermission ? 'A' : 'D';
			return ret;
		}
};
