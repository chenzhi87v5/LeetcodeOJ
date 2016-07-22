//Path Sum 二叉树的路径和
/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
	     / \
	    4   8
           /   / \
	  11  13  4
	 /  \      \
	7    2      1
	
	return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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
//只返回一个结果，不需要记录路径，同时必须要走到叶子节点才能判断，因此中途没法剪枝，只能进行朴素深搜
class Solution {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		if (root == NULL)
			return false;
		if (root->left == NULL && root-> right == NULL)  	//叶节点判断
			return sum == root->val;

		return hasPathSum(root->left, sum - root->val)    	//左右分支任意一个满足即可
			|| hasPathSum(root->right, sum - root->val);
	}
};
