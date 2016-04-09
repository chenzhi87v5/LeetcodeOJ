/*
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
*/

/*1-mySolution:*/
//直接使用STL
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {

		//解法一 STL
		/*nums.erase(unique(nums.begin(), nums.end()), nums.end());
		 *return nums.size();
		 */
		//解法二 STL
		/*return distance(nums.begin(), unique(nums.begin(), nums.end()));
		 */

		//解法三  不使用STL 
		if (nums.size() == 0)
			return 0;
		if (nums.size() == 1)
			return 1;
		int index = 0;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[index] != nums[i])
				nums[++index] = nums[i];
		}
		return index + 1;
	}
};
