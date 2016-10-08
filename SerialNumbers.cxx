// BEGIN CUT HERE
// PROBLEM STATEMENT
// You own a lot of guitars, and each guitar has a unique serial number.  You want to be able to  look up serial numbers quickly, so you decide to sort the entire list as follows.

Each serial number consists of uppercase letters ('A' - 'Z') and digits ('0' - '9'). To see if serial number A comes before serial number B, use the following steps:

   If A and B have a different length, the one with the shortest length comes first.
   Else if sum_of_digits(A) differs from sum_of_digits(B) (where sum_of_digits(X) returns the sum of all digits in string X), the one with the lowest sum comes first.
   Else compare them alphabetically, where digits come before letters.

Given a vector <string> serialNumbers, return a vector <string> with the ordered list of serial numbers in increasing order.

DEFINITION
Class:SerialNumbers
Method:sortSerials
Parameters:vector <string>
Returns:vector <string>
Method signature:vector <string> sortSerials(vector <string> serialNumbers)


CONSTRAINTS
-serialNumbers will contain between 1 and 50 elements, inclusive.
-Each element of serialNumbers will contain between 1 and 50 characters, inclusive.
-serialNumbers will only contain uppercase letters ('A' - 'Z') and digits ('0' - '9').
-All elements of serialNumbers will be distinct.


EXAMPLES

0)
{"ABCD","145C","A","A910","Z321"}

Returns: {"A", "ABCD", "Z321", "145C", "A910" }

The first serial is "A" because it has the shortest length. All others have length 4, but "ABCD" has the lowest sum. Next lowest is "Z321", and finally "A910" comes before "145C" because "A" comes before the "1" (they both have sum = 10)

1)
{"Z19", "Z20"}

Returns: {"Z20", "Z19" }

1+9 > 2+0, so "Z20" comes first.

2)
{"34H2BJS6N","PIM12MD7RCOLWW09","PYF1J14TF","FIPJOTEA5"}

Returns: {"FIPJOTEA5", "PYF1J14TF", "34H2BJS6N", "PIM12MD7RCOLWW09" }



3)
{"ABCDE", "BCDEF", "ABCDA", "BAAAA", "ACAAA"}

Returns: {"ABCDA", "ABCDE", "ACAAA", "BAAAA", "BCDEF" }



// END CUT HERE
#line 60 "SerialNumbers.cxx"
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

bool cmp(const string &a, const string &b)
	{
		if(a.sz > b.sz)
			return false;
		else if(a.sz < b.sz)
			return true;
		else{
			int suma = 0, sumb = 0;
			forn(i, a.sz)
			{
				if(a[i] - '0' >= 0 && a[i] - '9' <= 0)
					suma += a[i] - '0';
			}
			forn(i, b.sz)
			{
				if(b[i] - '0' >= 0 && b[i] - '9' <= 0)
					sumb += b[i] - '0';
			}
			if(suma > sumb)
				return false;
			else if(suma < sumb)
				return true;
			else
				return a < b;
		}
	}

class SerialNumbers {
	public:
		vector <string> sortSerials(vector <string> serialNumbers) 
		{		
			sort(serialNumbers.begin(), serialNumbers.end(), cmp);
			return serialNumbers;
		}
};
