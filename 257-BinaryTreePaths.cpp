/*
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
 
All root-to-leaf paths are:

["1->2->5", "1->3"]
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

//返回所有根到叶节点的路径
//九章 ： 深度优先遍历，每遇到叶节点，将栈中路径记录下来，最后将所有路径转成所需格式
class Solution {
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> path;                       //结果
		if (root == NULL)
			return path;

		vector<vector<int>> pathv;                  //存储根到叶 路径节点val值
		unordered_map<TreeNode*, bool> visited;     //hash map 记录是否访问了节点 true or false
		stack<TreeNode*> stk;                       //存储路径节点的stack
		stk.push(root);
		visited[root] = true;
		
		if (root->left == NULL && root->right == NULL)   //只有根节点情况时
			save(pathv, stk);
		
		while (!stk.empty()) {
			TreeNode *top = stk.top();
			if (top->left && visited[top->left] == false) {
				stk.push(top->left);
				visited[top->left] = true;
				if (top->left->left == NULL && top->left->right == NULL)
					save(pathv, stk);
				continue;
			}
			if (top->right && visited[top->right] == false) {
				stk.push(top->right);
				visited[top->right] = true;
				if (top->right->left == NULL && top->right->right == NULL)
					save(pathv, stk);
				continue;
			}
			stk.pop();   //关键点
		}

		return convert(pathv);
	}

private:
	//save函数将（一个根到叶节点的路径val值顺序）加入pathv
	void save(vector<vector<int>>& pathv, stack<TreeNode*> stk) {
		vector<int> cur;
		while (!stk.empty()) {
			TreeNode* top = stk.top();
			cur.push_back(top->val);
			stk.pop();
		}
		reverse(cur.begin(), cur.end());
		pathv.push_back(cur);
	}

	//convert函数将vector<vector<int>> pathv 转化成vector<string> path 输出格式
	vector<string> convert(vector<vector<int>>& pathv) {
		vector<string> path;
		for (int i = 0; i < pathv.size(); i++) {
			string cur;
			cur += to_string(pathv[i][0]);                  //to_string 用法
			for (int j = 1; j < pathv[i].size(); j++) {
				cur += "->";
				cur += to_string(pathv[i][j]);
			}
			path.push_back(cur);
		}
		return path;
	}
};
