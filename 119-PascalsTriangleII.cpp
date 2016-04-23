/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
	Could you optimize your algorithm to use only O(k) extra space?
*/

//1-: 两个vector ，一个记录当前行，一个记录上一行
class Solution {
public:
	vector<int> getRow(int rowIndex) {
		if (rowIndex <= 1)
			return vector<int>(rowIndex + 1, 1);
		
		vector<int> result(2, 1);
		for (int i = 3; i <= rowIndex + 1; i++) {
			vector<int> current(i ,1);       //记录当前计算行
			for(int j = 1; j < i - 1; j++)
				current[j] = result[j - 1] + result[j];
			result = current;
		}

		return result;
	}
};
