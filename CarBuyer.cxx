// BEGIN CUT HERE
// PROBLEM STATEMENT
// You wish to buy a new car and would like to get the cheapest option available. However, you recognize that the initial purchase cost is only a part of what you will need to spend on the car and you want to factor tax and fuel costs into your decision. You will be given a vector <string> cars giving the specifications of various models of car and an int annualDistance containing the distance that you will drive each year. For the car that you choose, the purchase cost only has to be paid once, the tax cost specific to the model has to be paid once per year and the fuel cost should be calculated as FUEL PRICE * DISTANCE DRIVEN / FUEL EFFICIENCY, where the fuel efficiency is specific to the car. You should calculate which car model in cars has the lowest cost on aggregate after years amount of time and return a double containing this cost.
Each element of cars will be formatted "<PURCHASE COST> <TAX> <FUEL EFFICIENCY>" (quotes for clarity).

DEFINITION
Class:CarBuyer
Method:lowestCost
Parameters:vector <string>, int, int, int
Returns:double
Method signature:double lowestCost(vector <string> cars, int fuelPrice, int annualDistance, int years)


NOTES
-The return value must be accurate to within an absolute or relative tolerance of 1e-9.


CONSTRAINTS
-cars will contain between 1 and 50 elements, inclusive.
-Each element of cars will contain between 5 and 15 characters, inclusive.
-Each element of cars will be formatted "<PURCHASE COST> <TAX> <FUEL EFFICIENCY>".
-Each <PURCHASE COST> will be an integer, without leading zeros, between 1 and 100000, inclusive.
-Each <TAX> will be an integer, without leading zeros, between 1 and 1000, inclusive.
-Each <FUEL EFFICIENCY> will be an integer, without leading zeros, between 1 and 100, inclusive.
-fuelPrice will be between 1 and 100, inclusive.
-annualDistance will be between 1 and 100000, inclusive.
-years will be between 1 and 100, inclusive.


EXAMPLES

0)
{"10000 50 50","12000 500 10","15000 100 65","20000 20 80","25000 10 90"}
2
5000
2

Returns: 10500.0

Here, fuel is cheap, you have a low annual mileage and you don't want to keep the car very long, so you go with the first model, which has the lowest purchase cost.

1)
{"10000 50 50","12000 500 10","15000 100 65","20000 20 80","25000 10 90"}
8
25000
10

Returns: 45200.0

This is the same set of cars, but this time fuel is far more expensive and you're going to keep the car for longer and drive it further. Now the more fuel-efficient fourth model is the cheapest.

2)
{"8426 774 19","29709 325 31","30783 853 68","20796 781 3"
,"27726 4 81","20788 369 69","17554 359 34","12039 502 24"
,"6264 230 69","14151 420 65","25115 528 70","22234 719 55"
,"2050 926 40","18618 714 29","173 358 57"}
33
8673
64

Returns: 254122.44444444444



// END CUT HERE
#line 67 "CarBuyer.cxx"
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

class CarBuyer {
	public:
		double lowestCost(vector <string> cars, int fuelPrice, int annualDistance, int years) 
		{		
			double lowest = -1;
			forv(i, cars)
			{
				int cost, tax, eff;
				sscanf(cars[i].c_str(), "%d %d %d", &cost, &tax, &eff);
				if(lowest == -1)
					lowest = cost + tax * years + double(fuelPrice) * annualDistance / eff * years;
				else
					lowest = min(lowest, cost + tax * years + double(fuelPrice) * annualDistance / eff * years);	
			}
			return lowest;
		}
};
