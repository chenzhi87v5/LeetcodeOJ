//Subsets II 子集合之二
/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note:
	Elements in a subset must be in non-descending order.
	The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,2], a solution is:

[
 [2],
 [1],
 [1,2,2],
 [2,2],
 [1,2],
 []
]
*/
/*
这道子集合之二是之前那道 Subsets 子集合 的延伸，这次输入数组允许有重复项，其他条件都不变，只需要在之前那道题解法的基础上稍
加改动便可以做出来，我们先来看非递归解法，拿题目中的例子[1 2 2]来分析，根据之前 Subsets 子集合 里的分析可知，当处理到第一个
2时，此时的子集合为[], [1], [2], [1, 2]，而这时再处理第二个2时，如果在[]和[1]后直接加2会产生重复，所以只能在上一个循环生成
的后两个子集合后面加2，发现了这一点，题目就可以做了，我们用last来记录上一个处理的数字，然后判定当前的数字和上面的是否相同，
若不同，则循环还是从0到当前子集的个数，若相同，则新子集个数减去之前循环时子集的个数当做起点来循环，这样就不会产生重复了，
代码如下： 
整个添加的顺序为：

[]
[1]
[2]
[1 2]
[2 2]
[1 2 2]
*/
class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int> > res(1);
		sort(nums.begin(), nums.end());
		int size = 1, last = nums[0];
		
		for (int i = 0; i < nums.size(); ++i) {
			if (last != nums[i]) {
				last = nums[i];
				size = res.size();
			}
			int newSize = res.size();
			for (int j = newSize - size; j < newSize; ++j) {
				res.push_back(res[j]);
				res.back().push_back(nums[i]);
			}
		}

		return res;
	}
}

//对比Subsets 题无重复元素相当于每个元素只能选0或者1次，这里扩充到每个元素可以选0到若干次
class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());

		vector<vector<int>> result;
		vector<int> path;

		dfs(nums, nums.begin(), path, result);

		return result;
	}
private:
	static void dfs(const vector<int> &nums, vector<int>::iterator start, vector<int> &path, vector<vector<int>>&result) {
		result.push_back(path); //加入path

		for(auto i = start; i < nums.end(); i++) {
			if (i != start && *i == *(i - 1))  //重复元素滤过
				continue;
			path.push_back(*i);
			dfs(nums, i + 1, path,result);
			path.pop_back();
		}
	}
};
