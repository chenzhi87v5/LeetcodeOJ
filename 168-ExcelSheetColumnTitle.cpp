//Excel Sheet Column Title 求 Excel 表列名称
/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.
For example:
    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
*/

//按题意 递归解
class Solution {
public:
	string convertToTitle(int n) {
		if (n == 0)
			return "";
		return convertToTitle((n - 1) / 26) + char((n - 1) % 26 + 'A');
	}
};
