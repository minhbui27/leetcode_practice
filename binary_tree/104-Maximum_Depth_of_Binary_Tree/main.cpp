#include <iostream>
using namespace std;
/* This is leetcode 104. Maximum Depth of the Binary Tree
 * Difficulty: Easy. Type: Binary Tree.
 * Goal: Given the root of a binary tree, find the depth, that is the longest path from the root to a leaf.
 * Approach: Pass the root into a recursive function called helper. The function helper will take in a reference
 * to max, a current value, and the next node. The base case for recursion is when we encounter a nullptr, then we return cur-1 since the nullptr doesn't count as a path. 
 * We recursively call this function in the left and right node each and every recursive call, then we return the max of the two.
 * This will ensure that the entire tree is subtree of every node is explored and max(left,right) will return the maximum depth from a child node to a leaf node.
*/
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
	int maxDepth(TreeNode* root) {
		int max = 0;
		max = helper(1, max, root);
		return max;
	}
	int helper(int cur,int &max,TreeNode* root) {
		if(!root) return cur-1;
		int left = helper(cur+1, max, root->left);
		int right = helper(cur+1, max, root->right);
		return max;
	}
};
int main ()
{
	
	return 0;
}
