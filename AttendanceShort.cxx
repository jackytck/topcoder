// BEGIN CUT HERE
// PROBLEM STATEMENT
// The students at your university have lately picked up the annoying habit of missing classes. To fix this problem your board has decided to only allow students with 75% or higher attendance to sit for the exams. Given a vector <string> names containing the students' names and a vector <string> attendance containing their attendance records, return the list of students who have less than 75% attendance.

The ith student's name is given as the ith element of names and his attendance record as the ith element of attendance. The attendance record corresponding to each student is specified as a string of 'A's, 'P's and 'M's. An 'A' indicates the students was absent for a class, whereas a 'P' means he was present and a 'M' means he was absent but he submitted a doctor's note for that class. If a student was absent for a class but submitted a doctor's note then that class is not counted when calculating his attendance percentage. Return a vector <string> containing the names of all the students who do not meet the attendance requirements. The names in the returned vector <string> should be in the same relative order as names.

DEFINITION
Class:AttendanceShort
Method:shortList
Parameters:vector <string>, vector <string>
Returns:vector <string>
Method signature:vector <string> shortList(vector <string> names, vector <string> attendance)


CONSTRAINTS
-names will contain between 0 and 50 elements, inclusive.   
-attendance will contain the same number of elements as names.
-Each element of names will contain between 1 and 50 characters, inclusive.
-Each element of attendance will contain between 1 and 50 characters, inclusive.
-Each element of names will contain only letters ('A' - 'Z' and 'a' - 'z').
-Each element of attendance will contain only 'A', 'P' and 'M' characters.
-Each element of attendance will contain at least one 'A' or 'P' character.


EXAMPLES

0)
{"Justin"}
{"PAAPP"}

Returns: {"Justin" }

Justin has attended 3 of his 5 classes which gives him 3/5 * 100 = 60% attendance. Since this is lower than 75% his name should be returned.

1)
{"Justin","Chris"}
{"PAAPP","PPPPA"}

Returns: {"Justin" }

Chris has attended 4 out of his 5 classes and thus has 80% attendance. Justin has 60% so only Justin's name should be returned.

2)
{"Sunny"}
{"PPPAM"}

Returns: { }

Sunny's attendance is effectively calculated from "PPPA" as classes which have a doctor's note are ignored. This results in a 75% attendance and so his name is not included in the returned list.

3)
{"Mansi", "Arjun", "Nikhil", "Taneja"}
{"PPPPMPPAPP", "AAMAAPP", "PPPPAAP", "PPPAAAMPP"}

Returns: {"Arjun", "Nikhil", "Taneja" }



4)
{}
{}

Returns: { }

Take care of the empty case.

// END CUT HERE
#line 69 "AttendanceShort.cxx"
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

class AttendanceShort {
	public:
		vector <string> shortList(vector <string> names, vector <string> attendance) 
		{		
			vector <string> ret;
			forv(i, attendance)
			{
				int day = 0, ab = 0;
				forn(j, attendance[i].sz)
				{
					if(attendance[i][j] == 'P' || attendance[i][j] == 'A')
						day++;
					if(attendance[i][j] == 'P')
						ab++;
				}
				if(double(ab) / day < 0.75)
					ret.PB(names[i]);
			}
			return ret;
		}
};
