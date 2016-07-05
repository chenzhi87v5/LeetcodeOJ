//Reverse Integer 翻转整数
/*
Reverse digits of an integer.
Example1: x = 123, return 321
Example2: x = -123, return -321
*/

/*翻转数字问题需要注意的就是溢出问题*/
class Solution {
public:
	int reverse(int x) {
		long long int r = 0;
		for (; x ;x /= 10)
			r = r*10 + x%10;
		
		if (r < INT_MIN || r > INT_MAX)
			return 0;
		return r;
	}
};
