//Combination Sum II 组合之和之二
/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.

For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 
*/
/*
这道题跟之前那道 Combination Sum 组合之和 本质没有区别，只需要改动一点点即可，之前那道题给定数组中的数字可以重复使用，
而这道题不能重复使用，只需要在之前的基础上修改两个地方即可，首先在递归的for循环里加上if (i > start && num[i] == num[i - 1]) 
continue; 这样可以防止result中出现重复项，然后就在递归调用dfs里面的参数换成i+1，这样就不会重复使用数组中的数字了，代码如下： 
*/
class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> result;  
		vector<int> intermediate;     
		sort(candidates.begin(), candidates.end());  //与039题不同，这里每个元素只能用一次

		dfs(candidates, target, 0, intermediate, result);
		return result;
	}

private:
	//使用nums[start, nums.size()) 之间的元素， 能找到的所有可能解
	void dfs(vector<int>& nums, int gap, int start, vector<int>& intermediate, vector<vector<int>>& result) {
		if(gap == 0) {  //找到一个合法解
			result.push_back(intermediate);
			return;
		}
		
		for (size_t i = start; i < nums.size(); i++) {
			//关键点！！！
			//确保nums[i]与nums[i - 1]不等, 防止出现重复项
			if (i > start && nums[i] == nums[i - 1])
				continue;
			if (gap < nums[i]) //剪枝
				return;

			intermediate.push_back(nums[i]); //执行扩展动作
			dfs(nums, gap - nums[i], i + 1, intermediate, result);  //变成 i + 1 保障不重复使用
			intermediate.pop_back(); //撤销动作
		}
	}
};

