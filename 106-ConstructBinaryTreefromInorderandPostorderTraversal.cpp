/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
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

//1-:中序遍历 与 后序遍历 构建二叉树
//递归法
//STL : prev() An iterator to the element n positions before it.
class Solution {
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		return buildTree(begin(inorder), end(inorder), begin(postorder), end(postorder));
	}

	//递归
	template<typename BidiIt>
	TreeNode* buildTree(BidiIt in_first, BidiIt in_last, BidiIt post_first, BidiIt post_last) {
		if (in_first == in_last)
			return NULL;
		if (post_first == post_last)
			return NULL;

		const auto val = *prev(post_last);
		TreeNode *root = new TreeNode(val);

		auto in_root_pos = find(in_first, in_last, val);   //关键点
		auto left_size = distance(in_first, in_root_pos);
		auto post_left_last = next(post_first, left_size);
		
		root->left = buildTree(in_first, in_root_pos, post_first, post_left_last);
		root->right = buildTree(next(in_root_pos), in_last, post_left_last, prev(post_last));
		
		return root;
	}
};
