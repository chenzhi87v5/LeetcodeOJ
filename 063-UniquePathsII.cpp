//Unique Paths II 不同的路径之二
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

/*
这道题是之前那道 Unique Paths 不同的路径 的延伸，在路径中加了一些障碍物，还是用动态规划Dynamic Programming来解，
不同的是当遇到为1的点，将该位置的dp数组中的值清零，其余和之前那道题并没有什么区别，代码如下： 
*/

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		if(obstacleGrid.empty() || obstacleGrid[0].empty() || obstacleGrid[0][0] == 1)
			return 0;
		
		vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
		for (int i = 0; i < obstacleGrid.size(); i++) {
			for (int j = 0; j < obstacleGrid[i].size(), j++) {
				if (obstacleGrid[i][j] == 1) dp[i][j] = 0;
				else if (i == 0 && j == 0) dp[i][j] = 1;
				else if (i == 0 && j > 0) dp[i][j] = dp[i][j - 1];
				else if (i > 0 && j == 0) dp[i][j] = dp[i - 1][j];
				else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		return dp.back().back();
	}
};

