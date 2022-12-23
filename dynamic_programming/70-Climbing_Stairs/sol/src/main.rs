use std::io;
/*This is leetcode 70. Climbing Stairs
* Difficulty: Easy. Type: Dynamic Programming
* Goal: Given an integer n as an input, which represent the number of steps in a staircase, find
* the number of ways you can reach the top. For example n=2 -> output = 2 via 1+1 step or 2 steps.
* Approach: Using bottom up dynamic programming, first we have two base cases which are the last
* and second to last steps, these will always be 1 since there is one way to land on the last step
* and there is one way to go from the second to last to the last step. For example, n = 3 then
* steps 2 and 3 have values l and r as 1, since there is one way to land on 3 and one way to get
* from 2 to 3, then step 1 is the sum of steps 2 and 3, so 1+1 = 2. So there are two ways to get
* from 1 to 3, and then step 0 is 1+2=3 steps. So there are 3 ways to get from step 0 to 3.
*/
struct Solution;
impl Solution {
    pub fn climb_stairs(mut n: i32) -> i32 {
        let mut l: i32 = 1;
        let mut r: i32 = 1;
        while n > 1 {
            let temp: i32 = l;
            l = l + r;
            r = temp;
            n -= 1;
        }
        l
    }
}
fn main() {
    let mut input = String::new();
    io::stdin()
        .read_line(&mut input)
        .expect("Failed to read input");
    let input: i32 = input.trim().parse().expect("Input is not a valid integer");
    println!("n = {}", input);
    println!("the number of ways: {}", Solution::climb_stairs(input));
}
