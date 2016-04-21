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

//1-:二叉搜索树的构建 BST 高度平衡
//二分法实现
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

//法二：
class Solution {
public:
	TreeNode* sortedArrayToBST (vector<int>& num) {
		return sortedArrayToBST(num.begin(), num.end());
	}
	
	template<typename RAIterator>
	TreeNode* sortedArrayToBST (RAIterator first, RAIterator last) {
		const auto length = distance(first, last);
		if (length <= 0) 
			return nullptr; // 终止条件
		
		// 三方合并
		auto mid = first + length / 2;
		TreeNode* root = new TreeNode (*mid);
		root->left = sortedArrayToBST(first, mid);
		root->right = sortedArrayToBST(mid + 1, last);
		return root;
	}
};
