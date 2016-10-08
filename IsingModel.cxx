// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
The Ising model is a simple widespread model in statistical
physics for simulating magnetic properties of matter.
In this model, we consider a rectangular grid, and we associate
each grid point with a value '+' or '-' (which physically
represents the spin of the element positioned at that grid point).


When we have such a spin configuration, the total energy of this
configuration is computed by adding the values contributed by
each pair of neighboring cells (only horizontal and vertical
direct neighbors are considered). If the pair consists
of two cells with the same spin (both '+' or both '-'), this pair
contributes a value of -1 to the total energy. Otherwise (one cell
is '+' and its neighbor is '-'), the pair contributes a value of +1
to the total energy.


See example 0 for a detailed computation of the energy value.



You are given a vector <string> spins representing the
spin configuration. You are to return the total energy of this
configuration.



DEFINITION
Class:IsingModel
Method:energy
Parameters:vector <string>
Returns:int
Method signature:int energy(vector <string> spins)


CONSTRAINTS
-spins will have between 1 and 50 elements, inclusive.
-Each element of spins will have between 1 and 50 characters, inclusive.
-All elements of spins will have the same number of characters.
-Each character of each element of spins will be either '+' or '-'.


EXAMPLES

0)
{"-++",
 "+-+"}

Returns: 3

There are a total of 7 neighboring pairs here: 4 horizontal (-+), (++),
(+-) and (-+) and 3 vertical (-+), (+-) and (++). Pairs of type (+-) and (-+) contribute a value of +1 to the total energy, and pairs of type (--) and (++) contribute a value of -1.  The total energy of this configuration is thus: E = 1 - 1 + 1 + 1 + 1 + 1 - 1 = 3.

1)
{"+"}

Returns: 0

With just one element, there is no neighboring pair, so the total energy is 0.

2)
{"++-+",
 "-++-",
 "+-+-",
 "++++"}

Returns: 4

3)
{"----",
 "---+",
 "-+++",
 "++++"}

Returns: -12

// END CUT HERE
#line 82 "IsingModel.cxx"
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

class IsingModel {
	public:
		int energy(vector <string> spins) 
		{		
			int ret = 0;
			forv(i, spins)
			{
				forn(j, spins[i].sz-1)
				{
					if(spins[i][j] == spins[i][j+1])
						ret--;
					else
						ret++;
				}
			}
			forn(i, spins.sz-1)
			{
				forn(j, spins[0].sz)
				{
					if(spins[i][j] == spins[i+1][j])
						ret--;
					else
						ret++;
				}
			}
			return ret;
		}
};
