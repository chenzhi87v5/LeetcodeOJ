/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero. 
*/


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*1-mySolution: 三个for循环，超时, 时间复杂度n^3*/
/*
class Solution {
public:
	vector<vector<int> > threeSum(vector<int>& nums) {
		vector<vector<int> > result;
		for (int i = 0; i < nums.size(); i++) {
			for (int j = i + 1; j < nums.size(); j++) {
				for (int k = j + 1; k < nums.size(); k++) {
					if ((nums[i] + nums[j] + nums[k]) == 0){
						vector<int> tmp;
						int min_n = min(min(nums[i], nums[j]), nums[k]);
						int max_n = max(max(nums[i], nums[j]), nums[k]);
						int mid_n = 0 - min_n - max_n;
						tmp.push_back(min_n);
						tmp.push_back(mid_n);
						tmp.push_back(max_n);
						result.push_back(tmp);
					}
				}
			}
		}
		return result;
	}
};
*/

/*2-Answers:*/
//先排序，然后左右夹逼，复杂度n^2
//这个方法可以推广到k-sum， 先排序，然后做k-2次循环，在最内层循环左右夹逼，时间复杂度是max(nlogn,n^(k-1))
//超时
/*
class Solution {
public:
	vector<vector<int> > threeSum(vector<int>& nums) {
		vector<vector<int> > result;
		if (nums.size() < 3)
			return result;
		sort(nums.begin(), nums.end()); //STL标准库算法 sort排序
		const int target = 0;

		auto last = nums.end();
		for (auto a = nums.begin(); a < prev(last, 2); a++) { //pre() 用法
			auto b = next(a);
			auto c = prev(last);
			while (b < c) {
				if (*a + *b + *c < target) {
					b++;
				}else if (*a + *b + *c > target) {
					c--;
				} else {
					result.push_back({*a, *b, *c});
					b++;
					c--;
				}
			}
		}
		sort(result.begin(), result.end());
		result.erase(unique(result.begin(), result.end()), result.end()); //string erase()函数用法，STL unique去重
		return result;
	}
};
*/
/*3-JiuZhang answers:*/
//复杂度n^2 ,关键点是两个去重if,还是夹逼法
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++) {
			if (i > 0 && nums[i] == nums[i - 1]) { //去重
				continue;
			}
			//Two Sum
			int start = i + 1, end = nums.size() - 1;
			int target = -nums[i];
			while (start < end) {
				if (start > i + 1 && nums[start] == nums[start - 1]) { //去重
					start++;
					continue;
				}
				if (nums[start] + nums[end] < target) {
					start++;
				} else if (nums[start] + nums[end] > target) {
					end--;
				} else {
					result.push_back({nums[i], nums[start], nums[end]});
					start++;
				}
			}
		}
	
		return result;
	}
};

int main()
{
	return 0;
}
