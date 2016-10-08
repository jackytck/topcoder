// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
You are packing a stack of books into some boxes,
packing as many books as you can into each box without exceeding a given weight limit.
Once you have packed as many books into a box as you can, you close and seal that box, and then begin filling the next one.
You take the books off the stack in order, packing each one before picking up the next.



The weights of the books will be given as a vector <int> weights,
where the first element is the weight of the book on top of the stack
and the last element is the weight of the book on the bottom of the stack.
The maximum weight that can fit into each box will be given as an int maxWeight.
Return the minimum number of boxes you will need.



DEFINITION
Class:BoxesOfBooks
Method:boxes
Parameters:vector <int>, int
Returns:int
Method signature:int boxes(vector <int> weights, int maxWeight)


CONSTRAINTS
-weights will contain between 0 and 50 elements, inclusive.
-maxWeight will be between 1 and 1000, inclusive.
-Each element of weights will be between 1 and maxWeight, inclusive.


EXAMPLES

0)
{ 5, 5, 5, 5, 5, 5 }
10

Returns: 3

You have 6 books that weigh 5 kilograms each.  Each box can hold 10 kilograms (2 books).  Therefore, you need 3 boxes.

1)
{ 51, 51, 51, 51, 51 }
100

Returns: 5

Each box can hold 100 kg, but since the books weigh 51 kg each, you can only put one in each box.

2)
{ 1, 1, 1, 7, 7, 7 }
8

Returns: 4

You would like to put one 1 kg book and one 7 kg book in each of 3 boxes.  But, since you must pack the books in order, you end up putting the three 1 kg books in one box and each of the three 7 kg books in its own box, for a total of 4 boxes.

3)
{ 12, 1, 11, 2, 10, 3, 4, 5, 6, 6, 1 }
12

Returns: 6



4)
{ }
7

Returns: 0



5)
{ 20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
  20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
  20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
  20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
  20, 20, 20, 20, 20, 20, 20, 20, 20, 20 }
1000

Returns: 1



// END CUT HERE
#line 89 "BoxesOfBooks.cxx"
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
#define For(i, st, en) for(__typeof(en) i = (st); i <= (en); i++)

using namespace std;

class BoxesOfBooks {
	public:
		int boxes(vector <int> weights, int maxWeight) 
		{
			if(weights.sz == 0) return 0;
			int nb = 1, bc = maxWeight;
			forn(i, weights.sz)
			{
				if(bc >= weights[i])
				{
					bc -= weights[i];
				}
				else
				{
					nb++;
					bc = maxWeight;
					bc -= weights[i];
				}
			}
			return nb;
		}
};
