/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

Follow up:
	Did you use extra space?
	A straight forward solution using O(mn) space is probably a bad idea.
	A simple improvement uses O(m + n) space, but still not the best solution.
	Could you devise a constant space solution?
*/

//1-:时间复杂度 m * n 空间复杂度 1  （自己的方法）
class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		if (matrix.empty())
			return;

		vector<vector<int>> res;   //记录为0的横纵坐标
		const int m = matrix.size();
		const int n = matrix[0].size();

		for(int i = 0; i < m ; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == 0)
					res.push_back({i, j});
			}
		}
		for (auto it : res) {
			int h = it[0];
			int l = it[1];
			for (int i = 0; i < m; i++)
				matrix[i][l] = 0;
			for (int i = 0; i < n; i++)
				matrix[h][i] = 0;
		}

		return;
	}
};
