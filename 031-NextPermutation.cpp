//Next Permutation 下一个排列
/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
The replacement must be in-place, do not allocate extra memory.
Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/
/*理解"下一个排序算法"算法过程与思想:寻找比当前排列顺序大的下一个相邻排列*/
//首先从后先前找到第一个降序的数字A，再从后向前找到一个个大于A的数字B，交换A与B的值，翻转B值后面的排列，最终即为下一个排列
/*
这道题让我们求下一个排列顺序，有题目中给的例子可以看出来，如果给定数组是降序，则说明是全排列的最后一种情况，
则下一个排列就是最初始情况。我们再来看下面一个例子，有如下的一个数组

1　　2　　7　　4　　3　　1
下一个排列为：
1　　3　　1　　2　　4　　7

那么是如何得到的呢，我们通过观察原数组可以发现，如果从末尾往前看，数字逐渐变大，到了2时才减小的，然后我们再从后往前找
第一个比2大的数字，是3，那么我们交换2和3，再把此时3后面的所有数字转置一下即可，步骤如下：

1　　2,　7　　4　　3　　1

1　　2,　7　　4　　3, 　1

1　　3,　7　　4　　2, 　1

1　　3　 1,　 2,　 4,   7,
*/
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int i, j, len = nums.size();
		for (i = len - 2; i >= 0; i--) {
			if (nums[i + 1] > nums[i]) {
				for (j = len - 1; j >= i; j--) {
					if (nums[j] > nums[i])
						break;
				}
				swap(nums[i], nums[j]);            		//STL swap
				reverse(nums.begin() + i + 1, nums.end()); 	//STL reverse
				return;
			}
		}
		reverse(nums.begin(), nums.end());
		return;
	}
};
