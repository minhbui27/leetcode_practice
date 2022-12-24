#include <algorithm>
#include <iostream>
/* This is leetcode 542. Diameter of Binary Tree
 * Difficulty: Easy. Type: Binary Tree.
 * Goal: Given the root of a binary tree, find the diameter of the tree, that is the length
 * of the longest path of one node to another node.
 * Approach: Using recursion, perform a depth first search while updating the diameter value. With every
 * iteration of the recursive loop, set the diameter to the max of the current diameter and the lengths left+right.
 * Then, return max of left and right + 1 (to account for the current root) as the result of the recursive loop.
 * With this approach, we will find the longest path as the sum of the depth of each and every left and right subtrees.
 * Then we return the max of the left and right as the output of the recursive function, and this will be evaluated
 * by the top node to determine if this longest path + another unexplored path is longer than the diameter.
*/
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
	int diameterOfBinaryTree(TreeNode* root) {
		int diameter = 0;
		return dfs(root,diameter);
	}
	int dfs(TreeNode* root, int &diameter) {
		int left = dfs(root->left,diameter);
		int right = dfs(root->right,diameter);
		diameter = std::max(left+right,diameter);
		return std::max(left,right) + 1;
	}
};
int main ()
{
	
	return 0;
}
