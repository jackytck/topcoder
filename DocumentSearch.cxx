// BEGIN CUT HERE
// PROBLEM STATEMENT
// You have been tasked with writing a function that will scan through a given document, and determine how many times a given word or phrase appears in that document.  However, it is important that your function does not count overlapping occurrences.  For instance, if the document were "abababa", and the search keyword was "ababa", you could find the keyword starting at index 0, or at index 2, but not both, since they would overlap.

You must concatenate the elements of the given vector <string> doc into a single string.  Then, return the maximum number of non-overlapping occurrences of the string search.

To find a maximal set of non-overlapping occurrences, perform the following procedure.  Starting from the left, find the first occurrence of the search string.  Then, continuing with the character immediately following the search string, continue looking for the next occurrence.  Repeat until no new occurrences can be found.  By continuing immediately following each found occurrence, we guarantee that we will not count overlaps.



DEFINITION
Class:DocumentSearch
Method:nonIntersecting
Parameters:vector <string>, string
Returns:int
Method signature:int nonIntersecting(vector <string> doc, string search)


CONSTRAINTS
-doc will contain between 1 and 50 elements, inclusive.
-Each element of doc will contain between 1 and 50 characters, inclusive.
-Each character of each element of doc will be a lowercase letter ('a'-'z') or a space (' ').
-search will contain between 1 and 50 characters, inclusive.
-Each character of search will be a lowercase letter ('a'-'z') or a space (' ').


EXAMPLES

0)
{"ababababa"}
"ababa"

Returns: 1

The example from the problem statement.

1)
{"ababababa"}
"aba"

Returns: 2

There are multiple ways to find the string twice, but it doesn't matter how we do it.

2)
{"abcdefghijklmnop",
 "qrstuvwxyz"}
"pqrs"

Returns: 1

Be sure to concatenate the document first.

3)
{"aaa", "aa", "a", "a"}
"aa"

Returns: 3



// END CUT HERE
#line 64 "DocumentSearch.cxx"
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

class DocumentSearch {
	public:
		int nonIntersecting(vector <string> doc, string search) 
		{		
			int cnt = 0;
			string docs;
			forv(i, doc)
				docs += doc[i];
			while(docs.find(search) != string::npos)
			{
				int i = docs.find(search);
				docs = docs.substr(i + search.sz, docs.sz - i - search.sz);
				cnt++;
			}
			return cnt;
		}
};
