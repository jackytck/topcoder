// BEGIN CUT HERE
// PROBLEM STATEMENT
// Pig Latin is a simple way of encoding words. We have invented a competitor 
called "Vowel Latin". It just changes the order of the 
letters in a word by moving all the vowels to the end, keeping them in the
same order as they appeared in the original word. 

Vowels are defined to be the letters 'a', 'e', 'i', 'o', and 'u' (in either uppercase or
lowercase). The reordering of the letters in a word does not change their case.
So the Vowel Latin version of "AmplifierX" would be "mplfrXAiie" 

Create a class VowelLatin that contains a method translate that is given a string
word and that returns the Vowel Latin version of word.



DEFINITION
Class:VowelLatin
Method:translate
Parameters:string
Returns:string
Method signature:string translate(string word)


CONSTRAINTS
-word contains between 1 and 50 characters, inclusive.
-Each character in word is a letter ('A'-'Z', 'a'-'z').


EXAMPLES

0)
"XYz"

Returns: "XYz"



   The word contains no vowels so it is unchanged by translating to Vowel Latin.



1)
"application"

Returns: "pplctnaiaio"



   The 5 vowels in this word are all moved to the end of the word.

2)
"qwcvb"

Returns: "qwcvb"

3)
"aeioOa"

Returns: "aeioOa"

// END CUT HERE
#line 64 "VowelLatin.cxx"
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

class VowelLatin {
	public:
		string translate(string word) 
		{		
			string v("aeiouAEIOU"), left, right;
			forn(i, word.sz)
				if(v.find(word[i]) != string::npos)
					right += word[i];
				else
					left += word[i];
			return left + right;
		}
};
