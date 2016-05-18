/*
Count the number of prime numbers less than a non-negative number, n. 
*/

//计算质数  本题要求我们求出小于n的数中共有多少个质数
//法一：超时
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
//法二：Good！！！
//还有一种推荐的最优算法  Sieve of Eratosthenes
class Solution {
public:
	int countPrimes(int n) {
		if (n <= 2)
			return 0;
		bool *p = new bool[n];    //new 与 delete 成对出现
		memset(p, true, sizeof(bool) * n); //将p 开始的n个字节全置为true
		
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
