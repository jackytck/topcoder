// BEGIN CUT HERE
// PROBLEM STATEMENT
// You are given two strings A and B that have the same length and contain only lowercase letters ('a'-'z').  The distance between two letters is defined as the absolute value of their difference.  The distance between A and B is defined as the sum of the differences between each letter in A and the letter in B at the same position. For example, the distance between "abcd" and "bcda" is 6 (1 + 1 + 1 + 3).

You must change exactly K characters in A into other lowercase letters.  Return the minimum possible distance between A and B after you perform that change.

DEFINITION
Class:ChangingString
Method:distance
Parameters:string, string, int
Returns:int
Method signature:int distance(string A, string B, int K)


CONSTRAINTS
-A and B will each contain between 1 and 50 characters, inclusive.
-K will be between 1 and the length of A, inclusive.
-A and B will contain the same number of characters.
-A and B will contain only lowercase letters ('a' - 'z').


EXAMPLES

0)
"ab"
"ba"
2

Returns: 0

The minimum distance (equal to 0) can be achieved when we change 'a' to 'b' and 'b' to 'a'.

1)
"aa"
"aa"
2

Returns: 2

We must change both letters 'a' to some other letters. Changing them to 'b' results in the smallest distance.


2)
"aaa"
"baz"
1

Returns: 1



3)
"fdfdfdfdfdsfabasd"
"jhlakfjdklsakdjfk"
8

Returns: 24



4)
"aa"
"bb"
2

Returns: 0



// END CUT HERE
#line 72 "ChangingString.cxx"
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

class ChangingString {
	public:
		int distance(string A, string B, int K) 
		{		
			int ret = 0;
			vector <int> a;
			forn(i, A.sz)
			{
				a.PB(abs(A[i] - B[i]));
			}
			sort(a.begin(), a.end());
			ford(i, a.sz)
			{
				forn(j, A.sz)
				{
					if(K != 0 && a[i] != 0 && abs(A[j] - B[j]) == a[i])
					{
						A[j] = B[j];
						K--;
					}
				}
			}
			forn(i, A.sz)
			{
				ret += abs(A[i] - B[i]);
			}
			return ret + K;
		}
};
