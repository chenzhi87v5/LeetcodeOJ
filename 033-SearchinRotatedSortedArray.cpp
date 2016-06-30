//Search in Rotated Sorted Array 在旋转有序数组中搜索
/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
You are given a target value to search. If found in the array return its index, otherwise return -1.
You may assume no duplicate exists in the array.
*/

//1-:二分查找，难度在于左右边界的确定
/*
这道题让在旋转数组中搜索一个给定值，若存在返回坐标，若不存在返回-1。我们还是考虑二分搜索法，但是这道题的难点在于我们不知道原数组在哪旋转了，我们还是用题目中给的例子来分析，对于数组[0 1 2 4 5 6 7] 共有下列七种旋转方法：

0　　1　　2　　 4　　5　　6　　7

7　　0　　1　　 2　　4　　5　　6

6　　7　　0　　 1　　2　　4　　5

5　　6　　7　　 0　　1　　2　　4

4　　5　　6　　7　　0　　1　　2

2　　4　　5　　6　　7　　0　　1

1　　2　　4　　5　　6　　7　　0

二分搜索法的关键在于获得了中间数后，判断下面要搜索左半段还是右半段，我们观察上面0分界的两部分，由此我们可以观察出规律，如果中间的数大于最左边的数，则左半段是有序的，若中间数小于最左边数，则右半段是有序的，我们只要在有序的半段里用首尾两个数组来判断目标值是否在这一区域内，这样就可以确定保留哪半边了，代码如下：
*/
class Solution {
public:
	int search(vector<int>& nums, int target) {
		int first = 0, last = nums.size();
		while (first != last) {
			int mid = (first + last) / 2;
			
			if (nums[mid] == target) {       			    //找到目标值
				return mid;
			} else if (nums[first] <= nums[mid]) {  		    //左值小于等于中值
				
				if (nums[first] <= target && target < nums[mid])    
					last = mid;
				else
					first = mid + 1;
			
			} else if (nums[first] > nums[mid]) {                       //左值大于中值
				
				if (nums[mid] < target && target <= nums[last - 1])
					first = mid + 1;
				else
					last = mid;
			}
		}

		return -1;
	}
};
