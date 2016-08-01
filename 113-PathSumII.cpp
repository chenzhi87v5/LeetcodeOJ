//Path Sum II 二叉树路径之和之二
/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
	     / \
	    4   8
	   /   / \
	  11  13  4
	 /  \    / \
	7    2  5   1

return
[
  [5,4,11,2],
  [5,8,4,5]
]
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

//1-:本题求路径（所有）左子树求到满意结果不能return 还要继续求右子树 
class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> result;
		vector<int> path;   		//中间结果
		dfs (root, sum, path, result);
		return result;
	}

	void dfs(TreeNode* root, int sum, vector<int> &path, vector<vector<int>> &result ) {
		if (root == NULL)    //为空返回，剪枝
			return;
		
		path.push_back(root->val);   

		if (root->left == NULL && root->right == NULL) {    //为叶子节点判断是否等于sum 
			if(root->val == sum)
				result.push_back(path);
		}

		dfs(root->left, sum - root->val, path, result);    //左子树
		dfs(root->right, sum - root->val, path, result);    //右子树
		
		path.pop_back();
	}
};
