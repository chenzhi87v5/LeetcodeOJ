/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
*/

//1-:模仿 I

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

//2-：
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() < 3)
			return nums.size();

		int index = 2;
		for (int i = 2; i < nums.size(); i++) {
			if (nums[i] != nums[index - 2])
				nums[index++] = nums[i];
		}

		return index;
	}
};

//3-:
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int index = 0, n = nums.size();
		for (int i = 0; i < n; i++) {
			if (i > 0 && i < n - 1 && nums[i] == nums[i - 1] && nums[i] == nums[i + 1])
				continue;
			nums[index++] = nums[i];
		}
		return index;
	}
};
