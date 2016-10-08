// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You work for an electric company, and the power goes out in a rather large apartment complex with a lot of irate tenants. You isolate the problem to a network of sewers underneath the complex with a step-up transformer at every junction in the maze of ducts. Before the power can be restored, every transformer must be checked for proper operation and fixed if necessary. To make things worse, the sewer ducts are arranged as a tree with the root of the tree at the entrance to the network of sewers. This means that in order to get from one transformer to the next, there will be a lot of backtracking through the long and claustrophobic ducts because there are no shortcuts between junctions. Furthermore, it's a Sunday; you only have one available technician on duty to search the sewer network for the bad transformers. Your supervisor wants to know how quickly you can get the power back on; he's so impatient that he wants the power back on the moment the technician okays the last transformer, without even waiting for the technician to exit the sewers first.
 You will be given three vector <int>'s: fromJunction, toJunction, and ductLength that represents each sewer duct. Duct i starts at junction (fromJunction[i]) and leads to junction (toJunction[i]). ductlength[i] represents the amount of minutes it takes for the technician to traverse the duct connecting fromJunction[i] and toJunction[i]. Consider the amount of time it takes for your technician to check/repair the transformer to be instantaneous. Your technician will start at junction 0 which is the root of the sewer system. Your goal is to calculate the minimum number of minutes it will take for your technician to check all of the transformers. You will return an int that represents this minimum number of minutes.

DEFINITION
Class:PowerOutage
Method:estimateTimeOut
Parameters:vector <int>, vector <int>, vector <int>
Returns:int
Method signature:int estimateTimeOut(vector <int> fromJunction, vector <int> toJunction, vector <int> ductLength)


CONSTRAINTS
-fromJunction will contain between 1 and 50 elements, inclusive.
-toJunction will contain between 1 and 50 elements, inclusive.
-ductLength will contain between 1 and 50 elements, inclusive.
-toJunction, fromJunction, and ductLength must all contain the same number of elements.
-Every element of fromJunction will be between 0 and 49 inclusive.
-Every element of toJunction will be between 1 and 49 inclusive.
-fromJunction[i] will be less than toJunction[i] for all valid values of i.
-Every (fromJunction[i],toJunction[i]) pair will be unique for all valid values of i.
-Every element of ductlength will be between 1 and 2000000 inclusive.
-The graph represented by the set of edges (fromJunction[i],toJunction[i]) will never contain a loop, and all junctions can be reached from junction 0.


EXAMPLES

0)
{0}
{1}
{10}

Returns: 10

The simplest sewer system possible. Your technician would first check transformer 0, travel to junction 1 and check transformer 1, completing his check. This will take 10 minutes.

1)
{0,1,0}
{1,2,3}
{10,10,10}

Returns: 40

Starting at junction 0, if the technician travels to junction 3 first, then backtracks to 0 and travels to junction 1 and then junction 2, all four transformers can be checked in 40 minutes, which is the minimum.

2)
{0,0,0,1,4}
{1,3,4,2,5}
{10,10,100,10,5}

Returns: 165

Traveling in the order 0-1-2-1-0-3-0-4-5 results in a time of 165 minutes which is the minimum.

3)
{0,0,0,1,4,4,6,7,7,7,20}
{1,3,4,2,5,6,7,20,9,10,31}
{10,10,100,10,5,1,1,100,1,1,5}

Returns: 281

Visiting junctions in the order 0-3-0-1-2-1-0-4-5-4-6-7-9-7-10-7-8-11 is optimal, which takes  (10+10+10+10+10+10+100+5+5+1+1+1+1+1+1+100+5) or 281 minutes.

4)
{0,0,0,0,0}
{1,2,3,4,5}
{100,200,300,400,500}

Returns: 2500

*/
// END CUT HERE
#line 76 "PowerOutage.cxx"
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

class node
{
    public:
        node(int n, int d): name(n), distance(d)
    {
    }
        int name;
        int distance;
};

class PowerOutage
{
	public:
	int estimateTimeOut(vector <int> fromJunction, vector <int> toJunction, vector <int> ductLength)
	{	 	 
        int maxdist = 0, sumall = 0;
        node * root = new node(0, 0);
        stack <node *> Stack;
        Stack.push(root);
        while(!Stack.empty())
        {
            node * t = Stack.top();
            Stack.pop();
            forv(i, fromJunction)
                if(fromJunction[i] == t->name)
                {
                    Stack.push(new node(toJunction[i], ductLength[i]+t->distance));
                    maxdist >?= ductLength[i]+t->distance;
                }
            delete t;
        }
        sumall = accumulate(ductLength.begin(), ductLength.end(), 0);
        return 2*sumall-maxdist;
	} 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; verify_case(0, Arg3, estimateTimeOut(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0,1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10,10,10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 40; verify_case(1, Arg3, estimateTimeOut(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {0,0,0,1,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,3,4,2,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10,10,100,10,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 165; verify_case(2, Arg3, estimateTimeOut(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {0,0,0,1,4,4,6,7,7,7,20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,3,4,2,5,6,7,20,9,10,31}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10,10,100,10,5,1,1,100,1,1,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 281; verify_case(3, Arg3, estimateTimeOut(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {0,0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {100,200,300,400,500}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2500; verify_case(4, Arg3, estimateTimeOut(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
}; 
// BEGIN CUT HERE 
int main()
{
	PowerOutage ___test; 
        	___test.run_test(-1); 
}
// END CUT HERE 
