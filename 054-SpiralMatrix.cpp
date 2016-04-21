/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
  
You should return [1,2,3,6,9,8,7,4,5].
*/

#include<iostream>
#include<vector>
using namespace std;

//1-:模拟螺旋读
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> result;
		
		if (matrix.empty())
			return result;
		
		int beginX = 0, endX = matrix[0].size() - 1;
		int beginY = 0, endY = matrix.size() - 1;

		while (true) {
			//从左到右
			for (int j = beginX; j <= endX; j++)
				result.push_back(matrix[beginY][j]);
			if (++beginY > endY)
				break;

			//从上到下
			for (int i = beginY; i <= endY; i++)
				result.push_back(matrix[i][endX]);
			if (--endX < beginX)
				break;

			//从右到左
			for (int j = endX; j >= beginX; j--)
				result.push_back(matrix[endY][j]);
			if (--endY < beginY)
				break;

			//从下到上
			for (int i = endY; i >= beginY; i--)
				result.push_back(matrix[i][beginX]);
			if (++beginX > endX)
				break;
		}
		return result;
	}
};



int main() {
	Solution A;
	vector<vector<int>> matrix;

	matrix.push_back({1, 2, 3});
	matrix.push_back({4, 5, 6});
	matrix.push_back({6, 7, 9});
	//A.spiralOrder(matrix);
	return 0;
}