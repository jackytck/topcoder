// BEGIN CUT HERE
// PROBLEM STATEMENT
// The distance between two strings with respect to a letter is defined as (n1 - n2)2, where n1 and n2 are the number of occurrences (both lowercase and uppercase) of that letter in the first and second strings, respectively.  The distance between two strings with respect to a third string is the sum of the distances between the two strings with respect to each letter in the third string.

You will be given three strings a, b and letterSet.  All the letters in letterSet will be distinct. Return the distance between a and b with respect to letterSet.

DEFINITION
Class:DistanceBetweenStrings
Method:getDistance
Parameters:string, string, string
Returns:int
Method signature:int getDistance(string a, string b, string letterSet)


CONSTRAINTS
-a will contain between 1 and 50 characters, inclusive.
-a will contain only letters ('a'-'z', 'A'-'Z').
-b will contain between 1 and 50 characters, inclusive.
-b will contain only letters ('a'-'z', 'A'-'Z').
-letterSet will contain between 1 and 26 characters, inclusive.
-letterSet will contain only lowercase letters ('a'-'z').
-Each character in letterSet will be distinct.


EXAMPLES

0)
"topcoder"
"contest"
"tcp"

Returns: 2

The letter 't' occurs once in the first string and twice in the second; the letter 'c' occurs once in the first string and once in the second; the letter 'p' occurs once in the first string and does not occur in the second one. The total distance is 1+0+1=2.

1)
"abcdef"
"fedcba"
"fed"

Returns: 0

The second string is a permutation of the letters in the first one thus the distance is 0.

2)
"aaaaa"
"bbbbb"
"a"

Returns: 25

The distance with respect to a single character in this case is 5*5=25.

3)
"aaAaB"
"BbaAa"
"ab"

Returns: 2

Lowercase and uppercase letters are regarded the same.

4)
"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
"bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb"
"ba"

Returns: 5000

These two strings are quite far away.

5)
"ToPcOdEr"
"tOpCoDeR"
"wxyz"

Returns: 0



// END CUT HERE
#line 83 "DistanceBetweenStrings.cxx"
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

class DistanceBetweenStrings {
	public:
		int getDistance(string a, string b, string letterSet) 
		{		
			int cnt = 0;
			forn(i, letterSet.sz)
			{
				int ac = 0, bc = 0;
				forn(j, a.sz)
					if(tolower(a[j]) == letterSet[i])
						ac++;
				forn(j, b.sz)
					if(tolower(b[j]) == letterSet[i])
						bc++;
				cnt += (ac - bc) * (ac - bc);
			}
			return cnt;
		}
};
