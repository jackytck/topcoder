// BEGIN CUT HERE
// PROBLEM STATEMENT
// One approach to voting is to have voters assign a rank to each candidate. Candidate A is preferred to candidate B if there are more voters who rank A ahead of B than there are voters who rank B ahead of A. A Condorcet winner is a candidate which is preferred to all other candidates. There can be at most one Cordorcet winner in an election, but there might also be none.

You will be given a vector <string> votes. The jth character of the ith element of votes is a lowercase letter, indicating the ranking that voter i assigned to candidate j. Letters closer to 'a' indicate higher-ranked (preferred) candidates, while those closer to 'z' are lower-ranked (less preferred). Return the 0-based index of the Cordorcet winner, or -1 if there isn't one.

DEFINITION
Class:CondorcetVoting
Method:winner
Parameters:vector <string>
Returns:int
Method signature:int winner(vector <string> votes)


CONSTRAINTS
-votes will contain between 1 and 50 elements, inclusive.
-Each element of votes will contain between 1 and 50 characters, inclusive.
-Each element of votes will contain the same number of characters.
-Each element of votes will contain only lowercase letters ('a' - 'z').


EXAMPLES

0)
{"acbd",
 "bacd",
 "bdca"}

Returns: 0

Voters 0 and 2 ranked candidate 0 higher than candidate 1, while voter 1 ranked candidate 1 higher than candidate 0.  Therefore, candidate 0 is preferred to candidate 1.

All three voters ranked candidate 0 higher than candidate 2, so candidate 0 is preferred to candidate 2.

Finally, voters 0 and 1 ranked candidate 0 higher than candidate 3, while only voter 2 ranked candidate 3 higher than candidate 0.  Therefore, candidate 0 is preferred to candidate 3 as well.

1)
{"abc", 
 "bca", 
 "cab"}

Returns: -1

This is a classic example of a cyclic preference. Two voters prefer 0 to 1, two prefer 1 to 2, and two prefer 2 to 0. There is no Condorcet winner.

2)
{"cezdqcw"}

Returns: -1

Even with only one voter, there may be no Condorcet winner because of a simple tie.

3)
{"abcd", "abcd", "abcd", "abcd", "abcd", "abcd",
 "cbad", "cbad", "cbad", "cbad", "cbad",
 "dbca", "cbda", "cbda"}

Returns: 1

Candidate 1 is nobody's first choice, but still wins.

