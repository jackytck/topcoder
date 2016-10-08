// BEGIN CUT HERE
// PROBLEM STATEMENT
// A pharmacist is making a mixture of several ingredients. She needs to know the density of the resulting mixture. Density is defined as the mass of the mixture divided by its volume.

You're given a vector <string> ingredients, each element of which describes a single ingredient and is formatted "<Volume> ml of <Name>, weighing <Mass> g" (quotes for clarity). <Volume> and <Mass> are integers representing the volume in milliliters and mass in grams, respectively.  <Name> is the name of the ingredient.

Return the density of the resulting mixture in grams per milliliters.

DEFINITION
Class:MixtureDensity
Method:getDensity
Parameters:vector <string>
Returns:double
Method signature:double getDensity(vector <string> ingredients)


NOTES
-The returned value must be accurate to within a relative or absolute value of 1E-9.


CONSTRAINTS
-ingredients will contain between 1 and 50 elements, inclusive.
-Each element of ingredients will contain between 23 and 50 characters, inclusive.
-Each element of ingredients will be formatted as described in the statement.
-Each <Volume> in ingredients will be an integer between 1 and 1000, inclusive, with no leading zeroes.
-Each <Mass> in ingredients will be an integer between 1 and 1000, inclusive, with no leading zeroes.
-Each <Name> in ingredients will contain only lowercase letters ('a'-'z') and spaces (' ').
-Each <Name> in ingredients will begin and end with a lowercase letter.


EXAMPLES

0)
{"200 ml of oil, weighing 180 g"}

Returns: 0.9

The density is mass/volume = 180g/200ml = 0.9g/ml, the answer is 0.9.

1)
{"100 ml of dichloromethane, weighing 130 g", "100 ml of sea water, weighing 103 g"}

Returns: 1.165

The volume of the resulting mixture is 200 ml and the mass is 233 g. Therefore, the density is 233g/200ml = 1.165g/ml.

2)
{"1000 ml of water, weighing 1000 g", "500 ml of orange juice concentrate, weighing 566 g"}

Returns: 1.044



3)
{"1000 ml of something   l i g h t, weighing 1 g"}

Returns: 0.0010



// END CUT HERE
#line 63 "MixtureDensity.cxx"
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

class MixtureDensity {
	public:
		double getDensity(vector <string> ingredients) 
		{		
			int m = 0, v = 0;
			forv(i, ingredients)
			{
				istringstream is(ingredients[i]);
				int t;
				is >> t;
				v += t;
				istringstream is2(ingredients[i].substr(ingredients[i].find(", weighing") + 11));
				is2 >> t;
				m += t;
			}
			return double(m) / v;
		}
};
