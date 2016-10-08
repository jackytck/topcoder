// BEGIN CUT HERE
// PROBLEM STATEMENT
// Peter has problems with pronouncing difficult words. In particular he can't pronounce words that contain three or more consecutive consonants (such as "street" or "first"). Furthermore he can't pronounce words that contain two or more consecutive vowels that are different (such as "goal" or "beauty"). He can pronounce words with two consecutive equal vowels though  (such as "need").



Is this problem we consider the 'y' to be always a consonant, even in words like "any". So the vowels are 'a', 'e', 'i', 'o' and 'u'. You are given a vector <string> words. If Peter can pronounce all the words, return an empty string; otherwise return the first word he can't pronounce.

DEFINITION
Class:Pronunciation
Method:canPronounce
Parameters:vector <string>
Returns:string
Method signature:string canPronounce(vector <string> words)


CONSTRAINTS
-words contains between 1 and 50 elements, inclusive.
-Each element of words has length between 1 and 50, inclusive.
-Each element of words consists of upper- and lowercase letters.


EXAMPLES

0)
{"All","of","these","are","not","difficult"}

Returns: ""

1)
{"The","word","REALLY","is","really","hard"}

Returns: "REALLY"

2)
{"TRiCKy"}

Returns: "TRiCKy"

Since the 'y' is a consonant, this word contain three consecutive consonants.

3)
{"irresistable","prerogative","uttermost","importance"}

Returns: ""

Peter can pronounce these words.

4)
{"Aa"}

Returns: ""

// END CUT HERE
#line 56 "Pronunciation.cxx"
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

class Pronunciation {
	public:
		string canPronounce(vector <string> words) 
		{		
			string ret = "", vowels = "AEIOU";
			forv(i, words)
			{
				bool pronounce = true;
				int c = 0;
				string temp = words[i];
				forv(j, temp)
					if(vowels.find(toupper(temp[j])) != string::npos)
						temp[j] = ' ';
				stringstream ss(temp);
				string t;
				while(ss >> t)
					c >?= t.sz;
				if(c >= 3)
					pronounce = false;
				forv(j, temp)
					temp[j] = temp[j] == ' ' ? toupper(words[i][j]) : ' ';
				ss.clear();
				ss.str(temp);
				while(ss >> t)
				{
					if(t.sz >= 2)
					{
						char vt = t[0];
						For(j, 1, t.sz)
							if(t[j] != vt)
								pronounce = false;
					}
				}
				if(!pronounce)
				{
					ret = words[i];
					break;
				}
			}
			return ret;
		}
};