4)
{"abbcbbbaaccaaccbbacbbbaacbccbccacaaacaacaaacbccaac",
 "accbabcaacacbcccbbccbbcaccccccbbcbbcbaccbcbcacbcbc",
 "acacaaabccaaaccabbaaaacabaaabacacbaacbcccbccbcbacb",
 "acbcbabaabbcaababaacbabcacbaccabbaaacccbcabbbcacba",
 "cbbbacbbacccbbabbbcbaabaaaacaacbcbccbaaccbcaaccbcb",
 "cbacbbcbbcbcaaabccabcabbcbacaaabccabbcbacbbacbbaca",
 "cacaabccbbbaaacccacbbcacababbcaaabccbbacbbbccacbaa",
 "bccbbabaaaababcbabbbbcbcacbcbcbacccacacacacacacaab",
 "bccabcaabcabbccaaccbcabaaabbbcaabaaabbbbabbbaabaac",
 "accccbabaaaabcbacabbcbbacaacaaaacccbbbcacaccccaaac",
 "cccbcaababbaacaaabbbaabbccccacaacbacaacbbbaacccbbb",
 "bccccaccbcbbaaaaaaaaccbababcabaaccacbbabbbcabbaaca",
 "cbacacaabbccacaabbbbbbccabcbbaccacbcacacacbccbcbcc",
 "baabcabccaaaaccbaacaaccacccbcbbaaacacaccbcaacbbbba",
 "bccaaaabcbbcbbbbbcaabaacccbccbbcbabacaaccbccaababb",
 "cacbbbbcabbcbaabbccbaccbaacbbcbbbbcabababccabbbcab",
 "bccbcacbccaacacccccaacabacbacbbbcaabacacccbbbccaac",
 "aaaccbbbacacbaaaacacaabbaacccbcccbcabbccbcacabbacb",
 "bcabcbbacbacacbbaaccabcabcbbaabacacccbbbcabbbcaacb",
 "bacbbbbaccbaabbbbbcaccbbcbcabbbccbcacccbabbbcaaacc",
 "bababcacbacacacccccbbcacccbbcbccaccaacbbcacabcabba",
 "aaabaccbbcacaacbabccccabbbcbcccccccbaacbccbaacbbbc",
 "abacbaaaaaccacbbbaccbbbabaacbcbccacccabaaaacbaabbb",
 "cbbcacbaccabbbcaacbcbabbcabcbaccabcbbbcabcbcbaacca",
 "babbacaaacbbcbbbabbaabcbabcbbaacaacbbbaaaabbcabcca",
 "cbabaacabcccaabbbacccaccbacabbaacaaabcbcccbcbcccaa",
 "aabbbcbacabbcabcbcccbccaccbcacbaacabbbccaabaabcbba",
 "caccabcccabbaacbabbaaaccccccccaaccbcaccacaabacccba",
 "bbbcabcababaabacaccacabcbccacccbbbbcbbbaccabcabaab",
 "bbbcaababbbbababababcbbbbaaabbacaabcacbbccbcaaaaaa",
 "bcbacccaaaabbcbcabbbcababbcacaabbbbcbbacbaabcbaccb",
 "bbcaccaaccacbbaaccaaaabccbbacbcbacaacbacbccaaccbba",
 "abaaacbccbbabbcaccbaccccbaaacaccccababcbccccbabcca",
 "acccaccababababacbbaccbcabcaccbabaabacbaacaaacabca",
 "aaabababccabccbcbabcabcacbbcacbcbbbabcabacbcaacacb",
 "ccacbaabbcbaccaccbbabbabbabaacccabcaaccacacccbbcab",
 "bbaabcbabbbaacacabaabcbaaabacbccccaccaaaacbacabbbc",
 "abaaaccaacbbcacacbcbccbaaacbbcbacabbbccabbbccaaaac",
 "bbacbabbcacbbacccaccbcbcabbcbaacabbbbabbaaabaacacb",
 "cacbacbccbcbabacccacabcacacabbcabbccaacacbaaacaacb",
 "bacbbacbccccabcbabcbbcbacacaaabcbaccccaabaabbacbcb",
 "abcaaccccabccaaaaccbabccacbcaaaacaccaccccccaaaabaa",
 "bacabcbccbacccbaaaabcbbaabbabaabcabacccbcabacccbcc",
 "babaccbbcbcbacccabccbcccbaaaaacccabcbccbbbbcbabcbc",
 "cccbbaccbabbbbcbcbcbaaacbbcacbcaacacacccbcabccbcaa",
 "caacbcacbccaaaaacaaababbcccacbabaaabcaacaaababacba",
 "cccccaccabcaacababbacbcbabbcaacbacbabbbccbabcbabbb",
 "ccbcababcabcbcccaccccacabcbaaacaabccbbaabaccbaccab",
 "abbbcacaccabcbccbacabbbccaccaaaacccabbcbacbbccabcb",
 "bacabccabcbbcaacbcacabcbccacbcccbcbcaaaabbaabccabb"}

Returns: 12



5)
{"h", "e", "l", "l", "o"}

Returns: 0



// END CUT HERE
#line 127 "CondorcetVoting.cxx"
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
#define For(i, st, en) for(__typeof(en) i = (st); i < (en); i++)

using namespace std;

class CondorcetVoting {
	public:
		int winner(vector <string> votes) 
		{		
			int win = -1;
			forn(i, votes[0].sz)
			{
				int r = 0;
				forn(j, votes[0].sz)
				{
					if(i == j) continue;
					int gd = 0, bad = 0;
					forn(k, votes.sz)
					{
						if(votes[k][j] > votes[k][i])
							gd++;
						else if (votes[k][j] < votes[k][i])
							bad++;
					}
					if(bad >= gd) break;
					else
						r++;
				}
				if(r == votes[0].sz - 1)
					win = i;
			}
			return win;
		}
};
