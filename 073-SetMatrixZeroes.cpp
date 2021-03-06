//Set Matrix Zeroes 矩阵赋零
/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
Follow up:
	Did you use extra space?
	A straight forward solution using O(mn) space is probably a bad idea.
	A simple improvement uses O(m + n) space, but still not the best solution.
	Could you devise a constant space solution?
*/

/*
这道题的要求是用O(1)的空间，那么我们就不能新建数组，我们考虑就用原数组的第一行第一列来记录各行各列是否有0.

- 先扫描第一行第一列，如果有0，则将各自的flag设置为true
- 然后扫描除去第一行第一列的整个数组，如果有0，则将对应的第一行和第一列的数字赋0
- 再次遍历除去第一行第一列的整个数组，如果对应的第一行和第一列的数字有一个为0，则将当前值赋0
- 最后根据第一行第一列的flag来更新第一行第一列

代码如下：
*/
class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		if (matrix.empty() || matrix[0].empty())
			return;
		int m = matrix.size(), n = matrix[0].size();
		bool rowZero = false, colZero = false;
		
		//第一列
		for (int i = 0; i < m; i++) {
			if (matrix[i][0] == 0) colZero = true;
		}
		//第一行
		for (int i = 0; i < n; i++) {
			if (matrix[0][i] == 0) rowZero = true;
		}

		//扫描
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				if (matrix[i][j] == 0) {
					matrix[0][j] = 0;
					matrix[i][0] = 0;
				}
			}
		}
		//置0
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				if (matrix[0][j] == 0 || matrix[i][0] == 0) {
					matrix[i][j] = 0;
				}
			}
		}

		//最后处理第一行 第一列
		if (rowZero) {
			for (int i = 0; i < n; i++) matrix[0][i] = 0;
		}
		if (colZero) {
			for (int i = 0; i < m; i++) matrix[i][0] = 0;
		}

		return;
	}
}
