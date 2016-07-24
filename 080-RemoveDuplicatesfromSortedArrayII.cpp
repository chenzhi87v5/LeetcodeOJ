//Remove Duplicates from Sorted Array II 有序数组中去除重复项之二
/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. 
It doesn't matter what you leave beyond the new length.
*/

//1-:模仿 Remove Duplicates from Sorted Array I
/*
这道题是之前那道 Remove Duplicates from Sorted Array 有序数组中去除重复项 的延续，这里允许最多重复的次数是两次，
那么我们就需要用一个变量count来记录还允许有几次重复
*/
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() < 3)
			return nums.size();

		int index = 0, count = 1;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[index] != nums[i]) {
				nums[++index] = nums[i];
				count = 1;
			} else if (nums[index] == nums[i] && count == 1) {
				nums[++index] = nums[i];
				count += 1;
			}
		}

		return index + 1;
	}
};
