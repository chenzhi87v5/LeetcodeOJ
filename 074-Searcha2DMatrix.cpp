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

//1-:二分查找

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty())
			return false;

		const int m = matrix.size();
		const int n = matrix[0].size();
		
		int first = 0;
		int last = m * n;   //关键点 坐标从0开始 
		while (first < last) {
			int mid = first + (last - first) / 2;
			int value = matrix[mid / n][mid % n];
			
			if (value == target) {
				return true;
			} else if (value < target) {
				first = mid + 1;
			} else {
				last = mid;
			}
		}

		return false;
	}
};
