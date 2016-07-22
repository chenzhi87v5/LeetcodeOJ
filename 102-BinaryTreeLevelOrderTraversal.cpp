//Binary Tree Level Order Traversal 二叉树层序遍历
/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
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

//二叉树的层级遍历 递归  与 迭代 两种实现
// 递归版 时间复杂度n 空间复杂度n
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> result;
		traverse(root, 1, result);
		return result;
	}
	void traverse(TreeNode *root, size_t level, vector<vector<int>> &result) {
		if (!root)
			return;
		if (level > result.size())                       //result 判定是否需要加入新层
			result.push_back(vector<int>());
		
		result[level - 1].push_back(root->val);           //将节点值加入指定的层
		traverse(root->left, level + 1, result);
		traverse(root->right, level + 1, result);
	}
};

//迭代版，使用队列(queue)
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> result;  
		if (!root)
			return result;
		queue<TreeNode *> current, next;   		//current 为当前处理层节点，next为下一层处理节点
		vector<int> level;          			//当前层的节点值数组从左到右

		current.push(root);
		while (!current.empty()) {
			while (!current.empty()) {
				TreeNode* node = current.front();
				current.pop();
				level.push_back(node->val);   	//当前层节点值存入level里
				
				if (node->left != NULL)         //下一层节点左到右放入next队列
					next.push(node->left);
				if (node->right != NULL)
					next.push(node->right);
			}
			result.push_back(level);    
			level.clear();              		//vector 清除内容clear()
			swap(next, current);        		//当前层处理完后与下一层节点交换
		}
		return result;
	}
};
