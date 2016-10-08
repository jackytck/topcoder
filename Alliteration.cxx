// BEGIN CUT HERE
// PROBLEM STATEMENT
// An alliteration consists of two or more consecutive words which start with the same letter (ignoring case).
You are given a sequence of words. Find out the number of alliterations in this sequence, considering only alliterations which cannot be extended.

DEFINITION
Class:Alliteration
Method:count
Parameters:vector <string>
Returns:int
Method signature:int count(vector <string> words)


CONSTRAINTS
-words will contain between 1 and 50 elements, inclusive.
-Each element of words will contain between 1 and 50 letters ('a'-'z', 'A'-'Z'), inclusive.


EXAMPLES

0)
{"He", "has", "four", "fanatic", "fantastic", "fans"}

Returns: 2

The first two words are an alliteration, and the last four words are another alliteration.

1)
{"There", "may", "be", "no", "alliteration", "in", "a", "sequence"}

Returns: 0

This sequence of words contains no alliteration.

2)
{"Round", "the", "rugged", "rock", "the", "ragged", "rascal", "ran"}

Returns: 2



// END CUT HERE
#line 44 "Alliteration.cxx"
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

class Alliteration {
	public:
		int count(vector <string> words) 
		{		
			char f('#');
			vector <int> cnt(words.sz, 0);
			int ret = 0;
			forv(i, words)
			{
				if(f != tolower(words[i][0]))
				{
					f = tolower(words[i][0]);
					cnt[i]++;
				}
			}
			forn(i, cnt.sz-1)
				if(cnt[i] == 1 && cnt[i+1] == 0)
					ret++;
			return ret;
		}
};
