/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.
*/

//按照题意解

class NumArray {
private:
	vector<int> acc;
public:
	NumArray(vector<int> &nums) {
		acc.push_back(0);
		for (auto n : nums) {
			acc.push_back(acc.back() + n);
		}
	}
	
	int sumRange(int i, int j) {
		return acc[j + 1] - acc[i];
	}
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
