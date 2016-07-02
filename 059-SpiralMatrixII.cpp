//Spiral Matrix II 螺旋矩阵之二
/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

//按照题意螺旋处理 螺旋矩阵之一 类似一个是读 现在是写
class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		//初始化
		vector<vector<int>> result(n, vector<int>(n));

		if (n == 0)
			return result;
		
		int xb = 0, xe = n - 1;
		int yb = 0, ye = n - 1;
		int num = 1;
		while (true) {
			//从左到右
			for (int i = xb; i <= xe; i++)
				result[yb][i] = num++;
			if (++yb > ye)
				break;

			//从上到下
			for (int i = yb; i <= ye; i++)
				result[i][xe] = num++;
			if (--xe < xb)
				break;

			//从右到左
			for (int i = xe; i >= xb; i--)
				result[ye][i] = num++;
			if (--ye < yb)
				break;

			//从下到上
			for (int i = ye; i >= yb; i--)
				result[i][xb] = num++;
			if (++xb > xe)
				break;
		}

		return result;
	}
};
