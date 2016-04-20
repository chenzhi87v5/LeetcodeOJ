/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
   
return its zigzag level order traversal as:
[
  [3],
  [20,9],
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

//1-:递归 和 迭代
//递归法 bool值 判定翻转条件
class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> result;
		traverse(root, 1, result, true);
		return result;
	}
	
	void traverse(TreeNode *root, size_t level, vector<vector<int>> &result, bool left_to_right) {
		if (!root)
			return;
		if (level > result.size())
			result.push_back(vector<int>());

		if(left_to_right)
			result[level - 1].push_back(root->val);
		else
			result[level - 1].insert(result[level - 1].begin(), root->val);

		traverse(root->left, level + 1, result, !left_to_right);
		traverse(root->right, level + 1, result, !left_to_right);
	}
};

//迭代法 使用queue
class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> result;
		if (!root)
			return result;

		bool left_to_right = true;         //翻转条件
		queue<TreeNode *> current, next;   //两个队列
		vector<int> level;
		current.push(root);

		while (!current.empty()) {
			while (!current.empty()) {
				TreeNode *node = current.front();
				current.pop();
				level.push_back(node->val);
				
				if (node->left != NULL)
					next.push(node->left);
				if (node->right != NULL)
					next.push(node->right);
			}
			
			if (left_to_right) {
				result.push_back(level);
			} else {
				reverse(level.begin(), level.end());
				result.push_back(level);
			}
			
			level.clear();
			left_to_right = !left_to_right;
			swap(next, current);
		}

		return result;
	}
};
