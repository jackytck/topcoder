// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
Many spreadsheet applications use positive integers to label rows of cells and strings to label columns of cells. Your task is to write a function that gets the number of the column and returns its label. 



All 26 uppercase letters are used to label the columns. Column labels are ordered according to their length, and labels with the same length are ordered in alphabetical order. Thus, the first 26 columns have a one-letter label, the following 26*26 columns have a two-letter label. 
The sequence of the labels looks as follows:



A, B, C, ..., Z, AA, AB, ..., AZ, BA, BB, ..., ZY, ZZ



The columns are numbered from 1, i.e., column number 1 has the label A. 



DEFINITION
Class:SpreadsheetColumn
Method:getLabel
Parameters:int
Returns:string
Method signature:string getLabel(int column)


NOTES
-The constraints will guarantee that the column label is between "A" and "ZZ", inclusive


CONSTRAINTS
-column will be between 1 and 702, inclusive.


EXAMPLES

0)
1

Returns: "A"

1)
2

Returns: "B"

2)
27

Returns: "AA"

3)
111

Returns: "DG"

4)
702

Returns: "ZZ"

Note that this is the largest possible input.

// END CUT HERE
#line 68 "SpreadsheetColumn.cxx"
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

class SpreadsheetColumn {
	public:
		string getLabel(int column) 
		{		
			string ret;
			if(column <= 26)
				ret += char('A'+column-1);
			else
			{
				ret += char('A'+column/26-(column%26 ? 1 : 2));
				ret += char('A'+column%26-(column%26 ? 1 : -25));
			}
			return ret;
		}
};
