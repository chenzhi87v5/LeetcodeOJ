//Number of 1 Bits 位1的个数
/*
Write a function that takes an unsigned integer and returns the number of '1' bits it has 
(also known as the Hamming weight).

For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, 
so the function should return 3.
*/
//精辟 优化代码
class Solution {
public:
	int hammingWeight(uint32_t n) {
		if (n == 0)
			return 0;
		int count = 0;
		while (n != 0) {
			if (n & 1 == 1)
				count++;
			n = (n >> 1);
		}
		return count;
	}
};
