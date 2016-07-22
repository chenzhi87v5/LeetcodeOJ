//Convert Sorted Array to Binary Search Tree 将有序数组转为二叉搜索树
/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST. 
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

//1-:二叉搜索树的构建 BST 高度平衡  二分法实现
class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		int len = nums.size();
		TreeNode *res = NULL;
		if (len == 0)
			return res;
		res = sortedArrayToBST(nums, 0, len - 1);	
		return res;
	}

	//递归法
	TreeNode* sortedArrayToBST(vector<int>& nums, int left, int right) {
		if (left > right)	//终止条件
			return NULL;

		int mid = (left + right) / 2;
		TreeNode* root = new TreeNode(nums[mid]);
		root->left = sortedArrayToBST(nums, left, mid - 1);
		root->right = sortedArrayToBST(nums, mid + 1, right);

		return root;
	}
};

