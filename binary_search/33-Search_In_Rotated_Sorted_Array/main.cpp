#include <iostream>
#include <vector>
using namespace std;
/* This is leetcode 33. Search in Sorted and Rotated Array
 * Difficulty: Medium. Type: Binary Search
 * Goal: Given a strictly increasing array, with a possibility of being rotated. That is
 * every values before the pivot will end up at the end of the array. Find the index of a given target
 * Approach: Use regular binary search, but keep track of the pivot and the cases where we need to take the
 * left subarray, other cases we will take the right subarray. (Cases are explained in the comments in the implementation)
*/
class Solution {
public:
	int search(vector<int>& nums, int target) {
		int l = 0, r = nums.size() - 1;	
		while(l <= r) {
			int mid = (l + r)/2;
			cout << nums[mid] << endl;
			if(nums[mid] == target) return mid;
			// First case: If nums[0] <= target < mid, then take the left subarray, this is such case where 
			// from nums[0] to mid is sorted like normal
			else if(((nums[0] <= target) && (target < nums[mid])) 
			// Second case: If target < mid < nums[0], then take the left subarray. If mid is smaller than nums[0], then
			// every number after mid is strictly lesser than nums[0]. target < mid means it is index of target >= index of pivot.
			// and it has to be to the left of mid.
					|| (target < nums[mid]) && (nums[mid] < nums[0]) 
			// Third case: If mid < nums[0] < target. If mid < nums[0], then everything to the right is strictly smaller than nums[0]
			// similar to the second case. If target is then greater than nums[0], then that means index of target < index of pivot.
					|| (nums[mid] < nums[0]) && (nums[0] <= target)) {
					r = mid - 1;
			}
			else l = mid + 1;
		}
		return -1;
	}
};
int main ()
{
	vector<int> input = {4,5,6,7,0,1,2};
	int target;
	cin >> target;
	Solution s;
	s.search(input, target);
	return 0;
}	
