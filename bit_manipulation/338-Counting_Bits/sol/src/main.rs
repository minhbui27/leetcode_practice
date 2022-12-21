use std::io;
/* This is leetcode 338 - Counting Bits
* Difficulty: Easy. Type: Bit Manipulation.
* Goal: Given a integer input, output a vector of size n+1 where each index represents the number
* of bits its required to represent that index. Example: input = 5 -> output = [0,1,1,2,1,2].
* Approach: Every integer power of 2 will require 1 bit to represent. All those integers
* multiplied by 2 will also only require the same 1 bit to represent, such as 2,4,8,16. All
* integers that are even but not a power of 2 such as 6 or 10 will require the same amount of bits
* needed to represent that integer divided by 2 since they are only the same bits shifted left by
* 1. For example 6 = 3*2 or 12 = 6*2. Odd integers will require the same amount of bits as that
* integer/2 + that integer % 2. This is the case because you only need to add 1 to round (n/2)*2 to
* n since n/2 will round down as n is an integer.
*/
struct Solution;
impl Solution {
    pub fn count_bits(n: i32) -> Vec<i32> {
        let mut output: Vec<i32> = vec![0;(n + 1) as usize];
        for i in 1..(n + 1) {
            output[i as usize] = output[i as usize/2] + i%2;    
        }
        output
    }
}
fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Failed to read input");
    let input:i32 = input.trim().parse().expect("Input is not an integer");
    println!("{:?}",Solution::count_bits(input));
}
