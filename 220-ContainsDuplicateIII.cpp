/*
Given an array of integers, find out whether there are two distinct indices i and j in the array such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k. 
*/

//求数组是否存在 |nums[i] - nums[j]| <= t && |i - j| <= k True Or False 
//STL multiset使用方法 
//维护一个大小为 k 的二叉搜索树
//有点难  注意绝对值
class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		multiset<long long> bst;
		for (int i = 0; i < nums.size(); i++) {
			if (bst.size() == k + 1)                     //当BST 超过大小k时 删除最前面的元素 i - k - 1;
				bst.erase(bst.find(nums[i - k - 1]));      //erase find 函数
			auto lb = bst.lower_bound(nums[i] - t);              //lower_bound返回容器中大于等于key的迭代器指针
			if (lb != bst.end() && *lb - nums[i] <= t)  //绝对值
				return true;
			bst.insert(nums[i]);
		}

		return false;
	}
};
