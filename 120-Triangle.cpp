//Triangle 三角形 
/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]

The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
Note:
	Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/

/*
动态规划问题
  设状态为f(i,j)，表示从从位置(i,j) 出发，路径的最小和，则状态转移方程为
  f(i,j) = min{f(i,j + 1), f(i + 1,j + 1)} + (i,j)
  时间复杂度n^2 空间复杂度1
  由下向上 计算
*/
class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		//参数检测
		if (triangle.size() == 0)
			return -1;
		if(triangle.size() == 1)
			return triangle[0][0];
		
		for (int i = triangle.size() - 2; i >= 0; i--) {  //倒数第二排开始
			for (int j = 0 ; j <= i; j++) {           //倒数一排最小的相邻值与倒数二排相加
				triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]); 
			}
		}
		
		return triangle[0][0];
	}
};
