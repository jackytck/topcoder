// BEGIN CUT HERE
// PROBLEM STATEMENT
// Santa Claus has come with a bag full of presents this year.  A group of N kids stand in line, anxious to get their gifts.  Santa Claus takes a present from his bag and gives it to the kid who is currently first in line.  That kid then goes to the end of the line, unless he already has 4 gifts, in which case, he goes home.  This process continues as long as there are presents in the bag and kids in the line.


You are given a vector <string> gifts containing the presents in Santa's bag, in the order they are given away.  Return a vector <string> containing exactly N elements, where the k-th element is a single space separated list of presents received by the k-th kid, in the order he received them.  Kid 0 is the first kid in the initial lineup, kid 1 is the second kid, etc.


DEFINITION
Class:SantaGifts
Method:distribute
Parameters:vector <string>, int
Returns:vector <string>
Method signature:vector <string> distribute(vector <string> gifts, int N)


CONSTRAINTS
-gifts will contain between 1 and 50 elements, inclusive.
-Each element of gifts will contain between 1 and 10 lowercase letters ('a'-'z'), inclusive.
-N will be between 1 and 50, inclusive.


EXAMPLES

0)
{"ball","plane","robot","puzzle"}
3

Returns: {"ball puzzle", "plane", "robot" }

The first kid gets a ball, the second one a plane, and the third one a robot.  Then the first kid reaches the front of the line again and gets the last gift.

1)
{"ball","plane","robot","puzzle","bike"}
1

Returns: {"ball plane robot puzzle" }

There is only one kid, so he will take the first four presents.

2)
{"ball","ball","plane","plane"}
2

Returns: {"ball plane", "ball plane" }

In this case Santa Claus is fair and gives a ball and a plane to both kids.

3)
{"ball","plane","robot"}
5

Returns: {"ball", "plane", "robot", "", "" }

Unfortunately, not all the kids will get gifts.

// END CUT HERE
#line 59 "SantaGifts.cxx"
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

class SantaGifts {
	public:
		bool allDone(vector <int> no)
		{
			bool done = true;
			forv(i, no)
				if(no[i] != 4)
					done = false;
			return done;
		}

		vector <string> distribute(vector <string> gifts, int N) 
		{		
			vector <string> ret(N, "");
			vector <int> no(N, 0);
			vector <string>::iterator iter = gifts.begin();
			int i = 0;
			while(iter != gifts.end())
			{
				if(no[i] != 4)
				{
					ret[i] += *iter + " ";
					no[i]++;
					iter++;
				}
				i++;
				i %= N;
				if(allDone(no))
					break;
			}
			forv(i, ret)
				if(ret[i].sz != 0)
					ret[i].erase(ret[i].end()-1, ret[i].end());
			return ret;
		}
};
