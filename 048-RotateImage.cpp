/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/

/*1-mySolution:*/
//先对角线翻转一次，再水平中线翻转一次
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		const int n = matrix.size();
		
		for (int i = 0; i < n ; i++) //对角线翻转
			for (int j = 0; j < n - i; j++)
				swap(matrix[i][j], matrix[n - j - 1][n - i - 1]);
		
		for (int i = 0; i < n / 2; i++) //水平中线翻转
			for (int j = 0; j < n; j++)
				swap(matrix[i][j], matrix[n - i - 1][j]);
	}
};
