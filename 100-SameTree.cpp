//Same Tree 判断相同树
/*
Given two binary trees, write a function to check if they are equal or not.
Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
*//**
  * Definition for a binary tree node.
  * struct TreeNode {
  *     int val;
  *     TreeNode *left;
  *     TreeNode *right;
  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  * };
  */
//递归版
class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q){
		if (!p && !q) return true; 	// 终止条件
		if (!p || !q) return false; 	// 剪枝(注意：均为空的情况上面已经排除了)
		return p->val == q->val 	// 三方合并
			&& isSameTree(p->left, q->left)
			&& isSameTree(p->right, q->right);
	}
};
