//Rotate Image 旋转图像
/*
You are given an n x n 2D matrix representing an image.
Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/

/*
首先以从对角线为轴翻转，然后再以x轴中线上下翻转即可得到结果，如下图所示(其中蓝色数字表示翻转轴)：

1  2  3　　　 　　 9  6  3　　　　　  7  4  1

4  5  6　　-->　　 8  5  2　　 -->    8  5  2　　

7  8  9 　　　 　　7  4  1　　　　　  9  6  3
*/
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		const int n = matrix.size();
		
		for (int i = 0; i < n ; i++) 		//对角线翻转
			for (int j = 0; j < n - i; j++)
				swap(matrix[i][j], matrix[n - j - 1][n - i - 1]);
		
		for (int i = 0; i < n / 2; i++) 	//水平中线翻转
			for (int j = 0; j < n; j++)
				swap(matrix[i][j], matrix[n - i - 1][j]);
	}
};
