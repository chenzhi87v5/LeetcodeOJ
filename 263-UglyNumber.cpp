//Ugly Number 丑陋数

/*Write a program to check whether a given number is an ugly number.
Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly
since it includes another prime factor 7.

Note that 1 is typically treated as an ugly number.*/

//被三个数除过之后最终等于1 则就是丑数
//这道题让我们检测一个数是否为丑陋数，所谓丑陋数就是其质数因子只能是2,3,5。那么最直接的办法就是不停的除以这些质数，
//如果剩余的数字是1的话就是丑陋数
class Solution {
public:
	bool isUgly(int num) {
		if (num <= 0)
			return false;
		if (num == 1)
			return true;
		
		//判断过程
		while (num >= 2 && num % 2 == 0)
			num /= 2;
		while (num >= 3 && num % 3 == 0)
			num /= 3;
		while (num >= 5 && num % 5 == 0)
			num /= 5;

		return num == 1;
	}
};
