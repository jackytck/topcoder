// BEGIN CUT HERE
// PROBLEM STATEMENT
// In Russia, the Value Added Tax is 18% for almost all goods, with the exception of certain food items, which have a Value Added Tax of only 10%.
You are given a String product, the name of a product, and an int price, the price of the product before tax. You are also given a String[] food, each element of which is the name of a food product. If the given product is an element in food, it is a food item (and thus subject to 10% tax), and otherwise, it is a non-food item (and thus subject to 18% tax). Return the price of the product after tax has been added.

DEFINITION
Class:ValueAddedTax
Method:calculateFinalPrice
Parameters:string, int, vector <string>
Returns:double
Method signature:double calculateFinalPrice(string product, int price, vector <string> food)


NOTES
-The returned value must have an absolute or relative error less than 1e-9.


CONSTRAINTS
-product will contain between 1 and 50 characters, inclusive.
-Each character in product will be a lowercase letter ('a'-'z').
-price will be between 1 and 1000, inclusive.
-food will contain between 1 and 50 elements, inclusive.
-Each element of food will contain between 1 and 50 characters, inclusive.
-Each character in each element of food will be a lowercase letter ('a'-'z').
-All elements of food will be distinct.


EXAMPLES

0)
"milk"
1
{"bread", "butter", "milk"}

Returns: 1.1



1)
"car"
100
{"bread", "butter", "milk"}

Returns: 118.0



2)
"abc"
57
{"a", "b", "c"}

Returns: 67.25999999999999



// END CUT HERE
#line 59 "ValueAddedTax.cxx"
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

class ValueAddedTax {
	public:
		double calculateFinalPrice(string product, int price, vector <string> food) 
		{		
			vector <string> :: iterator it = find(food.begin(), food.end(), product);
			return it != food.end() ? price * 1.1: price * 1.18;
		}
};
