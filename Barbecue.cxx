// BEGIN CUT HERE
// PROBLEM STATEMENT
// The Smiths are having a barbecue on a sunny Saturday morning. There was exactly one piece of meat for each family member. But before eating, they decided to play a game of football. As the barbecue was left unattended, the family dog ate one of the pieces of meat. In order to solve this problem, the big brother proposed that one of them should go and play with the dog while the others take their share of meat. Everybody was hungry, so they decided to vote for the person to be excluded.  

There are n members in the Smith family, which are denoted with indices between 0 and n-1. Each of them can vote for any number of persons (from 0 to n-1). In the end, the one who receives the most votes is going to lose the meat. In case of a tie, the one who voted the most loses his meat. If the tie still persists, the person with the smallest index is going to lose. 

You are given an int n denoting the number of Smiths attending the barbecue. You are also given a int[] voter and a int[] excluded with the following signification: the member with the index voter[i] has voted for the exclusion of the member with the index excluded[i]. Return the index of the person that is going to be excluded, according to the criteria defined above.



DEFINITION
Class:Barbecue
Method:eliminate
Parameters:int, vector <int>, vector <int>
Returns:int
Method signature:int eliminate(int n, vector <int> voter, vector <int> excluded)


CONSTRAINTS
-n is between 2 and 20, inclusive.
-voter and excluded have between 0 and 50 elements, inclusive.
-voter and excluded have the same number of elements.
-Each element of voter and excluded is between 0 and n-1, inclusive.
-A person cannot vote for the same person more than once.
-A person cannot vote for himself.


EXAMPLES

0)
3
{0,1,2,2}
{2,2,0,1}

Returns: 2

In this case, we have three members. The member with index 2 was voted for by the member with index 0 and the member with index 1 and thus, he is going to be excluded.

1)
3
{0,2,2}
{2,0,1}

Returns: 2

This time, all the three members are tied with one vote against them. But since the member with index 2 has voted two times, the answer is 2.

2)
2
{0,1}
{1,0}

Returns: 0

There are only two members and each of them has one exclusion vote. They are also tied by the number of votes given, so the tie is broken by the order of their indices. Thus, the correct answer is 0.

3)
20
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,3,4,5,
6,7,8,9,10,11,12,13,14,15,16,17,18,19,19,19,19}
{0,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,
0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,1,2,3}

Returns: 2

4)
5
{4,3,1,0}
{2,2,3,3}

Returns: 3

5)
10
{4,5,6,7,8,9,0,1,2}
{5,6,7,8,9,0,1,2,3}

Returns: 0

6)
7
{1,2,3,4,5,6,0,2,3,4,5,6,0,1,3,4,5,6,0,1,2,
 4,5,6,0,1,2,3,5,6,0,1,2,3,4,6,0,1,2,3,4,5}
{0,0,0,0,0,0,1,1,1,1,1,1,2,2,2,2,2,2,3,3,3,
 3,3,3,4,4,4,4,4,4,5,5,5,5,5,5,6,6,6,6,6,6}

Returns: 0

7)
5
{}
{}

Returns: 0

// END CUT HERE
#line 98 "Barbecue.cxx"
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

class Barbecue {
	public:
		int eliminate(int n, vector <int> voter, vector <int> excluded) 
		{		
			int ret = 0;
			vector <int> voted(n, 0), bevoted(n, 0), exclude;
			forv(i, voter)
			{
				voted[voter[i]]++;
				bevoted[excluded[i]]++;
			}
			int maxvote = *max_element(bevoted.begin(), bevoted.end());
			forv(i, bevoted)
				if(bevoted[i] == maxvote)
					exclude.PB(i);
			maxvote = -1;
			forv(i, exclude)
				if(voted[exclude[i]] > maxvote)
				{
					maxvote = voted[exclude[i]];
					ret = exclude[i];
				}
			return ret;
		}
};
