//Binary Search Tree Iterator 二叉搜索树迭代器
/*
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
Calling next() will return the next smallest number in the BST.
Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
*/
/**
  * Definition for binary tree
  * struct TreeNode {
  *     int val;
  *     TreeNode *left;
  *     TreeNode *right;
  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  * };
  */
//理解题意 中序遍历思想  下一个最小的节点值
class BSTIterator {
public:
	stack<TreeNode *> myStack;
	TreeNode *current;

	BSTIterator(TreeNode *root) {
		while (!myStack.empty()) {
			myStack.pop();
		}	
		current = root;
	}
	
	/** @return whether we have a next smallest number */
	bool hasNext() {
		return (current != NULL || !myStack.empty());	        
	}
	/** @return the next smallest number */
	int next() {
		while (current != NULL) {
			myStack.push(current);
			current = current->left;
		}
		current = myStack.top();
		myStack.pop();
		TreeNode *nxt = current;
		current = current->right;	
		return nxt->val;
	}
};
/**
  * Your BSTIterator will be called like this:
  * BSTIterator i = BSTIterator(root);
  * while (i.hasNext()) cout << i.next();
*/
