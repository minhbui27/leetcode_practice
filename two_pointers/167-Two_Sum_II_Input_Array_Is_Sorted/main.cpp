#include <iostream>
#include <vector>
using namespace std;
/* This is leetcode problem 167 - Two Sum II, Input Array Is Sorted
 * Difficulty: Medium. Type: Two Pointers 
 * Goal: Given an input array of non-decreasing integers and a target, find the index of two indices where the values 
 * add up to be equal to the target. It is guaranteed to have only one solution.
 * Approach: Since the array is sorted, place two pointers at the start and end.
 * If the sum of the two pointers is more than the target, then decrement the j pointer, this decreases the current sum
 * If the sum is less than the target, then increment the i pointer, this increases the current sum.
 * i++ and j-- until we reach the end, that is i = j. If at any point i + j = target, then return and break. If not, then
 * an empty vector will be returned.
*/
class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int i = 0, j = numbers.size() - 1;
		while(i < j) {
			if(numbers[j] + numbers[i] > target) j--;
			else if(numbers[j] + numbers[i] < target) i++;
			else return vector<int> {i + 1, j + 1};
		}
		return {};
	}
};
int main()
{
	vector<int> input = {2,7,11,15};
	int target;
	cin >> target;
	Solution s;	
	vector<int> output = s.twoSum(input, target);
	for(int i : output) cout << i << endl;
	return 0;
}
