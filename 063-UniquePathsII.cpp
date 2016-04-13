/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
    The total number of unique paths is 2.
*/

//1- :深搜 + 备忘录法

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		const int m = obstacleGrid.size();
		const int n = obstacleGrid[0].size();

		// 0行0列 未使用
		this->f = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
		return dfs(obstacleGrid, m, n);
	}

private:
	vector<vector<int>> f; //缓存
	
	//递归
	int dfs(const vector<vector<int>>& obstacleGrid, int x, int y) {
		if (x < 1 || y < 1)   //数据非法，终止条件
			return 0;
		//(x, y) 是障碍 
		if (obstacleGrid[x - 1][y - 1])
			return 0;

		if (x == 1 && y == 1)    //回到起点，收敛条件
			return 1;

		return getOrUpdate(obstacleGrid, x - 1, y) + getOrUpdate(obstacleGrid, x, y - 1);
	}
	
	//判断缓存
	int getOrUpdate(const vector<vector<int>>& obstacleGrid, int x, int y) {
		if (f[x][y] > 0)
			return f[x][y];
		else
			return f[x][y] = dfs(obstacleGrid, x, y);
	}
};
