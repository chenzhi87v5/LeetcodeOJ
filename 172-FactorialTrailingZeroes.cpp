/*
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.
*/

//理解题意，数学证明
//n!的值后面带多少个0 2与5相乘才会出现0
//对n!做质因数分解n!=(2^x)*(3^y)*(5^z)*...
//显然0的个数等于min(x,z)，并且min(x,z)==z
//证明：
//对于阶乘而言，也就是1*2*3*...*n
//[n/k]代表1~n中能被k整除的个数

class Solution {
public:
	int trailingZeroes(int n) {
		int ret = 0;
		while(n) {
			ret += n / 5;
			n /= 5;
		}

		return ret;
	}
};
