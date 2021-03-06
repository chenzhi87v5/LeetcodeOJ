//Range Sum Query 2D - Immutable 二维区域和检索 - 不可变

/*Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) 
and lower right corner (row2, col2).

Range Sum Query 2D
The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains 
sum = 8.

Example:
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]
  
  sumRegion(2, 1, 4, 3) -> 8
  sumRegion(1, 1, 2, 2) -> 11
  sumRegion(1, 2, 2, 4) -> 12

Note:
	You may assume that the matrix does not change.
	There are many calls to sumRegion function.
	You may assume that row1 ≤ row2 and col1 ≤ col2.*/

//巧妙解法  使用矩阵存储SUM值 
class NumMatrix {
private:
	vector<vector<int>> acc;
public:
	NumMatrix(vector<vector<int>> &matrix) {
		if (matrix.empty())
			return;
		
		int n = matrix.size(), m = matrix[0].size();
		acc.resize(n + 1, vector<int>(m + 1));
		for (int i = 0; i <= n; i++)
			acc[i][0] = 0;
		for (int j = 0; j <= m; j++)
			acc[0][j] = 0;
		
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				acc[i][j] = acc[i][j - 1] + acc[i - 1][j] - acc[i - 1][j - 1] + matrix[i - 1][j - 1];
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		return acc[row2 + 1][col2 + 1] 
			- acc[row1][col2 + 1] - acc[row2 + 1][col1] 
			+ acc[row1][col1];
	}
};
// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
