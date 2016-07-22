//Binary Tree Right Side View 二叉树的右侧视图
/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---

You should return [1, 3, 4].
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

//层次遍历每一层最后一个节点，由上往下
//复杂度 logn 空间复杂度 1 
//实际上是求二叉树层序遍历的一种变形，我们只需要保存每一层最右边的数字即可
class Solution {
public:
	vector<int> rightSideView(TreeNode* root) {
		vector<int> result;
		if (root == NULL)
			return result;
		queue<TreeNode *> que;   //层次访问，使用队列
		que.push(root);
		TreeNode *curr;         //当前节点

		while(!que.empty()) {
			int cnt = que.size();
			for (int i = 0; i < cnt; i++) {
				curr = que.front();
				que.pop();
				if (curr->left) {
					que.push(curr->left);
				}
				if (curr->right) {
					que.push(curr->right);
				}
			}
			result.push_back(curr->val);
		}
		return result;
	}
};
