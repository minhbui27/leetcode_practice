#include <iostream>
#include <map>
#include <stack>
#include <string.h>
using namespace std;
/* This is leetcode problem	20 - Valid parentheses
 * Difficulty: Easy. Type: Stack
 * Goal: Given a string of (),{},[], any combination, find whether it is valid, that is
 * every opening is properly closed.
 * Approach: Use map to map each closing to opening braces. Use a stack to track what is the current
 * opening brace that needs to be closed properly. If stack is empty of the current char is an opening
 * char, then add it to the stack. If it isn't then compare the current char to see if it matches its opening pair
 * if it isn't then return false, and if it is then pop the current top to move on to the next pair.
 * The return will be whether or not the stack is empty. If it isn't empty that means there is at least an extra pair of
 * opening that wasn't matched with a corresponding closing pair correctly
*/
class Solution {
public:
  bool isValid(string s) {
    if (s.length() < 2)
      return false;
    map<char, char> m;
    m[']'] = '[';
    m['}'] = '{';
    m[')'] = '(';
    stack<char> r;
    for (char c : s) {
      if (r.empty() || c == '{' || c == '[' || c == '(') {
        r.push(c);
      } else {
				if(m[c] != r.top()) return false; 
				r.pop();
      }
    }
    return r.empty();
  }
};
int main() {
  string in;
  cin >> in;
  Solution s;
  cout << s.isValid(in) << endl;
  return 0;
}
