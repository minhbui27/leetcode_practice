use std::io;
struct Solution;
impl Solution {
    pub fn search(nums: Vec<i32>, target: i32) -> i32 {
        let (mut l, mut r) = (0, nums.len() - 1);
        while l <= r {
            let mid = (l + r) / 2;
            if nums[mid] == target {
                return mid as i32;
            } else if ((nums[0] <= target) && (target < nums[mid]))
                || (target < nums[mid]) && (nums[mid] < nums[0])
                || (nums[mid] < nums[0]) && (nums[0] <= target)
            {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return -1;
    }
}
fn main() {
    let mut input = String::new();
    io::stdin()
        .read_line(&mut input)
        .expect("failed to read line");
    let target: i32 = input.trim().parse().expect("input is not an integer");
    let nums = vec![4, 5, 6, 7, 0, 1, 2];
    println!("index of {} is: {}", target, Solution::search(nums, target));
}
