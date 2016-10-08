// BEGIN CUT HERE
// PROBLEM STATEMENT
// In a set of distinct numbers, the median is an element M such that the number of elements greater than M is equal to the number of elements smaller than M. For example, in a set {1, 4, 2, 5, 7} the median is 4 because two elements (5 and 7) are greater than 4 and 2 elements (1 and 2) smaller than 4. The set {1, 5, 8, 3} has no median because no element from it satisfies the definition above.
You are given a vector <int> numbers. Return the median of numbers or -1 if numbers has no median.


DEFINITION
Class:MedianOfNumbers
Method:findMedian
Parameters:vector <int>
Returns:int
Method signature:int findMedian(vector <int> numbers)


CONSTRAINTS
-numbers will contain between 1 and 50 elements, inclusive.
-Each element of numbers will be between 1 and 100, inclusive.
-All elements of numbers will be distinct.


EXAMPLES

0)
{1, 4, 2, 5, 7}

Returns: 4

The example from the statement.

1)
{1, 5, 8, 3}

Returns: -1

2)
{7}

Returns: 7

There are zero elements that are greater than 7 and zero elements that are smaller than 7. 

3)
{7, 12}

Returns: -1

4)
{66, 53, 47, 86, 18, 21, 97, 92, 15}

Returns: 53

5)
{32, 54, 27, 4, 69, 96, 73, 1, 100, 15, 21}

Returns: 32

// END CUT HERE
#line 59 "MedianOfNumbers.cxx"
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

class MedianOfNumbers {
	public:
		int findMedian(vector <int> numbers) 
		{		
			sort(numbers.begin(), numbers.end());
			return numbers.sz%2 == 0 ? -1 : numbers[numbers.sz/2];
		}
};
