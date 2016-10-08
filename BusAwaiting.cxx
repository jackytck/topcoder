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

using namespace std;

class BusAwaiting
{
	public:
		int waitingTime(vector <string>, int);
};

int BusAwaiting::waitingTime(vector <string> buses, int arrivalTime) 
{
	bool first = true;
	int minWait = -1;
	for(int i = 0; i < buses.size(); i++)
	{
		int result = -1, wait, j;
		istringstream in(buses[i]);
		int start, interval, count;
		in>>start>>interval>>count;
		for(j = 0; j < count; j++)
		{		
			if(start + j * interval >= arrivalTime)
				{
					result = 1;
					break;
				}
		}
		if(result != -1)
		{
			wait = start + j * interval - arrivalTime;
		
			if(first)
			{
				minWait = wait;
				first = false;
			}
			if(wait < minWait)
			{
				minWait = wait;
			}
		}
	}
	return minWait;
}
