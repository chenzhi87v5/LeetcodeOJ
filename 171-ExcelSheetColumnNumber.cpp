//Excel Sheet Column Number 求Excel表列序号
/*
Related to question Excel Sheet Column Title
Given a column title as appear in an Excel sheet, return its corresponding column number.
For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
*/
//这题实际上相当于一种二十六进制转十进制的问题，并不难，只要一位一位的转换即可。代码如下：
class Solution {
public:
	int titleToNumber(string s) {
		int res = 0;
		int len = s.size();
		
		if (len == 0)
			return res;

		for (int i = 0; i < len; i++) {
			res = res * 26 + (s[i] - 'A' + 1);
		}
		return res;
	}
};
