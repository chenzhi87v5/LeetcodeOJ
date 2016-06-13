/*
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example:
Given num = 16, return true. Given num = 5, return false.

Follow up: Could you solve it without loops/recursion?
*/

//使用换底公式解

class Solution {
public:
	bool isPowerOfFour(int num) {
		return num > 0 && int(log10(num) / log10(4)) - log10(num) / log10(4) == 0;
	}
};
