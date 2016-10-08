// BEGIN CUT HERE
// PROBLEM STATEMENT
// 

You are implementing the member registration system of an online dating
site. When a new member signs up, it is possible that she initially
chooses the same username as an existing member. The system must then
inform the new member of the conflict and suggest a variant of the chosen
name with a number attached to the end.




If an existing member is named "FunkyMonkey", for example, and
a new member wants the same username, the simplest suggestion the system
can make is "FunkyMonkey1".  If there is already a member by
that name, the system must suggest "FunkyMonkey2", unless that 
variant is also taken. If all names from "FunkyMonkey1"
through "FunkyMonkey9" are taken as well as the
original "FunkyMonkey", the system moves on to consider 
"FunkyMonkey10", and so on. The goal is to use the smallest possible
number in the variant. Note that each username consists of letters (the characters
from 'a' to 'z' and from 'A' to 'Z') and numerals ('0' to '9').




You are given a vector <string>, existingNames, containing
all usernames that have already been registered in the system. You are
also given a single string, newName, containing the
username that a new member wants to use. In the event of a conflict, this
member will accept the suggestion offered by your system in accordance
with the principles above. Return a string containing the
username finally assigned to the new member.





DEFINITION
Class:UserName
Method:newMember
Parameters:vector <string>, string
Returns:string
Method signature:string newMember(vector <string> existingNames, string newName)


NOTES
-The constraints rule out names that end in a number with a leading zero, such as "grokster006" and "bart0".


CONSTRAINTS
-existingNames contains between 1 and 50 elements, inclusive
-each element of existingNames is between 1 and 50 characters long, inclusive
-the only characters permitted in elements of existingNames are 'a' to 'z', 'A' to 'Z', and '0' to '9'
-no element of existingNames ends in a number that has a leading zero
-newName is between 1 and 50 characters long, inclusive
-the only characters permitted in newName are 'a' to 'z' and 'A' to 'Z'


EXAMPLES

0)
{"MasterOfDisaster", "DingBat", "Orpheus", "WolfMan", "MrKnowItAll"}
"TygerTyger"

Returns: "TygerTyger"

"TygerTyger" is available.

1)
{"MasterOfDisaster", "TygerTyger1", "DingBat", "Orpheus", 
 "TygerTyger", "WolfMan", "MrKnowItAll"}
"TygerTyger"

Returns: "TygerTyger2"

"TygerTyger" and "TygerTyger1" are taken.

2)
{"TygerTyger2000", "TygerTyger1", "MasterDisaster", "DingBat", 
 "Orpheus", "WolfMan", "MrKnowItAll"}
"TygerTyger"

Returns: "TygerTyger"

There are higher-numbered variants of "TygerTyger", but the base name is available.

3)
{"grokster2", "BrownEyedBoy", "Yoop", "BlueEyedGirl", 
 "grokster", "Elemental", "NightShade", "Grokster1"}
"grokster"

Returns: "grokster1"

Note that "Grokster1" is not the same as "grokster1".

4)
{"Bart4", "Bart5", "Bart6", "Bart7", "Bart8", "Bart9", "Bart10",
 "Lisa", "Marge", "Homer", "Bart", "Bart1", "Bart2", "Bart3",
 "Bart11", "Bart12"}
"Bart"

Returns: "Bart13"

// END CUT HERE
#line 108 "UserName.cxx"
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

class UserName {
	public:
		string newMember(vector <string> existingNames, string newName) 
		{		
			string ret = newName;
			int append = 0;
			while(find(existingNames.begin(), existingNames.end(), ret) != existingNames.end())
			{
				append++;
				stringstream ss;
				string no;
				ss << append;
				ss >> no;
				ret = newName+no;
			}
			return ret;
		}
};
