//Symmetric Tree 判断对称树

/*Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
For example, this binary tree is symmetric:
    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
    3   3
Note:
Bonus points if you could solve it both recursively and iteratively.
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

//判断是否是对称树 两种方法实现  递归 与 迭代
//法一:递归法
class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		return root ? isSymmetric(root->left, root->right) : true;
	}

	bool isSymmetric(TreeNode *left, TreeNode *right) {
		if (!left && !right)     //终止条件
			return true;
		if (!left || !right)	 //终止条件
			return false;
		return left->val == right->val                      //三合并 
			&& isSymmetric(left->left, right->right)    //左支的左子树等于右支的右子树
			&& isSymmetric(left->right, right->left);   //左支的右子树等于右支的左子树
	}
};

//法二:迭代法 使用栈
class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (!root)
			return true;
		
		stack<TreeNode *>s;  //栈
		s.push(root->left);
		s.push(root->right);
		
		while (!s.empty()) {        
			auto p = s.top();    	 //提取对称节点判断
			s.pop();
			auto q = s.top();
			s.pop();

			if (!p && !q)
				continue;
			if (!p || !q)
				return false;
			if (p->val != q->val)
				return false;

			s.push(p->left);           //对称节点压入栈
			s.push(q->right);

			s.push(p->right);         //对称节点压入栈
			s.push(q->left);
		}

		return true;
	}
};

