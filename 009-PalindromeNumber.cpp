/*
Determine whether an integer is a palindrome. Do this without extra space. 
*/

/*1-my Solution:整数反转比较，使用long long int 防止溢出*/
/*
class Solution {
public:
	bool isPalindrome(int x) {
		long long int y = 0, t = x;
		if (x < 0)
			return false;

		while (x) {
			y = y*10 + x%10;
			x /= 10;
		}
		if (t == y)
			return true;
		else
			return false;
	}
};
*/

/*2-Answers:取最后一位与第一位比较*/
class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0) 
			return false;
		int d = 1;
		while (x / d >= 10) 
			d *= 10;
		while (x > 0) {
			int q = x / d;
			int r = x % 10;
			if (q != r)
				return false;
			x = x % d / 10;
			d /= 100;
		}
		return true;
	}
};

int main()
{
	return 0;
}
