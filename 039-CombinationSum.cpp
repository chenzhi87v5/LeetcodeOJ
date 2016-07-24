//Combination Sum 组合之和
/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers 
sums to T.
The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.

For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 
*/


//递归法 深度优先算法 
// 时间复杂度O(n!)，空间复杂度O(n)
/*
像这种结果要求返回所有符合要求解的题十有八九都是要利用到递归，而且解题的思路都大同小异
相类似的题目有 
	       Path Sum II 二叉树路径之和之二，
	       Subsets II 子集合之二，
	       Permutations 全排列，
	       Permutations II 全排列之二，
	       Combinations 组合项等等，

如果仔细研究这些题目发现都是一个套路，都是需要另写一个递归函数，这里我们新加入三个变量，start记录当前的递归到的下标，
intermediate为一个解，result保存所有已经得到的解，每次调用新的递归函数时，此时的target要减去当前数组的的数，具体看代码如下： 
*/
class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> result;  //最终结果
		vector<int> intermediate;     //中间结果
		sort(candidates.begin(), candidates.end()); 

		dfs(candidates, target, 0, intermediate, result);
		return result;
	}

private:
	void dfs(vector<int>& nums, int gap, int start, vector<int>& intermediate, vector<vector<int>>& result) {
		if(gap == 0) {  //找到一个合法解
			result.push_back(intermediate);
			return;
		}
		for (size_t i = start; i < nums.size(); i++) {
			if (gap < nums[i]) //剪枝
				return;

			intermediate.push_back(nums[i]); //执行扩展动作
			dfs(nums, gap - nums[i], i, intermediate, result);
			intermediate.pop_back(); //撤销动作
		}
	}
};

