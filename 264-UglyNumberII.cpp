//Ugly Number II	丑陋数之二

/*Write a program to find the n-th ugly number.
Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 
is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number.

Hint:
	The naive approach is to call isUgly for every number until you reach the nth one. Most numbers are not ugly. Try 
to focus your effort on generating only the ugly ones.
	An ugly number must be multiplied by either 2, 3, or 5 from a smaller ugly number.
	The key is how to maintain the order of the ugly numbers. Try a similar approach of merging from three sorted 
lists: L1, L2, and L3.
	Assume you have Uk, the kth ugly number. Then Uk+1 must be Min(L1 * 2, L2 * 3, L3 * 5).
*/

//Ugly Number I 的扩展题   找出第n个丑数

/*这道题是之前那道Ugly Number 丑陋数的延伸，这里让我们找到第n个丑陋数，还好题目中给了很多提示，基本上相当于告诉我们解法了，
根据提示中的信息，我们知道丑陋数序列可以拆分为下面3个子列表：

(1) 1×2, 2×2, 3×2, 4×2, 5×2, …
(2) 1×3, 2×3, 3×3, 4×3, 5×3, …
(3) 1×5, 2×5, 3×5, 4×5, 5×5, …

仔细观察上述三个列表，我们可以发现每个子列表都是一个丑陋数分别乘以2,3,5，而要求的丑陋数就是从已经生成的序列中取出来的，我们
每次都从三个列表中取出当前最小的那个加入序列，请参见代码如下：*/

class Solution {
public:
	int nthUglyNumber(int n) {
		int *uglys = new int[n];
		uglys[0] = 1;
		int next = 1;
		int *p2 = uglys;
		int *p3 = uglys;
		int *p5 = uglys;
		
		while (next < n) {
			int m = min(min(*p2 * 2, *p3 * 3), *p5 * 5);   //取最小
			uglys[next] = m;
			
			while (*p2 * 2 <= uglys[next])    	       //丑数数列增加
				p2++;
			while (*p3 * 3 <= uglys[next])
				p3++;
			while (*p5 * 5 <= uglys[next])
				p5++;
			next++;
		}

		int uglyNum = uglys[n - 1];
		delete uglys;
		uglys = NULL;
		return uglyNum;
	}
};
