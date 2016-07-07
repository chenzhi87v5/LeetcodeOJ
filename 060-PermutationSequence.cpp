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
//2-:康托编码思想：数学法解决 思路有点难理解
class Solution {
public:
	string getPermutation(int n, int k) {
		string s(n, '0');
		string result;
		for(int i = 0; i < n; i++)
			s[i] += i + 1;

		return kth_permutation(s, k);
	}
private:
	//求n！的值
	int factorial (int n) {
		int result = 1;
		for (int i = 1; i <= n; i++)
			result *= i;
		
		return result;
	}
	//seq已经排好序,是第一个排列
	template<typename Sequence>
	Sequence kth_permutation(const Sequence &seq, int k) {
		const int n = seq.size();
		Sequence S(seq);
		Sequence result;

		int base = factorial(n - 1);
		--k; //康托编码从0开始
		
		for (int i = n - 1; i > 0; k %= base, base /= i, i--) {
			auto a = next(S.begin(), k / base);
			result.push_back(*a);
			S.erase(a);
		}
		
		result.push_back(S[0]); //最后一个
		return result;
	}
};
/*

*/
