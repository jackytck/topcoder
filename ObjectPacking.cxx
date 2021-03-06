// BEGIN CUT HERE
// PROBLEM STATEMENT
// Given a rectangular object and several boxes (in this problem, we ignore the height of the box, so a box only has two dimensions) of different sizes, you want to find the box with the smallest area which is large enough to contain the object. When putting the object in the box, it's sides must be parallel with the sides of the box. Thus, you may only rotate the object 0, 90, 180 or 270 degrees (although for obvious reasons you only need to consider rotating with 0 and 90 degrees).

Create a class ObjectPacking which contains the method smallBox which takes an int objWidth, an int objLength (the width and length of the object), a vector <int> boxWidth, a vector <int> boxLength (the width and length of the boxes) and returns an int, the area of the smallest box that can fit the object. Element i in boxWidth and boxLength correspond to box i. If no box is big enough to contain the object, return -1.


DEFINITION
Class:ObjectPacking
Method:smallBox
Parameters:int, int, vector <int>, vector <int>
Returns:int
Method signature:int smallBox(int objWidth, int objLength, vector <int> boxWidth, vector <int> boxLength)


NOTES
-There doesn't have to be any gap between the sides of an object and the sides of the box. Thus, an object with width 5 and length 7 will fit in a box with width 7 and length 5.
-Return -1 if there is no box big enough to contain the object (see example 1).


CONSTRAINTS
-objWidth will be between 1 and 1000, inclusive.
-objLength will be between 1 and 1000, inclusive.
-boxWidth will contain between 1 and 50 elements, inclusive.
-boxLength will contain between 1 and 50 elements, inclusive.
-boxWidth will contain the same number of elements as boxLength.
-Each element in boxWidth will be between 1 and 1000, inclusive.
-Each element in boxLength will be between 1 and 1000, inclusive.


EXAMPLES

0)
7
3
{3}
{7}

Returns: 21

By rotating the object 90 degrees we can precisely fit it into the only box in the list, so the method should return 21 (7*3).


1)
5
8
{6,9,3}
{7,4,5}

Returns: -1

The object can't fit in any of the boxes, no matter if we rotate it or not. The method should thus return -1.


2)
17
5
{19,10,12,40}
{12,20,15,5}

Returns: 200

The object will fit in box 0, 1 and 3. The area of box 1 and 3 are 200 while the area of box 0 is 228, so the method should return 200.


3)
20
44
{36,42,18,37,33,5,30,10,29,9,11,16,48,50,34,44,33,12,31,41}
{42,45,46,24,23,21,21,8,26,25,48,12,10,45,18,6,12,22,42,45}

Returns: 1845

4)
1
10
{9,1,10}
{10,6,4}

Returns: 40

5)
5
4
{2,3,3,3,3}
{2,7,7,4,2}

Returns: -1

6)
3
3
{2,3,3,3,2}
{3,1,3,3,2}

Returns: 9

// END CUT HERE
#line 100 "ObjectPacking.cxx"
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

class ObjectPacking {
	public:
		int smallBox(int objWidth, int objLength, vector <int> boxWidth, vector <int> boxLength) 
		{		
			int ret = 1000001;
			forv(i, boxWidth)
				if((boxWidth[i] >= objWidth && boxLength[i] >= objLength) || (boxWidth[i] >= objLength && boxLength[i] >= objWidth))
					ret <?= boxWidth[i]*boxLength[i];
			return ret == 1000001 ? -1 : ret;
		}
};
