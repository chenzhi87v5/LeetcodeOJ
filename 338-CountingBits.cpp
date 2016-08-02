//Counting Bits 计数位           Ignore

/*Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in 
their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].

Follow up:
	It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time 
O(n) /possibly in a single pass?
	Space complexity should be O(n).
	Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other 
language.
Hint:
	You should make use of what you have produced already.
	Divide the numbers in ranges like [2-3], [4-7], [8-15] and so on. And try to generate new range from previous.
	Or does the odd/even status of the number help you in calculating the number of 1s?
*/
//从1开始，遇到偶数时，其1的个数和该偶数除以2得到的数字的1的个数相同，遇到奇数时，其1的个数等于该奇数除以2得到的数字的1的个
//数再加1，参见代码如下： 
//找规律  解题
class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> res{0};
		
		for (int i = 1; i <= num; i++) {
			if (i % 2 == 0)
				res.push_back(res[i / 2]);
			else
				res.push_back(res[i / 2] + 1);
		}

		return res;
	}
};
