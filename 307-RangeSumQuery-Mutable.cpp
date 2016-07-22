//Range Sum Query - Mutable 区域和检索 - 可变  树状数组Binary Indexed Tree
/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val.
Example:
 Given nums = [1, 3, 5]

 sumRange(0, 2) -> 9
 update(1, 2)
 sumRange(0, 2) -> 8

Note:
	The array is only modifiable by the update function.
	You may assume the number of calls to update and sumRange function is distributed evenly.
*/

//Range Sum Query - Immutable 区域和检索 - 不可变的延伸
/*
原码，补码和反码。计算机中，数值都是以补码的形式保存
补码：正数的补码和原码一样;负数的补码，就是在原来的原码基础上，保持符号位不变，其他位取反，然后再加1
最低位的计算方法有两种，一种是x&(x^(x–1))，另一种是利用补码特性x&-x 
*/

/*
这道题我们要使用一种新的数据结构，叫做树状数组Binary Indexed Tree，这是一种查询和修改复杂度均为O(logn)的数据结构。这个树状数组比较有意思，所有的奇数位置的数字和原数组对应位置的相同，偶数位置是原数组若干位置之和 
*/

//详细参考 http://www.cnblogs.com/grandyang/p/4985506.html
class NumArray {
private:
	vector<int> num;  //存储 原数组
	vector<int> bit;  //存储 树状数组Binary Indexed Tree

public:
	NumArray(vector<int> &nums) {
		num.resize(nums.size() + 1);
		bit.resize(nums.size() + 1);
		
		for (int i = 0; i < nums.size(); i++) {
			update(i, nums[i]);
		}
	}

	void update(int i, int val) {
		int diff = val - num[i + 1];
		
		for (int j = i + 1; j < num.size(); j += (j & -j)) {
			bit[j] += diff;
		}
		
		num[i + 1] = val;
	}

	int sumRange(int i, int j) {
		return getSum(j + 1) - getSum(i);
	}
	
	int getSum(int i) {
		int res = 0;
		for (int j = i; j > 0; j -= (j & -j)) {
			res += bit[j];
		}
		return res;
	}
};
// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
