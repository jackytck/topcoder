// BEGIN CUT HERE
// PROBLEM STATEMENT
// Johnny wants to become a great programmer, so he practices to improve his programming skills all the time.  He thinks he can save a lot of time if he can learn to type faster.  It's said that the key to speed typing is keeping the rhythm, which means pressing each key after a constant interval of time.  Johnny, like many programmers, loves all kinds of statistics, so he created a program for measuring his typing progress.  The program receives a string letters and a vector <int> times, representing the keys he pressed and the time of each press in milliseconds respectively.  The ith element of times is the time at which he typed the ith character in letters.  No key is pressed more than once, and all the times are relative to the start of his practice session.

For this problem you may assume that the average time of one key press will be an integer.

Your task is to calculate which letters take Johnny more than average time to type, so he can practice those letters more.  Return a string containing all such letters in the order that they occur in the input.

DEFINITION
Class:SpeedTyper
Method:lettersToPractice
Parameters:string, vector <int>
Returns:string
Method signature:string lettersToPractice(string letters, vector <int> times)


NOTES
-The time needed to press the first key is given by times[0], and the time needed to press the key corresponding to times[i] for all i > 0 is times[i]-times[i-1].


CONSTRAINTS
-letters will contain only lowercase letters ('a'-'z').
-letters will contain between 1 and 26 characters, inclusive.
-times will contain the same number of elements as the number of characters in letters.
-No letter will occur more than once in letters.
-Each element of times will be between 1 and 100000.
-Elements of times will be in strict ascending order.
-The average time of one key press will be an integer.


EXAMPLES

0)
"dcab"
{250, 300, 400, 800}

Returns: "db"

It took Johnny 250 ms to type 'd', 50 ms to type 'c', 100 ms to type 'a' and 400 ms for 'b'. The average time to type a letter is 200 ms so he needs to practice 'd' and 'b' more.

1)
"keyboard"
{100,200,300,500,600,800,900,1200}

Returns: "bad"

It took 200 ms each to type 'b', 'a', 300 ms to type 'd', while it only took 100 ms to type each of the other letters.  The average time is 150 ms.

2)
"rewq"
{500, 1000, 1500, 4000}

Returns: "q"

'q' seems to be a difficult letter to type.

3)
"abc"
{2000, 4000, 6000}

Returns: ""

Though the speed is not too impressive, the rhythm is perfect.

// END CUT HERE
#line 67 "SpeedTyper.cxx"
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

class SpeedTyper {
	public:
		string lettersToPractice(string letters, vector <int> times) 
		{		
			string ret = "";
			forv(i, times)
			{
				int time = i == 0 ? times[i] : times[i]-times[i-1];
				if(time > times[times.sz-1]/times.sz)
					ret += letters[i];
			}
			return ret;
		}
};
