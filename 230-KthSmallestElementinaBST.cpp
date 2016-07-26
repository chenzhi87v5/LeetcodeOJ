//Kth Smallest Element in a BST 二叉搜索树中的第K小的元素
/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
Note: 
	You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
Follow up:
	What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? 
      How would you optimize the kthSmallest routine?
Hint:
	Try to utilize the property of a BST.
	What if you could modify the BST node's structure?
	The optimal runtime complexity is O(height of BST).
*//**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//利用二叉树的特性进行求解
/*
在二叉搜索树种，找到第K个元素。
算法如下：
1、 计算左子树元素个数left。
2、 left+1 = K，则根节点即为第K个元素
    left >=k,   则第K个元素在左子树中
    left +1 <k, 则转换为在右子树中，寻找第K-left-1元素
*/
class Solution {
public:
	int calcTreeSize(TreeNode* root) {   //计算二叉树节点个数
		if (root == NULL)
			return 0;
		return 1 + calcTreeSize(root->left) + calcTreeSize(root->right);
	}

	int kthSmallest(TreeNode* root, int k) {
		if (root == NULL)
			return 0;
		int leftSize = calcTreeSize(root->left);
		if (k == leftSize + 1) {
			return root->val;
		} else if (leftSize >= k) {
			return kthSmallest(root->left, k);
		} else {
			return kthSmallest(root->right, k - leftSize - 1);
		}
	}
};
