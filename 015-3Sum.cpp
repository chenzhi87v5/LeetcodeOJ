//3Sum 三数之和
/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero. 
*/

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
//虽然超时,但是代码中有些STL 用法值得借鉴

/*
class Solution {
public:
	vector<vector<int> > threeSum(vector<int>& nums) {
		vector<vector<int> > result;
		if (nums.size() < 3)
			return result;
		
		sort(nums.begin(), nums.end());   				//STL标准库算法 sort排序
		const int target = 0;

		auto last = nums.end();
		for (auto a = nums.begin(); a < prev(last, 2); a++) {        	//pre() 用法
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
		result.erase(unique(result.begin(), result.end()), result.end());	//erase()函数用法，STL unique去重
		
		return result;
	}
};

/*
STL unique http://www.cnblogs.com/heyonggang/archive/2013/08/07/3243477.html
unique的作用是从输入序列中“删除”所有相邻的重复元素,其实它并不真正把重复的元素删除，是把重复的元素移到后面去了,返回去重后最后一个元素的地址
erase() 真正删除操作，
去重三步骤：先sort 再unique 后erase ,均是两个参数迭代器
*/

/*
这道题让我们求三数之和，比之前那道Two Sum 两数之和要复杂一些，我们还是要首先对原数组进行排序，然后开始遍历排序后的数组，这里注意不是遍历到最后一个停止，而是到倒数第三个就可以了，然后我们还要加上重复就跳过的处理，对于遍历到的数，我们用0减去这个数得到一个sum，我们只需要再之后找到两个数之和等于sum即可，这样一来问题又转化为了求two sum，这时候我们一次扫描，找到了等于sum的两数后，加上当前遍历到的数字，按顺序存入结果中即可，然后还要注意跳过重复数字。代码如下：
*/
//复杂度n^2 
//去重,夹逼法
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
