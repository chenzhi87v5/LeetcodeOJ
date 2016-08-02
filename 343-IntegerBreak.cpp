//Integer Break 整数拆分

/*Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those 
integers. Return the maximum product you can get.

For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).

Note: you may assume that n is not less than 2.
Hint:
	There is a simple O(n) solution to this problem.
	You may check the breaking results of n ranging from 7 to 10 to discover the regularities.*/

/*这道题给了我们一个正整数n，让我们拆分成至少两个正整数之和，使其乘积最大，题目提示中让我们用O(n)来解题，而且告诉我们找7到10
之间的规律，那么我们一点一点的来分析：

正整数从1开始，但是1不能拆分成两个正整数之和，所以不能当输出。
那么2只能拆成1+1，所以乘积也为1。
数字3可以拆分成2+1或1+1+1，显然第一种拆分方法乘积大为2。
数字4拆成2+2，乘积最大，为4。
数字5拆成3+2，乘积最大，为6。
数字6拆成3+3，乘积最大，为9。
数字7拆为3+4，乘积最大，为12。
数字8拆为3+3+2，乘积最大，为18。
数字9拆为3+3+3，乘积最大，为27。
数字10拆为3+3+4，乘积最大，为36。
....
那么通过观察上面的规律，我们可以看出从5开始，数字都需要先拆出所有的3，一直拆到剩下一个数为2或者4，因为剩4就不用再拆了，拆成
两个2和不拆没有意义，而且4不能拆出一个3剩一个1，这样会比拆成2+2的乘积小。那么这样我们就可以写代码了，先预处理n为2和3的情况
，然后先将结果res初始化为1，然后当n大于4开始循环，我们结果自乘3，n自减3，根据之前的分析，当跳出循环时，n只能是2或者4，再乘
以res返回即可：*/

class Solution {
public:
	int integerBreak(int n) {
		if (n == 2 || n == 3)
			return n - 1;
		int res = 1;
		while (n > 4) {
			res *= 3;
			n -= 3;
		}
		return res * n;
	}
};
