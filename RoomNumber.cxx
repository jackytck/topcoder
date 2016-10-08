// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
You are going to stick the number of your room on the door. The shop near your house suggests wonderful sets of plastic digits. Each set contains exactly ten digits - one of each digit between 0 and 9, inclusive. Return the number of sets required to write your room number.  Note that 6 can be used as 9 and vice versa.



DEFINITION
Class:RoomNumber
Method:numberOfSets
Parameters:int
Returns:int
Method signature:int numberOfSets(int roomNumber)


CONSTRAINTS
-roomNumber will be between 1 and 1,000,000, inclusive.


EXAMPLES

0)
122

Returns: 2

Two sets are required because each set contains only one '2' digit.

1)
9999

Returns: 2

Each set contains one '6' digit and one '9' digit. '6' could be used as '9' and therefore two sets are enough. 

2)
12635

Returns: 1

3)
888888

Returns: 6

// END CUT HERE
#line 48 "RoomNumber.cxx"
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

class RoomNumber {
	public:
		int numberOfSets(int roomNumber) 
		{		
			ostringstream ss;
			ss << roomNumber;
			string rn = ss.str();;
			int cnt69 = 0, cnt = 0;
			forn(i, rn.sz)
			{
				int cnto = 0;
				forn(j, rn.sz)
					if(rn[j] != '6' && rn[j] != '9' && rn[j] == rn[i])
						cnto++;
				cnt = max(cnt, cnto);
				if(rn[i] == '6' || rn[i] == '9')
					cnt69++;
			}
			return max(cnt, cnt69/2 + cnt69%2);
		}
};
