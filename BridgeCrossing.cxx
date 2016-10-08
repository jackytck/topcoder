// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// A well-known riddle goes like this: Four people are crossing an old bridge. The bridge cannot hold more than two people at once. It is dark, so they can't walk without a flashlight, and they only have one flashlight! Furthermore, the time needed to cross the bridge varies among the people in the group. For instance, let's say that the people take 1, 2, 5 and 10 minutes to cross the bridge. When people walk together, they always walk at the speed of the slowest person. It is impossible to toss the flashlight across the bridge, so one person always has to go back with the flashlight to the others. What is the minimum amount of time needed to get all the people across the bridge?

In this instance, the answer is 17. Person number 1 and 2 cross the bridge together, spending 2 minutes. Then person 1 goes back with the flashlight, spending an additional one minute. Then person 3 and 4 cross the bridge together, spending 10 minutes. Person 2 goes back with the flashlight (2 min), and person 1 and 2 cross the bridge together (2 min). This yields a total of 2+1+10+2+2 = 17 minutes spent.

You want to create a computer program to help you solve new instances of this problem. Given an vector <int> times, where the elements represent the time each person spends on a crossing, your program should return the minimum possible amount of time spent crossing the bridge.

DEFINITION
Class:BridgeCrossing
Method:minTime
Parameters:vector <int>
Returns:int
Method signature:int minTime(vector <int> times)


NOTES
-In an optimal solution, exactly two people will be sent across the bridge with the flashlight each time (if possible), and exactly one person will be sent back with the flashlight each time.  In other words, in an optimal solution, you will never send more than one person back from the far side at a time, and you will never send less than two people across to the far side each time (when possible).


CONSTRAINTS
-times will have between 1 and 6 elements, inclusive.
-Each element of times will be between 1 and 100, inclusive.


EXAMPLES

0)
{ 1, 2, 5, 10 }

Returns: 17

The example from the text.

1)
{ 1, 2, 3, 4, 5 }

Returns: 16

One solution is: 1 and 2 cross together (2min), 1 goes back (1min), 4 and 5 cross together (5min), 2 goes back (2min), 1 and 3 cross together (3min), 1 goes back (1min), 1 and 2 cross together (2min). This yields a total of 2 + 1 + 5 + 2 + 3 + 1 + 2 = 16 minutes spent.

2)
{ 100 }

Returns: 100

Only one person crosses the bridge once.

3)
{ 1, 2, 3, 50, 99, 100 }

Returns: 162

*/
// END CUT HERE
#line 58 "BridgeCrossing.cxx"
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

class BridgeCrossing
{
	public:
	int minTime(vector <int> times)
	{	 	 
        if(times.sz == 1)
            return times[0];
        _best = 100*5+100*5;
        _people.resize(times.sz, 0);
        _times = times;
        go(0, times.sz);
        return _best;
	} 

    void go(int time, int left)
    {
        forn(i, _people.sz-1)
            For(j, i+1, _people.sz)
                if(_people[i] == 0 && _people[j] == 0)
                {
                    _people[i] = _people[j] = 1;
                    int newTime = time + max(_times[i], _times[j]);
                    if(left == 2)
                        _best <?= newTime;
                    else
                    {
                        int fastestIndex = 0;
                        int backTime = -1;
                        forv(k, _people)
                            if(_people[k] == 1)
                                if(backTime == -1 || _times[k] < backTime)
                                {
                                    backTime = _times[k];
                                    fastestIndex = k;
                                }
                        _people[fastestIndex] = 0;
                        go(newTime+backTime, left-1);
                        _people[fastestIndex] = 1;
                    }
                    _people[i] = _people[j] = 0;
                }
    }

    int _best;
    vector <int> _times, _people;
        	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 1, 2, 5, 10 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 17; verify_case(0, Arg1, minTime(Arg0)); }
	void test_case_1() { int Arr0[] = { 1, 2, 3, 4, 5 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; verify_case(1, Arg1, minTime(Arg0)); }
	void test_case_2() { int Arr0[] = { 100 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; verify_case(2, Arg1, minTime(Arg0)); }
	void test_case_3() { int Arr0[] = { 1, 2, 3, 50, 99, 100 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 162; verify_case(3, Arg1, minTime(Arg0)); }

// END CUT HERE
 
}; 
// BEGIN CUT HERE 
int main()
{
	BridgeCrossing ___test; 
        	___test.run_test(-1); 
}
// END CUT HERE 
