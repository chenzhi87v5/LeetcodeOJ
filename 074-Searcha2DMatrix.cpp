//Search a 2D Matrix 搜索一个二维矩阵
/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
	Integers in each row are sorted from left to right.
	The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
	Given target = 3, return true.
*/

/*
这道题也可以使用一次二分查找法，如果我们按S型遍历该二维数组，可以得到一个有序的一维数组，那么我们只需要用一次二分查找法，
而关键就在于坐标的转换，如何把二维坐标和一维坐标转换是关键点，把一个长度为n的一维数组转化为m*n的二维数组(m*n = n)后，那么原
一维数组中下标为i的元素将出现在二维数组中的[i/n][i%n]的位置，有了这一点，代码很好写出来了：
*/
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty() || matrix[0].empty()) return false;                       //预处理
		if (target < matrix[0][0] || target > matrix.back().back()) return false;

		const int m = matrix.size();
		const int n = matrix[0].size();
		
		int first = 0;
		int last = m * n - 1;           		//关键
		while (first <= last) {
			int mid = (first + last) / 2;
			int value = matrix[mid / n][mid % n];   //关键
			if (value == target) {
				return true;
			} else if (value < target) {
				first = mid + 1;
			} else {
				last = mid - 1;
			}
		}

		return false;
	}
};
