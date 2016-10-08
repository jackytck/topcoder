// BEGIN CUT HERE
// PROBLEM STATEMENT
// It is a common mistake to sort numbers as strings.  For example, a sorted sequence like {"1", "174", "23", "578", "71", "9"} is not correctly sorted if its elements are interpreted as numbers rather than strings.
You will be given a String[] sequence that is sorted in non-descending order using string comparison.  Return this sequence sorted in non-descending order using numerical comparison instead.


DEFINITION
Class:SequenceOfNumbers
Method:rearrange
Parameters:vector <string>
Returns:vector <string>
Method signature:vector <string> rearrange(vector <string> sequence)


CONSTRAINTS
-sequence will contain between 2 and 50 elements inclusive. 
-Each element of sequence will contain between 1 and 9 characters inclusive.
-Each element of sequence will consist of only digits ('0'-'9').
-Each element of sequence will not start with a '0' digit.
-sequence will be ordered lexicographically.


EXAMPLES

0)
{"1","174","23","578","71","9"}

Returns: {"1", "9", "23", "71", "174", "578" }

1)
{"172","172","172","23","23"}

Returns: {"23", "23", "172", "172", "172" }

2)
{"183","2","357","38","446","46","628","734","741","838"}

Returns: {"2", "38", "46", "183", "357", "446", "628", "734", "741", "838" }

// END CUT HERE
#line 42 "SequenceOfNumbers.cxx"
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

class SequenceOfNumbers {
	public:
		vector <string> rearrange(vector <string> sequence) 
		{		
			vector <string> ret;
			vector <int> number;
			forv(i, sequence)
			{
				int no = 0;
				forn(j, sequence[i].sz)
					no += (sequence[i][sequence[i].sz-1-j]-'0')*int(pow(10.0, int(j)));
				number.PB(no);
			}
			sort(number.begin(), number.end());
			forv(i, number)
			{
				stringstream ss;
				ss << number[i];
				string s;
				ss >> s;
				ret.PB(s);
			}
			return ret;
		}
};
