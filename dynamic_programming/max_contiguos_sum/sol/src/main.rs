use std::io;
use std::cmp;
struct Solution;
impl Solution {
    pub fn vec_max(input: Vec<i32>) -> i32 {
        let mut max = 0;
        for i in input {
            max = cmp::max(max,i);
        }
        max
    }
    pub fn max_contiguous_sum(input: Vec<i32>) -> i32 {
        let mut output: Vec<i32> = vec![0,input.len().try_into().unwrap()];
        output[0] = 0;
        for i in 1..input.len() {
            output[i] = input[i];
            if output[i-1] > 0 {
                output[i] = input[i] + output[i-1];
            }
        }
        Solution::vec_max(output) 
    }
}
fn main() {
    let input: Vec<i32> = vec![5,15,-30,10,-5,40,10];
    println!("{:?}",Solution::max_contiguous_sum(input));
}
