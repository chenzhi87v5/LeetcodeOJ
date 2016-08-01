//Validate Binary Search Tree 验证二叉搜索树
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
// 中序遍历值存入数组，判定数组是否增序排列
class Solution {
public:
	 bool isValidBST(TreeNode* root) {
		if(root == NULL)
			return true;
		
		vector<int> result = inorderTraversal(root);  	  //中序遍历结果result
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
			while (p) {
				s.push(p);
				p = p->left;
			}
			p = s.top();
			s.pop();
			result.push_back(p->val); 
			p = p->right; 
		}
		return result;
	}
};

