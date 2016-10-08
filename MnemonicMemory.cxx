// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
It is often helpful to have a mnemonic phrase handy for a math test.  For example, the number 25735 can be remembered as "is there anybody out there".  If we count the number of characters in every word, we would get the sequence 2, 5, 7, 3, 5, which represents the original number!


Unfortunately for you, your professor likes to make the students memorize random numbers and then test them.  To beat the system, your plan is to come up with mnemonic phrases that will represent the numbers you must memorize.


You are given a string number and a vector <string> dictionary.  Return a single space delimited list of words, where each word is an element of dictionary, and no element of dictionary is used more than once. The phrase must contain exactly n words, where n is the number of digits in the number, and the length of the i-th word must be equal to the i-th digit of the number for all i.  If more than one phrase is possible, return the one that comes first alphabetically (in other words, if you have several words of the same length, you should use them in alphabetical order).


DEFINITION
Class:MnemonicMemory
Method:getPhrase
Parameters:string, vector <string>
Returns:string
Method signature:string getPhrase(string number, vector <string> dictionary)


CONSTRAINTS
-dictionary will contain between 1 and 50 elements, inclusive.
-Each element of dictionary will contain between 1 and 9 characters, inclusive.
-Each element of dictionary will contain only lowercase letters ('a'-'z').
-number will contain between 1 and 50 characters, inclusive.
-number will contain only digits between '1' and '9', inclusive.
-There will always be a possible solution with the given dictionary.


EXAMPLES

0)
"25735"
{"is", "there", "anybody", "out", "there"}

Returns: "is there anybody out there"

The example from the problem statement.

1)
"31415926"
{"may", "i", "have", "a", "large", "container", "of", "coffee"}

Returns: "may a have i large container of coffee"

Make sure you use words of the same length in alphabetical order.

2)
"1212"
{"a", "aa", "a", "aa"}

Returns: "a aa a aa"



3)
"11111111122"
{"a", "b", "d", "c", "a", "e", "f", "z", "zz", "za", "az", "e"}

Returns: "a a b c d e e f z az za"



4)
"2222"
{"ab", "cd", "ef", "a", "b", "ab"}

Returns: "ab ab cd ef"



// END CUT HERE
#line 74 "MnemonicMemory.cxx"
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

class MnemonicMemory {
	public:
		string getPhrase(string number, vector <string> dictionary) 
		{		
			sort(dictionary.begin(), dictionary.end());
			string phrase;
			forn(i, number.sz)
			{
				forv(j, dictionary)
				{
					if(dictionary[j] != "#" && dictionary[j].sz == number[i] - '0')
					{
						phrase += dictionary[j]; 
						if(i != number.sz - 1)
							phrase += " ";
						dictionary[j] = "#";
						break;
					}
				}
			}
			return phrase;
		}

};
