//Subsets 子集合
/*
Given a set of distinct integers, nums, return all possible subsets.
Note:
	Elements in a subset must be in non-descending order.
	The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,3], a solution is:

[
 [3],
 [1],
 [2],
 [1,2,3],
 [1,3],
 [2,3],
 [1,2],
 []
]
*/
/*
这道求子集合的问题，由于其要列出所有结果，按照以往的经验，肯定要是要用递归来做。这道题其实它的非递归解法相对来说更简单一点，
下面我们先来看非递归的解法，由于题目要求子集合中数字的顺序是非降序排列的，所有我们需要预处理，先给输入数组排序，然后再进一步
处理，最开始我在想的时候，是想按照子集的长度由少到多全部写出来，比如子集长度为0的就是空集，空集是任何集合的子集，满足条件，
直接加入。下面长度为1的子集，直接一个循环加入所有数字，子集长度为2的话可以用两个循环，但是这种想法到后面就行不通了，因为循环
的个数不能无限的增长，所以我们必须换一种思路。我们可以一位一位的网上叠加，比如对于题目中给的例子[1,2,3]来说，最开始是空集，
那么我们现在要处理1，就在空集上加1，为[1]，现在我们有两个自己[]和[1]，下面我们来处理2，我们在之前的子集基础上，每个都加个2，
可以分别得到[2]，[1, 2]，那么现在所有的子集合为[], [1], [2], [1, 2]，同理处理3的情况可得[3], [1, 3], [2, 3], [1, 2, 3], 再加
上之前的子集就是所有的子集合了，代码如下： 

整个添加的顺序为：

[]
[1]
[2]
[1 2]
[3]
[1 3]
[2 3]
[1 2 3]
*/
// Non-recursion
class Solution {
public:
	vector<vector<int> > subsets(vector<int> &nums) {
		vector<vector<int>> res(1);
		sort(nums.begin(), nums.end());
		
		for (int i = 0; i < nums.size(); i++ ) {
			int size = res.size();
			for (int j = 0; j < size; ++j) {
				res.push_back(res[j]);
				res.back().push_back(nums[i]);
			}
		}

		return res;
	}
}
/*
下面来看递归的解法，相当于一种深度优先搜索，参见网友JustDoIt的博客，由于原集合每一个数字只有两种状态，要么存在，要么不存在，
那么在构造子集时就有选择和不选择两种情况 
*/
//每个元素，都有两种选择，选或者不选 
//增量构造法,深搜,时间复杂度2^n 空间复杂度n
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> result;
		vector<int> path;
		subsets(nums, path, 0, result);

		return result;
	}

private:
	static void subsets(const vector<int>& nums, vector<int>& path, int step, vector<vector<int>>& result) {
		if (step == nums.size()) {
			result.push_back(path);
			return;
		}
		//实际处理~~~~
		//不选nums[step]
		subsets(nums, path, step + 1, result);

		//选nums[step]
		path.push_back(nums[step]);
		subsets(nums, path, step + 1, result);
		path.pop_back();
	}
};
