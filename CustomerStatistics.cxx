// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
You will be given a vector <string> customerNames, containing a list of customer names extracted from a database. Your task is to report the customers that occur more than once in this list, and the number of occurrences for each of the repeated customers. 



Your method should return the report as a vector <string>. Each element in this vector <string> should be of the form 
"NAME OCCURS", where NAME is the name of one customer and OCCURS is the number of times his
name occurs in customerNames.
Sort the result in alphabetical order by customer name.


DEFINITION
Class:CustomerStatistics
Method:reportDuplicates
Parameters:vector <string>
Returns:vector <string>
Method signature:vector <string> reportDuplicates(vector <string> customerNames)


CONSTRAINTS
-customerNames contains between 1 and 50 elements, inclusive.
-Each element of customerNames contains between 1 and 50 characters, inclusive.
-Each element of customerNames contains uppercase letters ('A'-'Z') only.


EXAMPLES

0)
{"JOHN", "BOB", "JOHN", "BILL", "STANLEY", "JOHN"}

Returns: {"JOHN 3" }

The only repeated name is JOHN, and it occurs three times.

1)
{"YETTI", "YETTI", "YETTI", "BIGFOOT", "BIGFOOT"}

Returns: {"BIGFOOT 2", "YETTI 3" }

Note the sorting order.

2)
{"ANDREW", "BILL", "CINDY", "DOH", "ERGH", "FOO", "GOO", "HMPH"}

Returns: { }

No repeated names this time.

3)
{"THEONLYCUSTOMER"}

Returns: { }

Again, no repeats.

4)
{"A", "B", "A", "C", "A", "B", "A", "D", "D", "D"}

Returns: {"A 4", "B 2", "D 3" }

// END CUT HERE
#line 65 "CustomerStatistics.cxx"
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

class CustomerStatistics {
	public:
		vector <string> reportDuplicates(vector <string> customerNames) 
		{		
			vector <string> ret;
			sort(customerNames.begin(), customerNames.end());
			string temp = customerNames[0];
			int cnt = 1;
			for(int i=1; i<customerNames.sz; i++)
			{
				if(customerNames[i] == temp)
					cnt++;
				else
				{
					if(cnt > 1)
					{
						ostringstream s;
						s << cnt;
						ret.PB(temp + " " + s.str());
						cnt = 1;
					}
					temp = customerNames[i];
				}
			}
			if(cnt > 1)
			{
				ostringstream s;
				s << cnt;
				ret.PB(temp + " " + s.str());
			}
			return ret;
		}
};
