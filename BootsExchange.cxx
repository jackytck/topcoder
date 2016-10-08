// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
A boot shop has received a shipment from the factory consisting of N left boots and N right boots. Each boot has some integer size, and a left and right boot will form a proper pair if they have equal sizes. Each boot can only belong to a single pair. The employees of the boot store want to create N proper pairs of boots.  Fortunately, the factory has offered to exchange any number of boots in the shipment with new boots of different sizes. 


You are given a vector <int> left and a vector <int> right containing the sizes of the left boots and right boots, respectively.
Return the least number of boots that must be exchanged.


DEFINITION
Class:BootsExchange
Method:leastAmount
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int leastAmount(vector <int> left, vector <int> right)


CONSTRAINTS
-Each element in left will be between 1 and 1000, inclusive.
-Each element in right will be between 1 and 1000, inclusive.
-left and right will have the same number of elements.
-left will contain between 1 and 50 elements, inclusive.


EXAMPLES

0)
{1, 3, 1}
{2, 1, 3}

Returns: 1

They can exchange a size 1 left shoe for a size 2 left shoe, or they can exchange the size 2 right shoe for a size 1 right shoe.

1)
{1, 3}
{2, 2}

Returns: 2

They can exchange both left shoes for size 2 left shoes, or they can exchange the right shoes for a size 1 right shoe and a size 3 right shoe, or they can mix these two possibilities.

2)
{1, 2, 3, 4, 5, 6, 7}
{2, 4, 6, 1, 3, 7, 5}

Returns: 0

Nothing to exchange.

// END CUT HERE
#line 54 "BootsExchange.cxx"
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

class BootsExchange {
	public:
		int leastAmount(vector <int> left, vector <int> right) 
		{		
			int ret = left.sz;
			forv(i, left)
				forv(j, right)
					if(left[i] == right[j])
					{
						right[j] = 0;
						ret--;
						break;
					}
			return ret;	
		}
};
