// BEGIN CUT HERE
// PROBLEM STATEMENT
// You are at a party where no one knows anyone else's name. Each time two people shake hands, they introduce themselves to each other, and share with the other all the names they've learned at the party so far. You will be given an int n, the number of people at the party. You will also be given a vector <int> personA and a vector <int> personB, containing the zero-based indices of the people who shook hands with each other, in chronological order. Elements of personA and personB with equal indices describe the same handshake. You should return the average number of names that each person at the party has learned, not including his or her own name.

DEFINITION
Class:Party
Method:averageNames
Parameters:int, vector <int>, vector <int>
Returns:double
Method signature:double averageNames(int n, vector <int> personA, vector <int> personB)


CONSTRAINTS
-n will be between 2 and 100, inclusive.
-personA and personB will contain between 1 and 50 elements, inclusive.
-personA and personB will contain the same number of elements.
-Each element of personA and personB will be between 0 and n-1, inclusive.
-personA[k] will be unequal to personB[k] for all valid k (no one will shake hands with themselves).


EXAMPLES

0)
4
{0,1,2}
{1,2,3}

Returns: 2.25

First person 0 shakes hands with person 1, and they learn each other's names. Then person 1 and person 2 shake hands, introduce each other and talk about person 0. Finally, person 2 shakes hands with person 3, introduce themselves and discuss persons 0 and 1.

Person 0 knows one other party-goer, person 1 knows two, and persons 2 and 3 both know about all three other people. Therefore, you should return (1+2+3+3) / 4 = 2.25.

1)
5
{0,0,0,0,0,0,0}
{1,2,3,4,3,2,1}

Returns: 4.0

Halfway through the party, everyone has introduced themselves to person 0 (and vice versa). Person 0 spends the remaining half of the party going back down the list and sharing everyone's names with everybody else.  By the end of the party, each partygoer knows the names of all four other people.

2)
100
{52,19,52,19}
{19,52,19,52}

Returns: 0.02

Only two people talk to each other during the entire party; the other 98 people leave without having learned anyone else's name.

3)
25
{14, 14, 16, 4, 14, 16, 2, 16, 8, 15, 17, 17, 3, 3, 19, 17, 20, 4, 24, 8}
{16, 2, 23, 16, 11, 8, 5, 19, 15, 20, 19, 18, 14, 12, 22, 9, 0, 7, 23, 10}

Returns: 4.44

// END CUT HERE
#line 61 "Party.cxx"
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

class Party {
	public:
		double averageNames(int n, vector <int> personA, vector <int> personB) 
		{		
			int ret = -n;
			set <int> known[n];
			forn(i, n)
				known[i].insert(i);
			forv(i, personA)
			{
				known[personA[i]].insert(known[personB[i]].begin(), known[personB[i]].end());
				known[personB[i]].insert(known[personA[i]].begin(), known[personA[i]].end());
			}
			forn(i, n)
				ret += known[i].sz;
			return double(ret)/n;
		}
};
