// BEGIN CUT HERE
// PROBLEM STATEMENT
// In the English language, a syllable can be loosely defined as a unit of uninterrupted sound. One can usually count the number of syllables in an English word by 'sounding it out'. In general, however, it is difficult to write a program to count the number of syllables in a word.


Here, we'll use the following procedure to count syllables: Each group of vowels {'A', 'E', 'I', 'O', 'U'} appearing in the word will add one syllable to the total number of syllables in the word. A group of vowels is either separated by consonants (all letters A-Z that are not vowels) or the group appears at the beginning or end of the word. So, for example, the word "HELLO" contains 2 syllables according to the above procedure due to the vowels 'E' and 'O'. The word "FOOBAR" also contains 2 syllables, even though there are 3 vowels in the word. This is because the two 'O' vowels are considered one group of vowels. Finally, the word "TELEVISION" contains 4 syllables.


Create a class SyllableCounter containing a method countSyllables which takes a string word as input. The method should return an int corresponding to the number of syllables in word according to the above algorithm.

DEFINITION
Class:SyllableCounter
Method:countSyllables
Parameters:string
Returns:int
Method signature:int countSyllables(string word)


CONSTRAINTS
-word will contain between 3 and 50 characters inclusive.
-word will contain only uppercase letters ('A'-'Z').
-word will contain at least one vowel and at least one consonant.


EXAMPLES

0)
"VOLUME"

Returns: 3

Note that this returns 3 because of the vowels O, U, and E. Your method should return 3 despite the fact that in spoken English, the E at the end doesn't actually create a syllable.

1)
"TELEVISION"

Returns: 4

2)
"BOOKKEEEEEEEEEEEEPER"

Returns: 3

3)
"SLKJSGLKAKHDGHELHDGILKLHDGOLOOOOOL"

Returns: 5

// END CUT HERE
#line 51 "SyllableCounter.cxx"
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

class SyllableCounter {
	public:
		int countSyllables(string word) 
		{		
			int ret = 0;
			string v = "AEIOU", temp;
			forv(i, word)
				if(v.find(word[i], 0) == string::npos)
					word[i] = ' ';
			stringstream ss(word);
			while(ss>>temp)
				ret++;
			return ret;
		}
};
