//Invert Binary Tree 翻转二叉树

/*Invert a binary tree.
     4
   /   \
  2     7
 / \   / \
1   3 6   9

to
     4
   /   \
  7     2
 / \   / \
9   6 3   1

Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard 
so fuck off.
*//**
  * Definition for a binary tree node.
  * struct TreeNode {
  *     int val;
  *     TreeNode *left;
  *     TreeNode *right;
  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  * };
  */
//反转二叉树   简单的深度递归DFS
//先来看递归的方法，写法非常简洁，交换当前左右节点，并直接调用递归即可，代码如下：
class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root == NULL)
			return root;
		
		TreeNode* tmp = root->left;
		root->left = root->right;
		root->right = tmp;
		
		root->left = invertTree(root->left);
		root->right = invertTree(root->right);

		return root;
	}
};
//非递归的方法也不复杂，跟二叉树的层序遍历一样，需要用queue来辅助，先把根节点排入队列中，然后从队中取出来，交换其左右节点i
//，如果存在则分别将左右节点在排入队列中，以此类推直到队列中木有节点了停止循环，返回root即可。代码如下：
class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (!root) return NULL;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			TreeNode *node = q.front(); 
			q.pop();
			
			TreeNode *tmp = node->left;
			node->left = node->right;
			node->right = tmp;
			
			if (node->left) q.push(node->left);
			if (node->right) q.push(node->right);
		}
		return root;
	}
}
