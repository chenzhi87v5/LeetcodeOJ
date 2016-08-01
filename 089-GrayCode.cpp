//Grey Code 格雷码   Ingore
/*
The gray code is a binary numeral system where two successive values differ in only one bit.
Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
00 - 0
01 - 1
11 - 3
10 - 2
Note:
	For a given n, a gray code sequence is not uniquely defined.
	For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.
	For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
*/

//1-:格雷码 I.自然二进制码转换为格雷码; II.格雷码转换为自然二进制码
//数学法：整数n的格雷码是 n^(n/2) "^"是异或  递归法
class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> result;
		const size_t size = 1 << n;  //2^n 值
		result.reserve(size); 	     //reserve表示容器预留空间，但并不是真正的创建对象
		for (size_t i = 0; i < size; i++)
			result.push_back(binary_to_gray(i));

		return result;
	}
private:
	static unsigned int binary_to_gray(unsigned int n) {
		return n ^ (n >> 1);
	}
};
