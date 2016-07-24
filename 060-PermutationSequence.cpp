//Permutation Sequence 序列排序
/*
The set [1,2,3,…,n] contains a total of n! unique permutations.
By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):
"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.
Note: Given n will be between 1 and 9 inclusive.
*/
//1-:暴力法算出所有排列，然后对排列排序sort 计算第k个排列 ;或者用之前的NextPermutation
/*
这道题是让求出n个数字的第k个排列组合，由于其特殊性，我们不用将所有的排列组合的情况都求出来，然后返回其第k个，我们可以只求出
第k个排列组合即可，那么难点就在于如何知道数字的排列顺序，可参见网友喜刷刷的博客，首先我们要知道当n = 3时，其排列组合
共有3! = 6种，当n = 4时，其排列组合共有4! = 24种，我们就以n = 4, k = 17的情况来分析，所有排列组合情况如下：

1234
1243
1324
1342
1423
1432
2134
2143
2314 
2341
2413
2431
3124
3142
3214
3241
3412	<--- k = 17
3421
4123
4132
4213
4231
4312
4321

我们可以发现，每一位上1,2,3,4分别都出现了6次，当第一位上的数字确定了，后面三位上每个数字都出现了2次，当第二位也确定了，后面的
数字都只出现了1次，当第三位确定了，那么第四位上的数字也只能出现一次，那么下面我们来看k = 17这种情况的每位数字如何确定，由于
k = 17是转化为数组下标为16：

最高位可取1,2,3,4中的一个，每个数字出现3！= 6次，所以k = 16的第一位数字的下标为16 / 6 = 2，即3被取出
第二位此时从1,2,4中取一个，k = 16是此时的k' = 16 % (3!) = 4，而剩下的每个数字出现2！= 2次，所以第二数字的下标为4 / 2 = 2，即4被取出
第三位此时从1,2中去一个，k' = 4是此时的k'' = 4 % (2!) = 0，而剩下的每个数字出现1！= 1次，所以第三个数字的下标为 0 / 1 = 0，即1被取出
第四位是从2中取一个，k'' = 0是此时的k''' = 0 % (1!) = 0，而剩下的每个数字出现0！= 1次，所以第四个数字的下标为0 / 1= 0，即2被取出

那么我们就可以找出规律了
a1 = k / (n - 1)!
k1 = k % (n - 1)!

a2 = k1 / (n - 2)!
k2 = k1 % (n - 2)!
...

an-1 = kn-2 / 1!
kn-1 = kn-2 % 1!

an = kn-1 / 0!
kn = kn-1 % 0!

代码如下：
*/
class Solution {
public:
	string getPermutation(int n, int k) {
		string res;
		string num = "123456789";
		vector<int> f(n, 1);
		
		for (int i = 1; i < n; i++) f[i] = f[i - 1] * i;
		--k;
		
		for (int i = n; i >= 1; --i) {
			int j = k / f[i - 1];
			k %= f[i - 1];
			res.push_back(num[j]);
			num.erase(j, 1);
		}
		return res;
	}
};
