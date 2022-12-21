/* This is leetcode 15. 3Sum
* Difficulty: Medium. Type: Two Pointers
* Goal: Given a vector of integers, output a vector of triplets that contains values in the
* original vector which adds up to 0.
* Approach: First sort the array. Then using the two pointer approach, loop through the input
* array, for each element in the input array, if the previous element is the same, then skip,
* because this means the value at i has been evaluated by i-1.
* Create pointers l and r, pointing to the next element i+1 and the end of the vector. Since the
* array is sorted, increase l and r accordingly to increase or decrease the current sum. 
* If i + l + r = 0, then push those values as a triplet to the output. Then increment l and
* decrement r until nums[l] and nums[r] are not the same value as the l and r that was used to push
* to the output. This is because we cannot have duplicates.
*/
struct Solution;
impl Solution {
    pub fn three_sum(mut nums: Vec<i32>) -> Vec<Vec<i32>> {
        nums.sort();
        let mut output: Vec<Vec<i32>> = vec![];
        for i in 0..nums.len() {
            if nums[i] > 0 { break; }
            if (i as i32) > 0 && nums[i] == nums[i-1] { continue; }
            let mut l = i+1;
            let mut r = nums.len() - 1;
            while l < r {
                let sum: i32 = nums[i] + nums[l] + nums[r];
                if sum < 0 { l+=1; }
                else if sum > 0 { r-= 1; }
                else {
                    output.push(vec![nums[i],nums[l],nums[r]]);
                    let last_l = nums[l];
                    let last_r = nums[r];
                    while l < r && last_l == nums[l] { l+= 1; }
                    while l < r && last_r == nums[r] { r-= 1; }
                }
            }
        }
        return output;
    }
}
fn main() {
    let nums: Vec<i32> = vec![-1, 0, 1, 2, -1, -4];
    let output = Solution::three_sum(nums);
    println!("{:?}",output);
}
