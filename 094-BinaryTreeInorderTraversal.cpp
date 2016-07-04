//Binary Tree Inorder Traversal 二叉树的中序遍历
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
/*二叉树的遍历 先序 中序 后序 层序 4种的 递归法与迭代法均需掌握*/
/*
二叉树的中序遍历顺序为左-根-右，可以有递归和非递归来解，其中非递归解法又分为两种，一种是使用栈来接，另一种不需要使用栈。我们先来看递归方法，十分直接，对左子结点调用递归函数，根节点访问值，右子节点再调用递归函数，代码如下： 
*/
//1-: 递归法
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;
		inOrder(root, result);
		return result;
	}
private:
	void inOrder(TreeNode* root, vector<int>& result) {
		if (!root)  return;
		if (root->left) inOrder(root->left, result);
		result.push_back(root->val);
		if (root->right) inOrder(root->right, result);
	}
};

//2-:迭代法 使用栈，时间复杂度n, 空间复杂度n 
/*
下面我们再来看非递归使用栈的解法，也是符合本题要求使用的解法之一，需要用栈来做，思路是从根节点开始，先将根节点压入栈，然后再将其所有左子结点压入栈，然后取出栈顶节点，保存节点值，再将当前指针移到其右子节点上，若存在右子节点，则在下次循环时又可将其所有左子结点压入栈中。这样就保证了访问顺序为左-根-右，代码如下：
*/
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;
		const TreeNode *p = root;     		//p是指向const TreeNode 的指针
		stack<const TreeNode *> s;    		//栈的元素是const TreeNode * 指针

		while (!s.empty() || p) {
			while (p) {
				s.push(p);              //入栈
				p = p->left;            //左子树
			} 
			p = s.top();                	//取栈顶元素
			s.pop();                    	//删除栈顶元素
			result.push_back(p->val);     	//访问val
			p = p->right;                	//右子树
			
		}
		return result;
	}
};
