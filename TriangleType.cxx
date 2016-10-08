// BEGIN CUT HERE
// PROBLEM STATEMENT
// In Euclidean Geometry, triangles can be categorized into one of three types
based on their angle measures.  A triangle is acute if all three angles are
less than 90 degrees.  A triangle is obtuse if one angle is greater than 90
degrees.  Lastly, a triangle with one angle at exactly 90 degrees is a right
triangle.

It could also be the case that three positive integers can not possibly form
the side-lengths of a triangle. This happens when the length of one side is
equal to or larger than the sum of the lengths of the other two sides, because
it would not be possible to connect the end points of the three sides in such a
way that a triangle was formed.

Write a method that takes as input three positive integer side-lengths
of a triangle. Return "IMPOSSIBLE" if a triangle cannot be formed.  Return
"ACUTE" if the triangle is acute, "OBTUSE" if the triangle is obtuse, and
"RIGHT" if the triangle is right.

DEFINITION
Class:TriangleType
Method:type
Parameters:int, int, int
Returns:string
Method signature:string type(int a, int b, int c)


NOTES
-For a triangle with side-lengths x, y, and z and x <= y <= z. *  The triangle is right if x*x + y*y = z*z.*  The triangle is obtuse if x*x + y*y < z*z.*  The triangle is acute if x*x + y*y > z*z.*  It is impossible to have x + y <= z.


CONSTRAINTS
-a, b, and c are between 1 and 10,000, inclusive.


EXAMPLES

0)
3
4
5

Returns: "RIGHT"

1)
3
4
4

Returns: "ACUTE"

2)
3
4
6

Returns: "OBTUSE"

3)
7
4
3

Returns: "IMPOSSIBLE"

// END CUT HERE
#line 68 "TriangleType.cxx"
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

class TriangleType {
	public:
		string type(int a, int b, int c) 
		{		
			int x = min(a, min(b, c));
			int z = max(a, max(b, c));
			int y = a+b+c-x-z;
			string ret;
			if(x+y <= z)
				ret = "IMPOSSIBLE";
			else if(x*x+y*y == z*z)
				ret = "RIGHT";
			else if(x*x+y*y < z*z)
				ret = "OBTUSE";
			else
				ret = "ACUTE";
			return ret;
		}
};
