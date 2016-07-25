//Sum Root to Leaf Numbers 求根到叶节点数字之和
/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
An example is the root-to-leaf path 1->2->3 which represents the number 123.
Find the total sum of all root-to-leaf numbers.
For example,

    1
   / \
  2   3

The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
	 Return the sum = 12 + 13 = 25.
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
//1-:二叉树的递归 递归思想
/*
这道求根到叶节点数字之和的题跟之前的求Path Sum 二叉树的路径和很类似，都是利用DFS递归来解，这道题由于不是单纯的把各个节点的数字相加，
而是每到一个新的数字，要把原来的数字扩大10倍之后再相加。代码如下： 
*/
class Solution {
public:
	int sumNumbers(TreeNode* root) {
		return dfs(root, 0);
	}
private:
	//递归
	int dfs(TreeNode *root, int sum) {
		if (root == NULL)   
			return 0;

		if (root->left == NULL && root->right == NULL)   //到达叶子节点返回值
			return sum * 10 + root->val;

		//左右继续递归
		return dfs(root->left, sum * 10 + root->val) 
			+ dfs(root->right, sum * 10 + root->val);
	}
};
