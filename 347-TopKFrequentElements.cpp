//Top K Frequent Elements 前K个高频元素
/*
Given a non-empty array of integers, return the k most frequent elements.
For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].
*/

/*
这道题给了我们一个数组，让我们统计前k个高频的数字，那么对于这类的统计数字的问题，首先应该考虑用哈希表来做，建立数字和其出现次数的映射，然后再按照出现次数进行排序。我们可以用堆排序来做，使用一个最大堆来按照映射次数从大到小排列，在C++中使用priority_queue来实现，默认是最大堆，参见代码如下： 
*/
//哈希表  堆排序 pririty_queue
class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> m;              //哈希表 建立数字和其出现次数的映射 unordered_map 
		priority_queue<pair<int, int>> q;       //最大堆来按照映射次数从大到小排列 priority_queue  
		vector<int> res;                        //结果集 

		for (auto a : nums)
			m[a]++;
		for (auto it : m)
			q.push({it.second, it.first});  //pair的使用 {a,b} or make_pair(a,b)
		for (int i = 0; i < k; i++) {
			res.push_back(q.top().second);
			q.pop();
		}

		return res;
	}
};
