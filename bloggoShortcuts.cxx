// BEGIN CUT HERE
// PROBLEM STATEMENT
// 


You are helping to develop a weblog-management system called
bloggo. Although bloggo pushes all content to the front end of a
website in HTML, not all content authors enjoy using HTML tags in their
text. To make their lives easier, bloggo offers a simple syntax called
shortcuts to achieve some HTML textual effects. Your job is to
take a document written with shortcuts and translate it into proper HTML.




One shortcut is used to make italicized text. HTML does this with
the  and </igs, but in bloggo, an author can simply
enclose a piece of text using two instances of the underscore character,
'_'. Thus, where a content author writes




  You _should_ see the baby elephant at the zoo!



bloggo will publish the following instead.




  You should</ie the baby elephant at the zoo!



Another shortcut serves to render text in boldface, which HTML
accomplishes with  and </bgs. Bloggo lets content
authors do the same with paired instances of the asterisk character,
'*'. When a content author writes the text




  Move it from *Receiving* to *Accounts Payable*.



it will end up on the website as




  Move it from Receiving</b Accounts Payable</b

Given a string, text, containing zero or more usages
of the italic and boldface shortcuts, translate it into HTML
as demonstrated by the examples above. There will be an even number
of underscores and of asterisks in text, respectively, and the
spans of text enclosed by successive pairs of these characters will not
overlap. To render a span of text in italics in HTML, you must start
with the  tag and end with the </ig. For boldface
text, start with  and end with </bfter rendering all
shortcuts in HTML, return the resulting text as a string.




DEFINITION
Class:bloggoShortcuts
Method:expand
Parameters:string
Returns:string
Method signature:string expand(string text)


CONSTRAINTS
-text is between 1 and 50 characters long, inclusive
-the only characters allowed in text are the alphabetic characters 'a' to 'z' and 'A' to 'Z', the underscore '_', the asterisk '*', the space character, and the punctuation symbols ',', ';', '.', '!', '?', '-', '(', and ')'.
-the underscore '_' occurs in text an even number of times
-the asterisk '*' occurs in text an even number of times
-no substring of text enclosed by a balanced pair of underscores or by a balanced pair of asterisks may contain any further underscores or asterisks


EXAMPLES

0)
"You _should_ see the new walrus at the zoo!"

Returns: "You should</ie the new walrus at the zoo!"

A walrus is a large, blubbery cousin of the seal.

1)
"Move it from *Accounts Payable* to *Receiving*."

Returns: "Move it from Accounts Payable</b Receiving</b
Notice that a boldface span may enclose several words.

2)
"I saw _Chelydra serpentina_ in *Centennial Park*."

Returns: "I saw Chelydra serpentina</i Centennial Park</b
One piece of text may include italics as well as boldface.

3)
" _ _ __  _ yabba dabba _   *  dooooo  * ****"

Returns: "     yabba dabba      dooooo  "

Shortcuts may enclose spaces or nothing at all.

4)
"_now_I_know_*my*_ABC_next_time_*sing*it_with_me"

Returns: "nowIknowmyABCnexttimesingitwithme"

// END CUT HERE
#line 120 "bloggoShortcuts.cxx"
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

class bloggoShortcuts {
	public:
		string expand(string text) 
		{		
			string ret;
			bool iflag = false, bflag = false;
			forv(i, text)
			{
				if(text[i] == '_')
				{
					iflag = !iflag;
					ret += iflag ? "<i>" : "</i>";
				}
				else if(text[i] == '*')
				{
					bflag = !bflag;
					ret += bflag ? "<b>" : "</b>";
				}
				else
					ret += text[i];
			}
			return ret;
		}
};
