// BEGIN CUT HERE
// PROBLEM STATEMENT
// There are several empty containers lined up in a row, and you want to put packages into them. You start with the first container and the first package. Do the following until all the packages are inside containers:


If the current package cannot fit into the current container, skip to step 3. Otherwise, go to the next step.
Put the current package into the current container. Grab the next  package, and go back to step 1.
Put the current container aside (you will not put any more packages into that container). Move on to the next container in line, and go back to step 1.


You are given a vector <int> containers, the i-th element of which is the capacity of the i-th container in line, and a vector <int> packages, the i-th element of which is the size of the i-th package. The constraints will guarantee that you will be able to put all the packages into containers using the above procedure. Return the sum of the wasted space in all the containers. The wasted space in a container is its capacity minus the total size of its contents.

DEFINITION
Class:Containers
Method:wastedSpace
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int wastedSpace(vector <int> containers, vector <int> packages)


NOTES
-A set of packages fits into a container if the total size of all the packages in the set does not exceed the capacity of the container.
-You must use the containers and the packages in the order that they are given. You may not reorder them.


CONSTRAINTS
-containers will contain between 1 and 50 elements, inclusive.
-Each element of containers will be between 1 and 1000, inclusive.
-packages will contain between 1 and 50 elements, inclusive.
-Each element of packages will be between 1 and 1000, inclusive.
-It will be possible to put all the packages inside containers using the method described in the statement.


EXAMPLES

0)
{ 5, 5, 5 }
{ 5, 5, 5 }

Returns: 0

Here, we've got 3 packages of size 5 and 3 containers of size 5, so no space will be wasted.

1)
{ 5, 6, 7 }
{ 5, 5, 5 }

Returns: 3

All the packages are of size 5. We will put the first package into the container of size 5, the second package into the container of size 6 and the third into the container of size 7. The overall wasted space will be equal to (5 - 5) + (6 - 5) + (7 - 5) = 3.

2)
{ 2, 3, 5 }
{ 3 }

Returns: 7

Here, we've got only one package of size 3. First, we'll try to put it into the container of size 2, but it won't fit, so we'll put it into the second container, leaving the third untouched. The overall wasted space will be 2 + (3 - 3) + 5 = 7.

3)
{ 3, 4, 5, 6 }
{ 3, 3, 3, 3, 3 }

Returns: 3



// END CUT HERE
#line 70 "Containers.cxx"
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

class Containers {
	public:
		int wastedSpace(vector <int> containers, vector <int> packages) 
		{		
			return accumulate(containers.begin(), containers.end(), 0) - accumulate(packages.begin(), packages.end(), 0);
		}
};
