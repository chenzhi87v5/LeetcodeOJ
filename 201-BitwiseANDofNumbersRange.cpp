/*
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

For example, given the range [5, 7], you should return 4.
*/

//按位与运算 
//一组数字按位与时，只有所有数字这一位上都为1时，结果才会为1
//如果这一组数字的最低位不相同的话，那这一位就肯定会被消掉，变成0.
//如果m!=n,那最低位肯定是要被消掉的，因为最低位肯定会是一个0，一个1.这时，我们可以将m和n都右移一位，将最后一位忽略。
class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		int count = 0; //记录左移位数
		
		while (m != n) {
			m >>= 1;
			n >>= 1;
			count++;
		}

		return m << count;
	}
};
