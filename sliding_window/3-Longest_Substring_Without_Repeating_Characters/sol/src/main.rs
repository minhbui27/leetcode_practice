use std::cmp;
/* This is leetcode 3. Maximum Length of Substring without repeating characters
* Difficulty: Medium. Type: Sliding Window.
* Goal: Given a string of chars, output the maximum length of a substring that has no repeating
* characters.
* Approach: Create a start variable as -1. Create a map of size greater than the amount of
* characters that are permitted in the string. This array will store the index of each character in
* the string.
* Then, loop through the string and if the current character has index greater than start, then set
* the start to that index, this means that the character already exists or we are at the beginning
* of the iteration.
* Then, set the index of the character to the mapping in the array. On the next iteration, the
* start will be changed to a repeated character if a mapping already exists. Note that the map is
* updated with every character, but if a mapping already exists, then it must be greater than the
* current start because start is equal to the index of the previous occurence of the current
* repeated character.
*/
struct Solution;
impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut max: i32 = 0;
        let mut start:i32 = -1;
        let mut m: [i32;256] = [0;256];
        let s: Vec<char> = s.chars().collect();
        for i in 0..s.len() {
            if m[s[i] as usize] > start {
                start = m[s[i] as usize];
            }
            m[s[i] as usize] = i as i32;
            max = cmp::max(max,i as i32 - start);
        }
        max
    }
}
fn main() {
    let input = String::from("abcabcbb");
    let output:i32 = Solution::length_of_longest_substring(input);
    println!("max length of substring = {}",output);
}
