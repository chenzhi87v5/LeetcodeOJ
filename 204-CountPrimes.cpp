//Count Primes 质数的个数
/*
Count the number of prime numbers less than a non-negative number, n. 
*/
//计算质数  本题要求我们求出小于n的数中共有多少个质数 法一：超时
class Solution {
public:
	int countPrimes(int n) {
		int count = 0;
		for (int i = 1; i < n ; i++) {
			if (isPrime(i))
				count++;
		}
		return count;
	}
private:
	//判断一个数是否是质数
	bool isPrime(int num) {
		if (num <= 1)
			return false;
		for (int i = 2; i * i <= num; i++) {
			if (num % i == 0)
				return false;
		}

		return true;
	}
};
//还有一种推荐的最优算法  Sieve of Eratosthenes
/*
这道题给定一个非负数n，让我们求小于n的质数的个数，题目中给了充足的提示，解题方法就在第二个提示埃拉托斯特尼筛法
Sieve of Eratosthenes中，这个算法的过程如下图所示，我们从2开始遍历到根号n，先找到第一个质数2，然后将其所有的倍数全部标记出
来，然后到下一个质数3，标记其所有倍数，一次类推，直到根号n，此时数组中未被标记的数字就是质数。我们需要一个n-1长度的bool型
数组来记录每个数字是否被标记，长度为n-1的原因是题目说是小于n的质数个数，并不包括n。 然后我们用两个for循环来实现埃拉托斯特
尼筛法，难度并不是很大，代码如下所示： 
*/
class Solution {
public:
	int countPrimes(int n) {
		if (n <= 2)
			return 0;
		bool *p = new bool[n];    	     	//new 与 delete 成对出现
		memset(p, true, sizeof(bool) * n);   	//将p 开始的n个字节全置为true
		
		for (int i = 2; i * i < n; i++) {
			if (p[i]) {
				for (int j = 2; j * i < n; j++)
					p[i * j] = false;
			}
		}
		
		int cnt = 0;
		for (int i = 2; i != n; i++) {
			if (p[i])
				cnt++;
		}
		
		delete [] p;
		return cnt;
	}
};
