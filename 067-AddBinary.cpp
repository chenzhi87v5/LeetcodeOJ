//Add Binary 二进制数相加
/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/

//模拟十进制相加，使用一个变量记录进位
class Solution {
public:
	string addBinary(string a, string b) {
		string result;
		
		const size_t n = a.size() > b.size() ? a.size() : b.size();
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());

		int carry = 0;  //进位
		for (size_t i = 0; i < n ; i++) {
			const int ai = i < a.size() ? a[i] - '0' : 0;
			const int bi = i < b.size() ? b[i] - '0' : 0;
			const int val = (ai + bi + carry) % 2;
			carry = (ai + bi + carry) / 2;
			result.insert(result.begin(), val + '0');
		}

		if(carry == 1)
			result.insert(result.begin(), '1');

		return result;
	}
};
