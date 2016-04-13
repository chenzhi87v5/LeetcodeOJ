/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
*/

//1-:
//深度优先搜索法 纯深搜小集合可以过，大集合超时 时间复杂度n^4 空间复杂度n^2

//2-:备忘录法：缓存思想
//深搜 + 缓存 时间复杂度n^2 空间复杂度n^2
class Solution {
public:
	int uniquePaths(int m, int n) {
		// 0行 0列未使用
		this->f = vector<vector<int>> (m + 1, vector<int>(n + 1, 0));
		return dfs(m, n);
	}
private:
	vector<vector<int>> f; //缓存

	int dfs(int x, int y) { 
		if (x < 1 || y < 1)  //数据非法,终止条件
			return 0;
		if (x == 1 || y == 1)  //回到起点，收敛条件
			return 1;

		return getOrUpdate(x - 1, y) + getOrUpdate(x, y - 1);
	}

	int getOrUpdate(int x, int y) {
		if (f[x][y] > 0)
			return f[x][y];
		else
			return f[x][y] = dfs(x, y);
	}
};
