#include <iostream>
#include <vector>
using namespace std;
/* This is leetcode problem 20 - Binary Search
 * Difficulty: Easy. Type: Binary Search
 * Goal: Given an array of integers with ascending order, find the index of the target, -1 if DNE
 * Approach: Create two pointers to the start and end of the array and while loop until start < end + 1 
 * (to account for the value at the end).
 * If the target is bigger than the current center, then set the start to center + 1 and keep the end
 * If the target is smaller than the current center, then set the end to center - 1 and keep the start
 * If the value at the center is equal to target then return the index of the center.
 * This will keep dividing the array in half until those two pointers are equal, and if no such return is made,
 * then return -1 at the end of the loop.
 *
 * The problem requires an O(log(n)) algorithm, which this achieves
*/
class Solution {
public:
	int search(vector<int>& nums, int target) {
		int i = 0,j = nums.size() - 1;
		while(i < j + 1) {
			int mid = (j+i)/2;
			if(nums[mid] < target) {
				i = mid + 1;
			}
			else if(nums[mid] > target) {
				j = mid - 1;	
			}
			else return mid;
		}
		return -1;
	}
};
int main ()
{
	vector<int> nums = {-1,0,3,5,9,12};
	int target;
	cin >> target;
	Solution s;
	cout << s.search(nums,target) << endl;
	return 0;
}
