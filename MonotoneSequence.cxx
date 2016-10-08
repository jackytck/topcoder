// BEGIN CUT HERE
// PROBLEM STATEMENT
// A strictly increasing sequence is a sequence of numbers where each number is strictly greater than the previous one. A strictly decreasing sequence is a sequence where each number is strictly less than the previous one. A strictly monotone sequence is a sequence that is either strictly increasing or strictly decreasing. For example, 1, 5, 6, 10 and 9, 8, 7, 1, are strictly monotone sequences, while 1, 5, 2, 6 and 1, 2, 2, 3 are not.

Given a sequence seq, determine the length of the longest contiguous subsequence that is strictly monotone (see examples for clarifications).

DEFINITION
Class:MonotoneSequence
Method:longestMonotoneSequence
Parameters:vector <int>
Returns:int
Method signature:int longestMonotoneSequence(vector <int> seq)


CONSTRAINTS
-seq will contain between 1 and 50 elements, inclusive.
-Each element of seq will be between 1 and 100, inclusive.


EXAMPLES

0)
{1, 7, 7, 8, 3, 6, 7, 2}

Returns: 3

The longest contiguous monotone subsequence is 3, 6, 7. The sequence 1, 3, 6, 7 is not valid because 1 and 3 are not adjacent, and 1, 7, 7, 8 is not valid because it is not strictly increasing.

1)
{1, 1, 1, 1, 1}

Returns: 1

A sequence of one element is valid.

2)
{10, 20, 30, 25, 20, 19, 20, 18, 23}

Returns: 4



3)
{3, 2, 1, 4}

Returns: 3



// END CUT HERE
#line 52 "MonotoneSequence.cxx"
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
#define clr(x) memset(x, 0, sizeof(x))
#define forn(i,n) for(__typeof(n) i = 0; i < (n); i++)
#define ford(i,n) for(int i = (n) - 1; i >= 0; i--)
#define For(i, st, en) for(__typeof(en) i = (st); i < (en); i++)

using namespace std;

class MonotoneSequence {
	public:
		int longestMonotoneSequence(vector <int> seq) 
		{
			vector<int> inc, dec;
			inc.push_back(1);
			dec.push_back(1);
			int temp = seq[0], count = 1;
			int temp2 = seq[0], count2 = 1;
			for(int i = 1; i < seq.size(); i++)
			{
				if(temp < seq[i])
				{
					temp = seq[i];
					count++;
					inc.push_back(count);
				}
				else
				{
					inc.push_back(count);
					temp = seq[i];
					count = 1;
				}
				if(temp2 > seq[i])
				{
					temp2 = seq[i];
					count2++;
					dec.push_back(count2);
				}
				else
				{
					dec.push_back(count2);
					temp2 = seq[i];
					count2 = 1;
				}
			}
			return std::max(*max_element(inc.begin(), inc.end()), *max_element(dec.begin(), dec.end()));
		}
};
