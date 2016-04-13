/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

//1-：深度优先 + 缓存 备忘录法
//备忘录法

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size();
		int n = grid[0].size();

		this->f = vector<vector<int>>(m, vector<int>(n, -1));
		return dfs(grid, m - 1, n - 1);
	}
private:
	vector<vector<int>> f; //缓存

	int dfs(const vector<vector<int>>& grid, int x, int y) {
		if (x < 0 || y < 0)      //越界 终止条件 注意不是 0
			return INT_MAX;
		if (x == 0 && y == 0)   //回到起点，收敛条件
			return grid[0][0];
		return min(getOrUpdate(grid, x - 1, y), getOrUpdate(grid, x, y - 1)) + grid[x][y];
	}

	int getOrUpdate(const vector<vector<int>>& grid, int x, int y) {
		if (x < 0 || y < 0)
			return INT_MAX;  //越界
		if (f[x][y] >= 0) 
			return f[x][y];
		else
			return f[x][y] = dfs(grid, x , y);
	}
};
