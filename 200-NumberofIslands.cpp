//Number of Islands 岛屿的数量
/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is 
formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surround
ed by water.

Example 1:
11110
11010
11000
00000
Answer: 1

Example 2:
11000
11000
00100
00011
Answer: 3
*/
//实为求连通子图的个数，借助DFS的思想
class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		int num = 0;
		if (grid.size() == 0) {
			return num;
		}
		if (grid[0].size() == 0) {
			return num;
		}
		
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[i].size(); j++) {
				if (dfs(i, j, grid))
					num++;
			}
		}
		return num;
	}

private:
	//将所有相邻的1置为3  OR 还有一种设置一个新的矩阵标示是否访问过
	bool dfs(int i, int j, vector<vector<char>> &grid) {
		if (i >= 0 && i < grid.size() && j >=0 && j <grid[i].size() && grid[i][j] == '1') {
			grid[i][j] = '3';
			dfs(i - 1, j, grid);
			dfs(i + 1, j, grid);
			dfs(i, j - 1, grid);
			dfs(i, j + 1, grid);
			return true;
		}
		return false;
	}
};
