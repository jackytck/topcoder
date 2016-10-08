// BEGIN CUT HERE
// PROBLEM STATEMENT
//   A prime number is an integer greater than 1 that has no positive divisors other than 1 and itself. The first prime numbers are 2, 3, 5, 7, 11, 13, 17, ...
The number N is considered far from primes if there are no prime numbers between N-10 and N+10, inclusive, i.e., all numbers N-10, N-9,  ..., N-1, N, N+1, ..., N+9, N+10 are not prime.
You are given an int A and an int B. Return the number of far from primes numbers between A and B, inclusive.


DEFINITION
Class:FarFromPrimes
Method:count
Parameters:int, int
Returns:int
Method signature:int count(int A, int B)


CONSTRAINTS
-A will be between 10 and 100000, inclusive.
-B will be between A and 100000, inclusive.
-(B - A) will be between 0 and 1000, inclusive.


EXAMPLES

0)
3328
4100

Returns: 4

The far from primes numbers are 3480, 3750, 3978 and 4038.

1)
10
1000

Returns: 0

2)
19240
19710

Returns: 53

3)
23659
24065

Returns: 20

4)
97001
97691

Returns: 89

// END CUT HERE
#line 58 "FarFromPrimes.cxx"
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

class FarFromPrimes {
	public:
		bool isPrime(int k)
		{
			bool ret = true;
			For(i, 2, k)
				if(k%i == 0)
					ret = false;
			return (k == 0 || k == 1) ? false : ret;
		}

		int count(int A, int B) 
		{		
			int ret = 0;
			vector <bool> prime;
			for(int i=A-10; i<=B+10; i++)
				prime.PB(isPrime(i));
			for(int i=A; i<=B; i++)
			{
				if(!prime[i-A+10])
				{
					bool far = true;
					for(int j=i-10; j<=i+10; j++)
						if(prime[j-A+10])
							far = false;
					if(far)
						ret++;
				}
			}
			return ret;
		}
};
