// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Background

I remember a chain problem from my childhood. Suppose you have four sections of a golden chain. Each consists of three links joined together in a line. You would like to connect all four sections into a necklace. The obvious solution is to cut the last link of each section and use it to connect the first section to the second one, then the second to the third, then the third to the fourth, then the fourth to the first one. If you want to minimize the number of cuts, you can do better. You can cut one of the three link sections into its individual links. Using the three loose links you can join the three remaining sections together.

Your task is, given the lengths of the sections, to return the minimum number of cuts to make one big circular necklace out of all of them.


DEFINITION
Class:GoldenChain
Method:minCuts
Parameters:vector <int>
Returns:int
Method signature:int minCuts(vector <int> sections)


CONSTRAINTS
-sections has between 1 and 50 elements inclusive
-each element of sections is between 1 and 2,147,483,647 inclusive
-the sum of all elements of sections is between 3 and 2,147,483,647 inclusive


EXAMPLES

0)
{3,3,3,3}

Returns: 3

1)
{2000000000}

Returns: 1

2)
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,
21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,
38,39,40,41,42,43,44,45,46,47,48,49,50}

Returns: 42

3)
{20000000,20000000,2000000000}

Returns: 3

4)
{10,10,10,10,10,1,1,1,1,1}

Returns: 5

5)
{1,10}

Returns: 1

*/
// END CUT HERE
#line 62 "GoldenChain.cxx"
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

class GoldenChain
{
	public:
	int minCuts(vector <int> sections)
	{	 	 
        int ret = 0;
        sort(sections.begin(), sections.end());
        int remain = sections.sz;
        forv(i, sections)
        {
            if(remain-1 >= sections[i])
            {
                ret += sections[i];
                remain -= 1+sections[i];
                if(remain == 0)
                    break;
            }
            else
            {
                ret += remain;
                break;
            }
        }
        return ret;
	} 
        	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3,3,3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, minCuts(Arg0)); }
	void test_case_1() { int Arr0[] = {2000000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, minCuts(Arg0)); }
	void test_case_2() { int Arr0[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,
21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,
38,39,40,41,42,43,44,45,46,47,48,49,50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 42; verify_case(2, Arg1, minCuts(Arg0)); }
	void test_case_3() { int Arr0[] = {20000000,20000000,2000000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, minCuts(Arg0)); }
	void test_case_4() { int Arr0[] = {10,10,10,10,10,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(4, Arg1, minCuts(Arg0)); }
	void test_case_5() { int Arr0[] = {1,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(5, Arg1, minCuts(Arg0)); }

// END CUT HERE
 
}; 
// BEGIN CUT HERE 
int main()
{
	GoldenChain ___test; 
        	___test.run_test(-1); 
}
// END CUT HERE 
