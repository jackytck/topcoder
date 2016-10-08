// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
You are given a vector <string> text, each element of which contains a single word.  Encrypt the text by removing 
all vowels ('a', 'e', 'i', 'o', 'u') from every word that contains at least one non-vowel.  If a word consists only of vowels, leave it as is.  Return the result as a vector <string>, where the ith element is the encrypted version of the ith element in text.


DEFINITION
Class:VowelEncryptor
Method:encrypt
Parameters:vector <string>
Returns:vector <string>
Method signature:vector <string> encrypt(vector <string> text)


CONSTRAINTS
-text will contain between 1 and 50 elements, inclusive.
-Each element of text will contain between 1 and 20 lowercase letters ('a'-'z'), inclusive.


EXAMPLES

0)
{"hello", "world"}

Returns: {"hll", "wrld" }



1)
{"a", "b", "c"}

Returns: {"a", "b", "c" }



2)
{"he", "who", "is", "greedy", "is", "disgraced"}

Returns: {"h", "wh", "s", "grdy", "s", "dsgrcd" }



// END CUT HERE
#line 46 "VowelEncryptor.cxx"
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

class VowelEncryptor {
	public:
		vector <string> encrypt(vector <string> text) 
		{		
			vector <string> ret;
			forv(i, text)
			{
				bool allv = true;
				forn(j, text[i].sz)
				{
					if(!(text[i][j] == 'a' || text[i][j] == 'e' || text[i][j] == 'i' || text[i][j] == 'o' || text[i][j] == 'u'))
						allv = false;
				}
				if(!allv)
				{
					string in;
					forn(j, text[i].sz)
					{
						if(!(text[i][j] == 'a' || text[i][j] == 'e' || text[i][j] == 'i' || text[i][j] == 'o' || text[i][j] == 'u'))
							in += text[i][j];
					}
					ret.PB(in);
				}
				else
					ret.PB(text[i]);
			}
			return ret;

		}
};
