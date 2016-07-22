//Minimum Depth of Binary Tree 二叉树的最小深度
/*
Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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

/*二叉树的最小深度： 根 到 叶子节点 （最短的路径）
  与二叉树的最大深度不一样，在max 的时候就指定了是叶子节点;而最小深度min的时候可能是分支节点而不是叶节点
  递归版 时间复杂度n 空间复杂度logn
*/
class Solution {
public:
	int minDepth(TreeNode* root) {
		return minDepth(root, false);
	}
private:
	static int minDepth(const TreeNode* root, bool hasbrother) {
		if (!root)                             
			return hasbrother ? INT_MAX : 0;  	  //节点为空时如果有兄弟节点，则为父节点为分支节点
							  	  //该节点 下置为INT_MAX, 否则返回 0 父节点是叶子节点

		return 1 + min(minDepth(root->left, root->right != NULL),   //左分支
				minDepth(root->right, root->left != NULL));   //右分支
	}
};

//附上二叉树最大深度
int maxDepth(TreeNode* root) {
	if (!root) return 0;
	return 1 + max(maxDepth(root->left), maxDepth(root->right));
}
