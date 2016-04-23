/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
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

//1-: 递归
class Solution {
public:
	bool isBalanced(TreeNode* root) {	
		return depth(root) != -1;
	}

	int depth(TreeNode *root) {
		if (root == NULL)            //为空返回0
			return 0;

		int left = depth(root->left);      //左子树深度
		int right = depth(root->right);    //右子树深度

		if (left == -1 || right == -1 || abs(left - right) > 1)  //剪枝条件
			return -1;

		return max(left, right) + 1;   //否则就返回最大深度
	}
};
