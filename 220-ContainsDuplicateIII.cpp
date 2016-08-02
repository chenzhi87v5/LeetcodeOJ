//Contains Duplicate III 包含重复值之三

/*Given an array of integers, find out whether there are two distinct indices i and j in the array such that the difference 
between nums[i] and nums[j] is at most t and the difference between i and j is at most k. */

//求数组是否存在 |nums[i] - nums[j]| <= t && |i - j| <= k True Or False 
class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		map<int, int> m;
		int j = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (i - j > k && m[nums[j]] == j) 
				m.erase(nums[j++]);
			
			//lower_bound()函数来找一个特定范围，就是大于或等于nums[i] - t的地方
			auto a = m.lower_bound(nums[i] - t);
			
			if (a != m.end() && abs(a->first - nums[i]) <= t) 
				return true;
			
			m[nums[i]] = i;
		}

		return false;
	}
};
