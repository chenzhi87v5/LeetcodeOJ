//Intersection of Two Arrays 两个数组相交
/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.
*/

/*
这道题让我们找两个数组相同的部分，难度不算大，我们可以用个set把nums1都放进去，然后遍历nums2的元素，如果在set中存在，说明是公共部分，加入结果的set中，最后再把结果转为vector的形式即可： 
*/
class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		set<int> s(nums1.begin(), nums1.end()), res;    //set使用 初始化
		for (auto a : nums2) {
			if (s.count(a))                         //count
				res.insert(a);
		}

		return vector<int>(res.begin(), res.end());    //vector初始化
	}
};
