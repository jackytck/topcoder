// BEGIN CUT HERE
// PROBLEM STATEMENT
// You are developing an application for online transactions and you want to accept several credit cards. Card numbers, however, are usually long, so it's easy to make mistakes when typing them in. You want to create a method that will verify the numbers entered by users.

You know that the Luhn formula applies for all the acceptable card numbers.
The Luhn formula works as follows.

First, separate the individual digits of the credit card number.  For example:

21378 becomes
2 1 3 7 8

If there is an even number of digits, multiply each digit in an odd position by 2. Otherwise, multiply each digit in an even position by 2. Positions are 1-indexed, so the first digit is at position 1. The example number above contains an odd number of digits, so we multiply each digit in an even position by 2:

2 1 3 7 8 becomes
2 2 3 14 8

Note that the even positions refer to the original number so they don't change even when a 2-digit number appears.

Finally, take the sum of all the digits (for 2-digit numbers insert both the digits separately into the sum):

2+2+3+1+4+8 = 20

If the sum is a multiple of 10, the number is valid. Otherwise, it is invalid.

Given a string cardNumber containing the credit card number, return "VALID" if the card number is valid, or "INVALID" if it is invalid (all quotes for clarity).


DEFINITION
Class:VerifyCreditCard
Method:checkDigits
Parameters:string
Returns:string
Method signature:string checkDigits(string cardNumber)


CONSTRAINTS
-cardNumber will contain between 1 and 50 characters, inclusive.
-Each character in cardNumber will be a digit ('0'-'9').


EXAMPLES

0)
"21378"

Returns: "VALID"

This number has 5 digits, which is an odd number, so we multiply the digits in even positions by 2 to get:

2 2 3 14 8

The sum of the digits is 20, which is a multiple of 10, meaning it's a valid number.

1)
"31378"

Returns: "INVALID"

When we apply the Luhn formula here, the sum of the digits is 21, so the number is invalid.


2)
"11111101"

Returns: "VALID"

We multiply the digits in odd positions by 2 to get:

2 1 2 1 2 1 0 1

The sum of the digits is 10, so it's a valid card.


3)
"50005"

Returns: "VALID"

All the digits in even positions are 0 so multiplying by 2 doesn't change the number. The sum of the digits is 10, so it's a valid card.

4)
"542987223412"

Returns: "INVALID"



// END CUT HERE
#line 91 "VerifyCreditCard.cxx"
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

class VerifyCreditCard {
	public:
		int sumDigits(int n)
		{
			int sum = 0;
			while(n != 0)
			{
				sum += n%10;
				n /= 10;
			}
			return sum;
		}

		string checkDigits(string cardNumber) 
		{		
			int sum = 0;
			vector <int> nu;
			forn(i, cardNumber.sz)
			{
				if(cardNumber.sz % 2 == 0)
				{
					if((i+1)%2 == 1)
					{
						nu.PB((cardNumber[i]-'0')*2);
					}
					else
						nu.PB(cardNumber[i]-'0');
				}
				else
				{
					if((i+1)%2 == 0)
					{
						nu.PB((cardNumber[i]-'0')*2);
					}
					else
						nu.PB(cardNumber[i]-'0');
				}
			}
			forv(i, nu)
			{
				sum += sumDigits(nu[i]);
			}
			return sum%10 == 0 ? "VALID": "INVALID";
		}
};
