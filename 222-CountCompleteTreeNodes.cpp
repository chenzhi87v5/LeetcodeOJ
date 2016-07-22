//Count Complete Tree Nodes 求完全二叉树的节点个数
/*
Given a complete binary tree, count the number of nodes.
Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
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

//如果从某节点一直向左的高度 = 一直向右的高度, 那么以该节点为root的子树一定是满二叉树. 而满二叉树的节点数,可以用公式算出 2^h - 1. 如果高度不相等, 则递归调用 return countNode(left) + countNode(right) + 1.  复杂度为O(h^2)
//pow( , ) 数学计算公式n^m
class Solution {
public:
	int countNodes(TreeNode* root) {
		if (root == NULL) 
			return 0;

		TreeNode* lt = root;
		TreeNode* rt = root;
		int leftdepth = 0;
		int rightdepth = 0;
		
		while (lt) {          		//计算树的深度
			leftdepth++;
			lt = lt->left;
		}
		while (rt) {
			rightdepth++;
			rt = rt->right;
		}
		
		if (leftdepth == rightdepth) {   
			return pow(2, leftdepth) - 1;   //满二叉树计算节点公式
		} else {
			return countNodes(root->left) + countNodes(root->right) + 1;
		}
	}
};
