// BEGIN CUT HERE
// PROBLEM STATEMENT
// Run-length encoding is a simple compression technique which compresses strings of letters by replacing repeated consecutive letters (called runs) by the number of occurrences of the letter, followed by that letter. For example, AAAABBBCDDE compresses to 4A3BC2DE. The number 1 may be omitted in runs consisting of a single letter, as with letters 'C' and 'E' in the previous example.

Any string consisting of uppercase letters where each letter is optionally preceded by a positive integer is called a properly encoded string. Given a properly encoded string text, return the decoded string. If the decoded string would be more than 50 characters long, return "TOO LONG" (without the quotes).


DEFINITION
Class:RunLengthEncoding
Method:decode
Parameters:string
Returns:string
Method signature:string decode(string text)


CONSTRAINTS
-text will contain between 0 and 50 characters ('0'-'9', 'A'-'Z'), inclusive.
-text will be a properly encoded string: all numbers contained will be positive integers with no leading zeros and each number will precede a letter.


EXAMPLES

0)
"4A3BC2DE"

Returns: "AAAABBBCDDE"

This is the example in the problem statement.

1)
"1A1B1C1D1E"

Returns: "ABCDE"

1's can be omitted, but also may appear in the input. This input is valid, although we'd doubled the size of the string by "compressing" it.


2)
"1A3A5A4BCCCC"

Returns: "AAAAAAAAABBBBCCCC"

Although it isn't the best possible, this is also a properly encoded string.

3)
"50A"

Returns: "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"

4)
"21Z13S9A8M"

Returns: "TOO LONG"

5)
"123456789012345678901234567890B"

Returns: "TOO LONG"

The decoded string would be more than 10^30 characters long, which is more than 50.

// END CUT HERE
#line 64 "RunLengthEncoding.cxx"
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

class RunLengthEncoding {
	public:
		string decode(string text) 
		{		
			int words = 0, repeat = 1;
			string ret = "";
			forn(i, text.sz)
			{
				if(text[i]-'0' >= 0 && text[i]-'0' <= 9)
				{
					if(text[i+1]-'0' >= 0 && text[i+1]-'0' <= 9)
					{
						if(text[i+2]-'0' >= 0 && text[i+2]-'0' <= 9)
						{
							ret = "TOO LONG";
							break;
						}
						else
						{
							repeat = (text[i]-'0')*10 + text[i+1]-'0';
							i++;
						}
					}
					else
						repeat = text[i]-'0';
				}
				else
				{
					words += repeat;
					if(words > 50)
					{
						ret = "TOO LONG";
						break;
					}
					forn(j, repeat)
						ret += text[i];
					repeat = 1;
				}
			}
			return ret;
		}
};
