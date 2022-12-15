#include <iostream>
#include <type_traits>
using namespace std;
/* This is leetcode 226 - Invert Binary Tree
 * Difficulty: Easy. Type: Binary Tree 
 * Goal: Given the root of a binary tree, swap every right node with every left node.
 * Approach: Using recursion, swap the left and right nodes, then pass in right into the recursive call
 * and the left into a recursive call. Base case is when the current node is null, then return null.
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
	TreeNode* invertTree(TreeNode* root) {
		if(!root) return nullptr;
		swap(root->left,root->right);
		invertTree(root->right);
		invertTree(root->left);
		return root;
	}
};
int main ()
{
	
	return 0;
}
