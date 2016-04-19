/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3

   return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
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

//1-: 递归法，题目要求使用迭代法（即非递归）
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;
		if (root == NULL)
			return result;
		inOrder(root, result);

		return result;
	}
private:
	void inOrder(TreeNode* root, vector<int>& result) { //递归法 可以改变实现先序，后序遍历
		if (root != NULL){
			inOrder(root->left, result);
			result.push_back(root->val);
			inOrder(root->right, result);
		}
	}
};

//2-:迭代法实现中序遍历
//使用栈，时间复杂度n, 空间复杂度n                -------------改变程序可实现先序遍历及后序遍历
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;
		const TreeNode *p = root;  //p 是指向const TreeNode 的指针
		stack<const TreeNode *> s;    //栈的元素是const TreeNode * 指针

		while (!s.empty() || p != NULL) {
			if (p != NULL) {
				s.push(p);                 //入栈
				p = p->left;               //左子树
			} else {
				p = s.top();                //取栈顶元素
				s.pop();                    //删除栈顶元素
				result.push_back(p->val);     //访问val
				p = p->right;                //右子树
			}
		}

		return result;
	}
};





