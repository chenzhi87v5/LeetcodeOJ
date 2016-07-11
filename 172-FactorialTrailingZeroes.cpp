//Factorial Trailing Zeroes 求阶乘末尾零的个数
/*
Given an integer n, return the number of trailing zeroes in n!.
Note: Your solution should be in logarithmic time complexity.
*/

/*理解题意，数学证明
n!的值后面带多少个0 2与5相乘才会出现0
对n!做质因数分解n!=(2^x)*(3^y)*(5^z)*...
显然0的个数等于min(x,z)，并且min(x,z)==z
证明：
对于阶乘而言，也就是1*2*3*...*n
[n/k]代表1~n中能被k整除的个数
*/
/*
这道题并没有什么难度，是让求一个数的阶乘末尾0的个数，也就是要找乘数中10的个数，而10可分解为2和5，而我们可知2的数量又远大于5的数量，那么此题即便为找出5的个数。仍需注意的一点就是，像25,125，这样的不只含有一个5的数字需要考虑进去。代码如下： 
*/
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
