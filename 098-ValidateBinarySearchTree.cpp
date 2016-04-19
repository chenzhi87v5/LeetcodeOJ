/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

	The left subtree of a node contains only nodes with keys less than the node's key.
	The right subtree of a node contains only nodes with keys greater than the node's key.
	Both the left and right subtrees must also be binary search trees.
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


//1-:递归检查节点值是否在合法范围内
/*  LeetCode 已结更新 通过不了 加入了新的节点值 INT_MIN INT_MAX
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		bool res = isValidBST(root, INT_MIN, INT_MAX);    //INT_MIN, INT_MAX 用的精辟
		
		return res;
	}
private:
	//递归判定node val值是否在lower 与 upper之间
	bool isValidBST(TreeNode* root, int lower, int upper) {
		if (root == NULL)
			return true;
		
		return (root->val > lower) && (root->val < upper)
			&& isValidBST(root->left, lower, root->val)
			&& isValidBST(root->right, root->val, upper);
	}
};
*/


//2-: 中序遍历值存入数组，判定数组是否增序排列
class Solution {
public:
	 bool isValidBST(TreeNode* root) {
		if(root == NULL)
			return true;
		
		vector<int> result = inorderTraversal(root);  //中序遍历结果result
		for(int i = 0; i < result.size(); i++) {          //判定结果完全升序排列 注意 是 '<='
			if (i > 0 && result[i] <= result[i - 1])
				return false;
		}

		return true;
	}
private:
	//中序遍历 迭代法
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;
		const TreeNode *p = root;
		stack<const TreeNode *> s;
	
		while (!s.empty() || p != NULL) {
			if (p != NULL) {
				s.push(p);
				p = p->left;
			} else {
				p = s.top();
				s.pop();
				result.push_back(p->val); 
				p = p->right; 
			}
		}

		return result;
	}
};

