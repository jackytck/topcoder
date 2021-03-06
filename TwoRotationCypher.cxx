// BEGIN CUT HERE
// PROBLEM STATEMENT
// You have decided to create your own simple encryption method for strings containing only lowercase letters and spaces. You start by splitting the alphabet into two groups. The first group consists of the first firstSize letters of the alphabet, and the second consists of the remaining 26 - firstSize letters. To encrypt a character in your message, you do the following:

If it a space, it is kept as is.
If it is a letter in the first group, it is moved firstRotate letters forward in the group, wrapping back to the start if necessary. For example, if firstSize is 6 and firstRotate is 2, then 'A' would become 'C', and 'F' would become 'B'.
If it is a letter in the second group, then it is moved secondRotate letters forward in the group, again wrapping back to the start of the group if necessary.


Given firstSize, firstRotate, secondRotate and a message, return the encrypted form of the message.

DEFINITION
Class:TwoRotationCypher
Method:encrypt
Parameters:int, int, int, string
Returns:string
Method signature:string encrypt(int firstSize, int firstRotate, int secondRotate, string message)


CONSTRAINTS
-firstSize will be between 1 and 25, inclusive.
-firstRotate will be between 0 and firstSize - 1, inclusive.
-secondRotate will be between 0 and 25 - firstSize, inclusive.
-message will contain between 1 and 50 characters, inclusive.
-message will contain only lowercase letters ('a' - 'z') and spaces.


EXAMPLES

0)
13
0
0
"this string will not change at all"

Returns: "this string will not change at all"



1)
13
7
0
"only the letters a to m in this string change"
abcdefghijklm
hijklmabcdefg
Returns: "onfy tbl flttlrs h to g cn tbcs strcna jbhnal"



2)
9
0
16
"j to z will change here"
abcdefghi jklmnopqrstuvwxyz
jklmnopqrstuvwxyz
zjklmnopqrstuvwxy
Returns: "z sn y vikk chamge heqe"



3)
17
9
5
"the quick brown fox jumped over the lazy dog"

Returns: "yqn izalc kwgsf ogt bzehnm grnw yqn djvu mgp"



4)
3
1
2
"  watch   out for strange  spacing "
abc
bca
Returns: "  ybvaj   qwv hqt uvtbpig  urbakpi "



// END CUT HERE
#line 82 "TwoRotationCypher.cxx"
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

class TwoRotationCypher {
	public:
		string encrypt(int firstSize, int firstRotate, int secondRotate, string message) 
		{		
			string en = message;
			forn(i, message.sz)
			{
				if(message[i] == ' ')
				{
					continue;
				}
				else if(message[i] - 'a' < firstSize)
				{
					if(firstRotate == 0) continue;
					if(message[i] - 'a' < firstSize - firstRotate)
					{
						en[i] = message[i] + firstRotate;
					}
					else
					{
						en[i] = message[i] - (firstSize - firstRotate);
					}
				}
				else
				{
					if(secondRotate == 0) continue;
					if('z' - message[i] >= secondRotate)
					{
						en[i] = message[i] + secondRotate;
					}
					else
					{
						en[i] = message[i] - (26 - firstSize - secondRotate);
					}
				}
			}
				return en;
		}
};
