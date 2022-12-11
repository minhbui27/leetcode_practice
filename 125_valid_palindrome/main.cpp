#include <cctype>
#include <iostream>
#include <string.h>
using namespace std;
/* This is leetcode question 125 - Valid Palindrome
* Difficulty: Easy. Type: Two Pointers
* Goal: Find if a string is a valid palindrome, that is it is the same forwards and backwards
*	Approach: Have one pointer pointing to the start of the string (i) and one to end of the string (j)
*	While the i pointer is less than j i.e they haven't met in the middle, do below:
* Increment i until the current character at i is alphanumeric, and decrement j until the same
* Make sure that there is an i < j in the inner while loop to deal with cases where there are only 2 chars
* If any comparison between i and j are false i.e it is already not a palindrome, then return false, true otherwise.
*/
class Solution {
	public:
		bool isPalindrome(string s) {
			int i = 0, j = s.length() - 1;
			while(i < j) {
				while(i < j && !isalnum(s[i])) i++;
				while(i < j && !isalnum(s[j])) j--;
				if(tolower(s[i++]) != tolower(s[j--])) return false;
			}
			cout << "true" << endl;
			return true;
  }
};
int main() {
  string s;
  getline(cin, s);
  Solution sol;
  sol.isPalindrome(s);
  return 0;
}
