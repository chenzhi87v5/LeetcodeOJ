//Container With Most Water 装最多水的容器
/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.
*/

/*2-Answers: 时间复杂度n*/
//每个容器的面积取决于最短的木板 只需要一个循环足矣
//定义start和end两个指针分别指向数组的左右两端，然后两个指针向中间搜索，每移动一次算一个值和结果比较取较大的
//容器装水量的算法长乘以宽
class Solution {
public:
	int maxArea(vector<int>& height) {
		int start = 0;
		int end = height.size() - 1;
		int result = INT_MIN;
		
		while (start < end) {
			int area = min(height[end], height[start]) * (end - start);
			result = max(result, area);
			if (height[start] < height[end])
				start++;
			else
				end--;
		}
		return result;
	}
};
