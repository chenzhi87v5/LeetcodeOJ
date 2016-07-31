//3Sum 三数之和
/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero. 
*//*
这道题让我们求三数之和，比之前那道Two Sum 两数之和要复杂一些，我们还是要首先对原数组进行排序，然后开始遍历排序后的数组，
这里注意不是遍历到最后一个停止，而是到倒数第三个就可以了，然后我们还要加上重复就跳过的处理，对于遍历到的数，
我们用0减去这个数得到一个sum，我们只需要再之后找到两个数之和等于sum即可，这样一来问题又转化为了求two sum，
这时候我们一次扫描，找到了等于sum的两数后，加上当前遍历到的数字，按顺序存入结果中即可，然后还要注意跳过重复数字。
代码如下：
*/
//复杂度n^2 
//去重,夹逼法 或者用set 免去去重判断
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());
		
		for (int i = 0; i < int(nums.size() - 2); i++) {
			if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {   //去重
				int left = i + 1, right = nums.size() - 1, sum = 0 - nums[i];
				while (left < right) {
					if (nums[left] + nums[right] == sum) {
						res.push_back({nums[i], nums[left], nums[right]});
						while (left < right && nums[left] == nums[left + 1]) left++;  	//去重
						while (left < right && nums[right] == nums[right - 1]) right--; //去重
						left++;
						right--;
					} else if (nums[left] + nums[right] < sum) left++;
					else right--;
				}
			}
		}
		return res;
	}
};
