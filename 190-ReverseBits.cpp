//Reverse Bits 翻转位
/*
Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

Follow up:
If this function is called many times, how would you optimize it?
Related problem: Reverse Integer
*/

//位运算,翻转所有位
class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		uint32_t reversed = 0;
		//精辟
		for (int i = 0; i < 32; i++) {
			reversed = (reversed << 1) | (n & 1);
			n = (n >> 1);
		}

		return reversed;
	}
};
