//Palindrome Number 验证回文数字
/*
Determine whether an integer is a palindrome. Do this without extra space. 
*/

/*取最后一位与第一位比较*/
class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0) 
			return false;
		int d = 1;
		while (x / d >= 10) 
			d *= 10;
		while (x > 0) {
			int q = x / d;   //第一位
			int r = x % 10;  //最后一位
			if (q != r)
				return false;
			x = x % d / 10;   //x去掉第一位与最后一位
			d /= 100;
		}
		return true;
	}
};
