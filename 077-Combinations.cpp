//Combinations 组合项
/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
For example,
If n = 4 and k = 2, a solution is:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/
/*
这道题让求1到n共n个数字里k个数的组合数的所有情况，还是要用深度优先搜索DFS来解，根据以往的经验，像这种要求出所有结果的集合，一
般都是用DFS调用递归来解。那么我们建立一个保存最终结果的大集合result，还要定义一个保存每一个组合的小集合path，每次放一个数到
path里，如果path里数个数到了k个，则把path保存到最终结果中，否则在下一层中继续调用递归。 
*/
class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> result;
		vector<int> path;
		dfs(n, k, 1, 0, path, result);
		return result;
	}
private:
	//start，开始的数，cur，已经选好的数
	static void dfs(int n, int k, int start, int cur, vector<int>& path, vector<vector<int>>& result) {
		if (cur == k) {
			result.push_back(path);
			return;
		}
		for (int i = start; i <= n; i++) {
			path.push_back(i);
			dfs(n, k, i + 1, cur + 1, path, result);
			path.pop_back();
		}
	}
};
