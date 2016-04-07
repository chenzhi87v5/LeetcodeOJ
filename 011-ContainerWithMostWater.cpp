/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define INT_MIN 99999

/*1-mySolution: 时间复杂度n^2 超时*/
/*
class Solution {
public:
	int maxArea(vector<int>& height) {
		int max_r = 0;
		for (int i = 0; i < height.size() ; i++) {
			for (int j = i + 1; j < height.size(); j++) {
				max_r = max(max_r, (j - i) * min(height[i], height[j]));
			}
		}
		return max_r;
	}
};
*/

/*2-Answers: 时间复杂度n*/
//每个容器的面积取决于最短的木板 只需要一个循环足矣
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

int main() 
{
	return 0;
}
