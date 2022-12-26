#include <iostream>
/* This is leetcode 100. Same Tree
 * Difficulty: Easy. Type: Binary Tree
 * Goal: Given the root of two trees, find whether or not two trees are equivalent.
 * Approach: Two trees are equivalent iff for every right and left subtrees in the first one, the
 * equivalent right and left nodes on the other tree must contain the same value. Using recursion with
 * the base case of one or both nodes being null, return true if they are both null, false otherwise since
 * one node being null means that there doesn't exist an equivalent subtree at that node. Then, return
 * true of both of the values of the current nodes are equivalent AND the left nodes recursive call returns
 * true AND the recursive call for the right node returns true.
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
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if(!p || !q) return p == q;
		bool left = isSameTree(p->left, q->left);
		bool right = isSameTree(p->right, q->right);
		return p->val == q->val && left && right;
	}
};
int main ()
{
	
	return 0;
}
