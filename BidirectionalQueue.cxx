// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You are given a bidirectional cyclical queue which contains N elements. You need to extract several elements from this queue.

You can do 3 kinds of operations with this queue:

Extract first element. After applying this operation, queue a1, ..., aK becomes a2, ..., aK.

Shift queue elements left. After applying this operation, queue a1, ..., aK becomes a2, ..., aK, a1.

Shift queue elements right. After applying this operation, queue a1, ..., aK becomes aK, a1, ..., aK-1.

You are given the initial number of elements in the queue N and a vector <int> indices which contains the initial (1-based) positions of wanted elements in the queue. Return the minimal number of left and right shifts you'll have to perform to extract the wanted elements in the given order.

DEFINITION
Class:BidirectionalQueue
Method:extractElements
Parameters:int, vector <int>
Returns:int
Method signature:int extractElements(int N, vector <int> indices)


CONSTRAINTS
-N will be between 1 and 50, inclusive.
-indices will contain between 1 and N elements, inclusive.
-Each element of indices will be between 1 and N, inclusive.
-All elements of indices will be distinct.


EXAMPLES

0)
10
{1, 2, 3}

Returns: 0

The elements are extracted in the same order as they appear in the queue, so no shifts are required.

1)
10
{2, 9, 5}

Returns: 8

To extract the first wanted element, 1 left shift is required. After this the next wanted element will be 7th in a queue with 9 elements, so to extract it 3 right shifts are required. Finally, the last wanted element will be 5th in a queue with 8 elements, so either 4 left shifts or 4 right shifts are required.

2)
32
{27, 16, 30, 11, 6, 23}

Returns: 59



3)
10
{1, 6, 3, 2, 7, 9, 8, 4, 10, 5}

Returns: 14



*/
// END CUT HERE
#line 68 "BidirectionalQueue.cxx"
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

class BidirectionalQueue
{
	public:
	int extractElements(int N, vector <int> indices)
	{	 	 
        int cnt = 0;
        forv(i, indices)
        {
            int left = indices[i]-1, right = N-indices[i]+1;
            if(left-right<=0)
            {
                leftShift(N, indices, left);
                cnt += left;
            }
            else
            {
                rightShift(N, indices, right);
                cnt += right;
            }
            extractMin(N, indices);
        }
        return cnt;
	} 

    void extractMin(int& N, vector <int>& indices)
    {
        N--;
        forv(i, indices)
            indices[i]--;
    }

    void leftShift(const int N, vector <int>& indices, int steps)
    {
        forv(i, indices)
            indices[i] -= steps;
        forv(i, indices)
            if(indices[i] < 1)
                indices[i] += N;
    }

    void rightShift(const int N, vector <int>& indices, int steps)
    {
        forv(i, indices)
            indices[i] += steps;
        forv(i, indices)
            if(indices[i] > N)
                indices[i] -= N;
    }
        	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arr1[] = {1, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(0, Arg2, extractElements(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 10; int Arr1[] = {2, 9, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 8; verify_case(1, Arg2, extractElements(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 32; int Arr1[] = {27, 16, 30, 11, 6, 23}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 59; verify_case(2, Arg2, extractElements(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 10; int Arr1[] = {1, 6, 3, 2, 7, 9, 8, 4, 10, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 14; verify_case(3, Arg2, extractElements(Arg0, Arg1)); }

// END CUT HERE
 
}; 
// BEGIN CUT HERE 
int main()
{
	BidirectionalQueue ___test; 
        	___test.run_test(-1); 
}
// END CUT HERE 
