// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
In many computer systems, multiple processes can read from the same resource during the same clock cycle, but only a single process can write to the resource during a clock cycle.  Reads and writes cannot be mixed during the same clock cycle.  Given a history of the reads and writes that occurred during a particular computation as a string trace, and an int procs representing the number of processes used by the computation, calculate the minimum duration of the computation in clock cycles.  The trace represents each read as an 'R' and each write as a 'W'.



For example, if trace is "RWWRRR" and procs is 3, then the minimum number of clock cycles is 4: one for the first read, one each for the two writes, and one for the last group of reads.


DEFINITION
Class:MultiRead
Method:minCycles
Parameters:string, int
Returns:int
Method signature:int minCycles(string trace, int procs)


CONSTRAINTS
-trace will contain between 1 and 50 characters, inclusive.
-Each character in trace will be 'R' or 'W'.
-procs will be between 1 and 10, inclusive.


EXAMPLES

0)
"RWWRRR"
3

Returns: 4

The example above.

1)
"RWWRRRR"
3

Returns: 5

Now the final group of 'R's takes two cycles.

2)
"WWWWW"
5

Returns: 5

3)
"RRRRRRRRRR"
4

Returns: 3

4)
"RWRRWWRWRWRRRWWRRRRWRRWRRWRRRRRRRRRWRWRWRRRRWRRRRR"
4

Returns: 30

// END CUT HERE
#line 63 "MultiRead.cxx"
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

class MultiRead {
	public:
		int minCycles(string trace, int procs) 
		{		
			int buf = procs, ret = 0;
			forn(i, trace.sz)
			{
				if(trace[i] == 'W')
				{
					buf = procs;
					ret++;
				}
				else
				{
					buf++;
					if(buf > procs)
					{
						buf = 1;
						ret++;
					}
				}
			}
			return ret;
		}
};
