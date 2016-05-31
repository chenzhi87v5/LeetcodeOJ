/*
Given an integer, write a function to determine if it is a power of two. 
*/

//确定一个数是否是2的幂

class Solution {
public:
	bool isPowerOfTwo(int n) {
		if (n == 0)              //注意临界情况 0 不是2 的幂  1 = 2^0
			return false;
		
		while (n % 2 == 0) {
			n /= 2;
		}
		
		return n == 1;
	}
};
