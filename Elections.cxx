// BEGIN CUT HERE
// PROBLEM STATEMENT
// There are two candidates campaigning to be president of a country.
From newspaper polls, it is clear what percentages of people plan to vote for each candidate in each state.
Candidate 1 wants to campaign in one last state, and needs to figure out which state that should be.

You are given a vector <string> likelihoods, each element of which corresponds to a state. Each element consists of the characters '1' and '2', where '1' represents some number of votes for candidate 1, and '2' represents votes for candidate 2 (in each element every character represents the same number of votes). You are to return an int representing the 0-based index of the state where the lowest percentage of people are planning on voting for candidate 1 (lowest percentage of '1' characters in that element of the input).  If there are multiple such states, return one with the lowest index in likelihoods.

DEFINITION
Class:Elections
Method:visit
Parameters:vector <string>
Returns:int
Method signature:int visit(vector <string> likelihoods)


CONSTRAINTS
-likelihoods will contain between 1 and 50 elements inclusive.
-Each element of likelihoods will contain between 1 and 50 characters inclusive, and each character will be '1' or '2'.


EXAMPLES

0)
{"1222","1122","1222"}

Returns: 0

In the first state only 25% of people prefer candidate 1, while in the second and third, 50% and 25% prefer him, respectively. 

1)
{"1222111122","2222222111","11111222221222222222"}

Returns: 1

The percentages of people, prefering candidate 1 to candidate 2 are (in order): 50%, 30%, 30%

2)
{"111","112","121","122","211","212","221","222"}

Returns: 7

3)
{"1122","1221","1212","2112","2121","2211"}

Returns: 0

4)
{"11112222111121","1211221212121","112111222","11122222222111","112121222","1212122211112"}

Returns: 3

// END CUT HERE
#line 55 "Elections.cxx"
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

class Elections {
	public:
		int visit(vector <string> likelihoods) 
		{		
			int ret = 0, minA = 1, minB = 1;
			forv(i, likelihoods)
			{
				int one = 0;
				forn(j, likelihoods[i].sz)
					if(likelihoods[i][j] == '1')
						one++;
				if(one*minB < minA*likelihoods[i].sz)
				{
					minA = one;
					minB = likelihoods[i].sz;
					ret = i;
				}
			}
			return ret;
		}
};
