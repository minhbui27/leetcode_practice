#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
/* This is leetcode problem 121 - Best time to buy or sell stock
 * Difficulty: Easy. Type: Sliding window 
 * Goal: Given an array of integers, find the maximum profit, that is buying 
 * a stock with value i and selling with value i...n. If the array is decreasing, then
 * no profit could be made, since buying from index i and selling at index i...n would not yield
 * positive profit. Same for vector of size 1, can buy but cannot sell -> no profit
 * Approach: Create a sliding window that starts has two points i and j, starting at 0 and i + 1.
 * Increment j while calculating if j - i exceeds current max, then update. If j is less than i, then
 * set i to j, and j++, this is logical since if j is lesser than i, then even if there is a larger number
 * later, buying j will always be a better deal.
*/
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if(prices.size() < 2) return 0;
		int cur = 0;
		int i = 0, j = i + 1;	
		while(j < prices.size()) {
			if(prices[i] > prices[j])	{
				i = j;
			}
			else {
				cur = max(cur,prices[j] - prices[i]);
			}
			j++;
		}
		return cur;
	}
};
int main ()
{
	vector<int> input = {7,6,4,3,1};
	Solution s;
	cout << s.maxProfit(input) << endl;
	return 0;
}
