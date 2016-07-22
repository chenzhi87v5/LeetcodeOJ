//Binary Tree Preorder Traversal 二叉树的先序遍历
/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3

   return [1,2,3].
Note: Recursive solution is trivial, could you do it iteratively?
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
//1-:递归法很简单(Easy)
//2-:迭代法 使用栈
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> result;
		const TreeNode *p;
		stack<const TreeNode *> s;

		p = root;
		if (p != NULL)
			s.push(p);

		while (!s.empty()) {
			p = s.top();
			s.pop();
			result.push_back(p->val);    //访问节点值

			if (p->right != NULL)        //右子树入栈
				s.push(p->right);
			if (p->left != NULL)          //左子树入栈
				s.push(p->left);
		}
		return result;
	}
};
