//Maximal Square 最大正方形

/*Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Return 4.*/

//最大的正方形  新建一个矩阵 记录正方形边大小 动态规划问题
class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		if (matrix.size() == 0 || matrix[0].size() == 0)
			return 0;
		int m = matrix.size();
		int n = matrix[0].size();
		vector<vector<int>> f(m, vector<int>(n));
		
		//初始化f第一排 第一列
		for (int i = 0; i < n; i++) {
			if (matrix[0][i] == '1')
				f[0][i] = 1;
		}
		for (int i = 1; i < m; i++) {
			if (matrix[i][0] == '1')
				f[i][0] = 1;
		}
		
		//f矩阵累计正方形最大边大小
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				if (matrix[i][j] == '0') {
					f[i][j] = 0;
				} else {
					f[i][j] = 1 + min(f[i - 1][j], min(f[i - 1][j - 1], f[i][j - 1]));
				}

			}
		}
		
		//统计最大边
		int ans = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++)
				ans = max(ans, f[i][j]);
		}
		return ans * ans;
	}
};
