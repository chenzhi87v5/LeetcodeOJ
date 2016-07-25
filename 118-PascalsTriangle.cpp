//Pascal's Triangle 杨辉三角
/*
Given numRows, generate the first numRows of Pascal's triangle.
For example, given numRows = 5,
Return
[
        [1],
       [1,1],
      [1,2,1],
     [1,3,3,1],
    [1,4,6,4,1]
]
*/
/*
具体生成算是：每一行的首个和结尾一个数字都是1，从第三行开始，中间的每个数字都是上一行的左右两个数字之和。代码如下：
*/
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> result;
		if (numRows == 0)
			return result;
		result.push_back(vector<int>(1, 1));  //第一行
		if (numRows == 1)
			return result;
		result.push_back(vector<int>(2, 1));  //第二行
		if (numRows == 2)
			return result;
		
		for(int i = 3; i <= numRows; i++) {   		   //第三行开始使用循环计算
			vector<int> current(i, 1);                 //计算新的行current
			const vector<int> &prev = result[i - 2];   //上一行 '&'表示取地址符，或者表示引用
			
			for(int j = 1; j < i - 1; j++)
				current[j] = prev[j - 1] + prev[j]; //左上角与右上角之和

			result.push_back(current);
		}
		return result;
	}
};
