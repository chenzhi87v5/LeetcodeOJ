/*
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Ensure that numbers within the set are sorted in ascending order.


Example 1:

	Input: k = 3, n = 7

Output:

	[[1,2,4]]

Example 2:

	Input: k = 3, n = 9

Output:

	[[1,2,6], [1,3,5], [2,3,4]]
*/

//深度优先搜索法DFS

class Solution {
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> res;
		vector<int> out;

		dfs(k, n, 1, out, res);
		
		return res;
	}

	//DFS 深度递归
	void dfs(int k, int n, int level, vector<int> &out, vector<vector<int>> &res) {
		if (n < 0)  //剪枝
			return;
		if (n == 0 && out.size() == k) //结果
			res.push_back(out);
		
		for (int i = level; i <= 9; i++) { //扩展
			out.push_back(i);
			dfs(k, n - i, i + 1, out, res);
			out.pop_back();
		}
	}
};
