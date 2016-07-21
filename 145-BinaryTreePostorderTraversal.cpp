//Binary Tree Postorder Traversal 二叉树的后序遍历
/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
     /
    3
    
    return [3,2,1].

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

/*
经典题目，求二叉树的后序遍历的非递归方法，跟前序，中序，层序一样都需要用到栈，后续的顺序是左-右-根，所以当一个节点值被取出来时，它的左右子节点要么不存在，要么已经被访问过了。具体思路可参见神网友 Yu's Coding Garden 的博客，代码如下： 
*/
class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> result;
		stack<TreeNode*> stk;
		if (!root)
			return result;
		stk.push(root);
		TreeNode* head = root;
		while (!stk.empty()) {
			TreeNode* top = stk.top();
			if ((!top->left && !top->right) || top->left == head || top->right == head ){
				result.push_back(top->val);
				stk.pop();
				head = top;
			} else {
				if (top->right){
					stk.push(top->right);
				}	
				if (top->left) {
					stk.push(top->left);
				}
			}
		}
		return result;
	}
};
