// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
  You are given two line segments on the plane. Each segment is parallel to either the X axis or the Y axis. Your task is to figure out how the segments intersect and return one of the following strings:

  "NO", if the segments do not intersect
  "POINT", if the segments' intersection forms a point
  "SEGMENT", if the segments' intersection forms a line segment



  The segments will be given as two int[]s s1 and s2. Each of them will contain four integers x1, y1, x2, y2 (in that order) where (x1, y1), (x2, y2) are segment endpoints.


DEFINITION
Class:Segments
Method:intersection
Parameters:vector <int>, vector <int>
Returns:string
Method signature:string intersection(vector <int> s1, vector <int> s2)


CONSTRAINTS
-       Each of s1 and s2 will contain exactly four elements
-       All integers in s1 and s2 will be between -1000 and 1000, inclusive
-       Each segment will be parallel to either the X axis or the Y axis 


EXAMPLES

0)
{0, 0, 0, 1}	
{1, 0, 1, 1}

Returns: "NO"

The segments are parallel and there is no intersection.

1)
{0, 0, 0, 1}
{0, 1, 0, 2}

Returns: "POINT"

The segments are located on the same line and have only one common point (0,1).

2)
{0, -1, 0, 1}
{-1, 0, 1, 0}

Returns: "POINT"

The segments intersect at point (0,0).

3)
{0, 0, 2, 0}
{1, 0, 10, 0}

Returns: "SEGMENT"

The segments have a common line segment from (1,0) to (2,0).

4)
{5, 5, 5, 5}
{6, 6, 6, 6}

Returns: "NO"

These are two different points.

5)
{10, 0, -10, 0}
{5, 0, -5, 0}

Returns: "SEGMENT"

The segments have a common line segment from (-5,0) to (5,0).

// END CUT HERE
#line 81 "Segments.cxx"
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

class Segments {
	public:
		string intersection(vector <int> s1, vector <int> s2) 
		{		
			bool s1v = true, s2v = true, point = false, segment = false;
			if(s1[1] == s1[3])
				s1v = false;
			if(s2[1] == s2[3])
				s2v = false;
			if(s1v)
			{
				for(int i=min(s1[1], s1[3]); i<=max(s1[1], s1[3]); i++)
				{
					if(s2v)
					{
						if(s1[0] == s2[0] && i >= min(s2[1], s2[3]) && i <= max(s2[1], s2[3]))
						{
							if(!point)
								point = true;
							else
								segment = true;
						}
					}
					else
					{
						if(i == s2[1] && s1[0] >= min(s2[0], s2[2]) && s1[0] <= max(s2[0], s2[2]))
						{
							if(!point)
								point = true;
							else
								segment = true;
						}
					}
				}
			}
			else
			{
				for(int i=min(s1[0], s1[2]); i<=max(s1[0], s1[2]); i++)
				{
					if(s2v)
					{
						if(i == s2[0] && s1[1] >= min(s2[1], s2[3]) && s1[1] <= max(s2[1], s2[3]))
						{
							if(!point)
								point = true;
							else
								segment = true;
						}
					}
					else
					{
						if(s1[1] == s2[1] && i >= min(s2[0], s2[2]) && i <= max(s2[0], s2[2]))
						{
							if(!point)
								point = true;
							else
								segment = true;
						}
					}
				}
			}
			return segment ? "SEGMENT" : (point ? "POINT" : "NO");
		}
};
