//Palindrome Number 验证回文数字
/*
Determine whether an integer is a palindrome. Do this without extra space. 
*/

/*取最后一位与第一位比较*/
/*
这道验证回文数字的题不能使用额外空间，意味着不能把整数变成字符，然后来验证回文字符串。而是直接对整数进行操作，我们可以利用取整和取余来获得我们想要的数字，比如 1221 这个数字，如果 计算 1221 / 1000， 则可得首位1， 如果 1221 % 10， 则可得到末尾1，进行比较，然后把中间的22取出继续比较。代码如下： 
*/
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
