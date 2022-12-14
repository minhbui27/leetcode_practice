/* Leetcode 167. Two Sum II, Input Array Is Sorted.
* Same implementation as my C++ program, using two pointers
* But this one is written in rust, therefore blazingly fast
*/
struct Solution;
impl Solution {
    pub fn two_sum(numbers: Vec<i32>, target: i32) -> Vec<i32> {
        let (mut i,mut j) = (0, numbers.len() -1 );
        while i < j {
            if numbers[i] + numbers[j] > target {
                j -= 1;
            } 
            else if numbers[i] + numbers[j] < target {
                i += 1;
            }
            else { return vec![(i as i32)+1,(j as i32)+1]; }
        }
        return vec![];
    }
}
fn main() {
    let target = 9;
    let numbers = vec![2,7,11,15];
    let output = Solution::two_sum(numbers,target);
    println!("{:?}",output);

}
