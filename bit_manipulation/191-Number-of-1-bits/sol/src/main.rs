use std::io;
/* This is leetcode 191. Number of 1 bits
* Goal: Given an unsigned 32 bit integer, output the number of 1 bits in the binary representation
* Approach: Using the bitwise and operator with 0000...0001, shift left logical until the input is
* 0 and every iteration add 1 to the count of logical and returns 1.
*/
struct Solution;
impl Solution {
    pub fn hammingWeight(n: u32) -> i32 {
        let mut count:i32 = 0;  
        let mut num = n;
        while num != 0 {
            count += (num & 1) as i32;
            num >>= 1;
        } 
        count
    }
}
fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Cannot read the input");
    let input:u32 = input.trim().parse().expect("Input is not integer");
    println!("The number of 1's are: {}", Solution::hammingWeight(input));
}
