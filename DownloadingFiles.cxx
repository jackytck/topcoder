// BEGIN CUT HERE
// PROBLEM STATEMENT
// You are downloading some files from the Internet, and you want to know how long it will take until they are completely downloaded.

For each download, you are given its current speed (in KB/s) and remaining time based on that speed (in seconds).  The sum of all the speeds is your total bandwidth, which remains constant and is utilized fully at all times during the downloads.  This means that when files finish downloading, the newly available bandwidth is distributed among the remaining files.  The way it's distributed does not affect the final answer.

For example, consider the following scenario where you are downloading two files.
1) Speed = 3 KB/s Remaining Time 57 seconds
2) Speed = 2 KB/s Remaining Time 22 seconds

After 22 seconds, the second file will finish downloading.  The first file still has 35 seconds remaining, but that time is based on the original speed.  The bandwidth freed up by the second file is now allocated to the first file, and its new speed is 3+2=5 KB/s.  The new remaining time is: Old_Remaining_Time * Old_Speed / New_Speed = 35*3/5 = 21 seconds.

So the actual remaining time for all the files is 21+22=43 seconds.

You will be given a vector <string> tasks, each element of which represents a single file being downloaded.  Each file is represented as two positive integers with no leading zeroes, separated by a single space.  The first integer is the current download speed in KB/s and the second integer is the remaining time in seconds based on the current speed.  Return a double representing the remaining time in seconds for all the downloads to finish.

DEFINITION
Class:DownloadingFiles
Method:actualTime
Parameters:vector <string>
Returns:double
Method signature:double actualTime(vector <string> tasks)


CONSTRAINTS
-tasks will contain between 1 and 50 elements, inclusive.
-Each element of tasks will be formatted "<speed> <time>" (quotes for clarity), where <speed> is an integer between 1 and 100, inclusive, with no leading zeroes, and <time> is an integer between 1 and 10000, inclusive, with no leading zeroes.


EXAMPLES

0)
{"3 57","2 22"}

Returns: 43.0

The example from above.

1)
{"3 1057","2 1022"}

Returns: 1043.0

This is the same as the first example but all the files will take 1000 seconds more to completely download.

2)
{"25 1000","5 5000","10 5000"}

Returns: 2500.0

In this case, when the first file finishes downloading, we will have 25 KB/s of newly available bandwidth.  We can share it between the remaining downloads however we want without affecting the final answer.  Suppose that 15 KB/s goes to the second file and 10 KB/s goes to the third file.  The new speeds and remaining times for those files will be:
20 KB/s and remaining time 2000 seconds
20 KB/s and remaining time 1000 secondsThose would take 1500 seconds to complete. So the answer is 1000 + 1500 = 2500.


3)
{"1 10","1 20","2 40"}

Returns: 27.5

For this example, suppose that all newly available bandwidth goes to the slowest task every time.  When the first download finishes (after 10 seconds), the second task doubles its speed to 2, and thus halves its remaining time from (20-10=10) to 5.  When the second download finishes, the third one doubles its speed, so its remaining time goes from (40-15=25) to 12.5.  The total time is 10+5+12.5=27.5.

4)
{"6 88","39 7057","63 2502","45 2285","28 8749","62 3636","1 5546","49 5741"}

Returns: 4414.542662116041

And here is a nice random example for you.

// END CUT HERE
#line 72 "DownloadingFiles.cxx"
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
#define clr(x) memset(x, 0, sizeof(x))
#define forn(i,n) for(__typeof(n) i = 0; i < (n); i++)
#define ford(i,n) for(int i = (n) - 1; i >= 0; i--)
#define For(i, st, en) for(__typeof(en) i = (st); i < (en); i++)

using namespace std;

class DownloadingFiles {
	public:
		double actualTime(vector <string> tasks) 
		{		
			int s, t, l = 0, a = 0;
			istringstream is;
			forn(i, tasks.sz)
			{
				is.str(tasks[i]);
				is >> s >> t;
				l += s * t;
				a += s;
				is.clear();
			}
			return double(l) / a;
		}
};
