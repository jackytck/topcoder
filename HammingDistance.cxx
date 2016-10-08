// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
The Hamming distance between two numbers is defined as the
number of positions in their binary representations at which they
differ (leading zeros are used if necessary to make the binary
representations have the same length) - e.g., the numbers "11010"
and "01100" differ at the first, third and fourth positions, so
they have a Hamming distance of 3.


You will be given a vector <string> numbers containing
the binary representations of some numbers (all having the same
length). You are to return the minimum among the Hamming distances
of all pairs of the given numbers.



DEFINITION
Class:HammingDistance
Method:minDistance
Parameters:vector <string>
Returns:int
Method signature:int minDistance(vector <string> numbers)


CONSTRAINTS
-numbers will have between 2 and 50 elements, inclusive.
-Each element of numbers will have between 1 and 50 characters, inclusive.
-All elements of numbers will have the same number of characters.
-All elements of numbers will only contain the characters '0' and '1'.


EXAMPLES

0)
{"11010", "01100"}

Returns: 3


The example from the problem statement.


1)
{"00", "01", "10", "11"}

Returns: 1


A binary code that uses all possible codewords has minimum Hamming distance 1.


2)
{"000", "011", "101", "110"}

Returns: 2


Adding a "parity bit" to the binary numbers of example 1 increases the minimum 
Hamming distance to 2.



3)
{"01100", "01100", "10011"}

Returns: 0


Note that the input may contain identical numbers (Hamming distance 0).



4)
{"00000000000000000000000000000000000000000000000000",
"11111111111111111111111111111111111111111111111111"}

Returns: 50

5)
{"000000", "000111", "111000", "111111"}

Returns: 3

// END CUT HERE
#line 88 "HammingDistance.cxx"
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

class HammingDistance {
	public:
		int minDistance(vector <string> numbers) 
		{		
			int ret = numbers[0].sz;
			forn(i, numbers.sz-1)
			{
				For(j, i+1, numbers.sz)
				{
					int dist = 0;
					forn(k, numbers[i].sz)
						if(numbers[i][k] != numbers[j][k])
							dist++;
					ret = ret <? dist;
				}
			}
			return ret;
		}
};
