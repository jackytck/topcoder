// BEGIN CUT HERE
// PROBLEM STATEMENT
// We have a pile of crates at our warehouse that we want to load onto trucks.
Our plan is to divide the pile in half forming two smaller piles, then continuing
dividing each of the small piles in half until we get piles that will fit on a 
truck. (Of course, when we divide an odd number of crates in "half", one of the 
resulting piles will have one more crate than the other.) Our problem is to 
determine how many trucks we will need to ship the crates.

Create a class Truckloads that contains a method numTrucks that is given numCrates 
(the number of crates at the warehouse) and loadSize (the maximum number of
crates that will fit in a truck) and that returns the number of trucks required.



DEFINITION
Class:Truckloads
Method:numTrucks
Parameters:int, int
Returns:int
Method signature:int numTrucks(int numCrates, int loadSize)


CONSTRAINTS
-numCrates will be between 2 and 10,000, inclusive.
-loadSize loadSize will be be between 1 and (numCrates - 1), inclusive.


EXAMPLES

0)
14
3

Returns: 6



   After the first division we have two piles each with 7 crates. Each of these
   piles must be divided giving us 2 piles of 3 and 2 piles of 4. The piles 
   with 4 crates must be further divided giving us 2 piles of 3 and 4 piles of 2.
   Each of these piles fits into a truck, so we need 6 trucks.





1)
15
1

Returns: 15



   We will eventually end up with 15 piles, each with just 1 crate.

2)
1024
5

Returns: 256



   1024 divides in half very nicely. We eventually end up with 256 piles, each
   containing 4 crates.

// END CUT HERE
#line 71 "Truckloads.cxx"
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

class Truckloads {
	public:
		int numTrucks(int numCrates, int loadSize) 
		{		
			if(numCrates <= loadSize)
				return 1;
			else
				return numTrucks(numCrates/2, loadSize) + numTrucks(numCrates-numCrates/2, loadSize);
		}
};
