//Binary Tree Paths 二叉树路径

/*Given a binary tree, return all root-to-leaf paths.
For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
 
All root-to-leaf paths are:
["1->2->5", "1->3"]
*//**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*这道题给我们一个二叉树，让我们返回所有根到叶节点的路径，跟之前那道Path Sum II 二叉树路径之和之二很类似，比那道稍微简单一些
，不需要计算路径和，只需要无脑返回所有的路径即可，那么思路还是用DFS来解，代码而很简洁，参见如下:*/

class Solution {
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> res;
		if (root) dfs(root, "", res);
		return res;
	}
	void dfs(TreeNode *root, string out, vector<string> &res) {
		out += to_string(root->val);
		if (!root->left && !root->right) 
			res.push_back(out);
		else {
			 if (root->left) dfs(root->left, out + "->", res);
			 if (root->right) dfs(root->right, out + "->", res);
		}
	}
};
