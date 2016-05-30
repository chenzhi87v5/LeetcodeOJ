/*
Invert a binary tree.

     4
   /   \
  2     7
 / \   / \
1   3 6   9

to
     4
   /   \
  7     2
 / \   / \
9   6 3   1

Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so fuck off.
*/

//

/**
  * Definition for a binary tree node.
  * struct TreeNode {
  *     int val;
  *     TreeNode *left;
  *     TreeNode *right;
  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  * };
  */

//反转二叉树
//简单的深度递归DFS

class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root == NULL)
			return root;
		
		TreeNode* tmp = root->left;
		root->left = root->right;
		root->right = tmp;
		
		root->left = invertTree(root->left);
		root->right = invertTree(root->right);

		return root;
	}
};
