//Power of Three 判断3的次方数

/*Given an integer, write a function to determine if it is a power of three.
Follow up:
Could you do it without using any loop / recursion?*/

/*这道题让我们判断一个数是不是3的次方数，在LeetCode中，有一道类似的题目Power of Two，那道题有个非常简单的方法，由于2的次方数
实在太有特点，最高位为1，其他位均为0，所以特别容易，而3的次方数没有显著的特点，最直接的方法就是不停地除以3，看最后的余数是
否为1，要注意考虑输入是负数和0的情况，参见代码如下：*/

class Solution {
public:
	bool isPowerOfThree(int n) {
		while (n && n % 3 == 0) {
			n /= 3;
		}
		return n == 1;
	}
};
/*最后还有一种巧妙的方法，利用对数的换底公式来做，高中学过的换底公式为logab = logcb / logca，那么如果n是3的倍数，则log3n一定i
是整数，我们利用换底公式可以写为log3n = log10n / log103，注意这里一定要用10为底数，不能用自然数或者2为底数，否则当n=243时会
出错，原因请看这个帖子。现在问题就变成了判断log10n / log103是否为整数，在c++中判断数字a是否为整数，
我们可以用 a - int(a) == 0 来判断，参见代码如下： */

class Solution {
public:
	bool isPowerOfThree(int n) {
		return n > 0 && int(log10(n) / log10(3)) - log10(n) / log10(3) == 0;
	}
};
