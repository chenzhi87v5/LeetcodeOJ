/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/

/**
  * Definition for a binary tree node.
  * struct TreeNode {
  *     int val;
  *     TreeNode *left;
  *     TreeNode *right;
  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  * };
  */

//1-: 递归法  思想Important！！！！
//时间复杂度 n 空间复杂度logn 
class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (!root)
			return 0;

		return max(maxDepth(root->left), maxDepth(root->right)) + 1;  //简单精辟
	}
};
