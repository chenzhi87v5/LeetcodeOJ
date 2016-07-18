//H-Index II 求H指数之二
/*
Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize your algorithm?

Hint:

Expected runtime complexity is in O(log n) and the input is sorted.
*/

//二分查找法 H-Index I 扩展
class Solution {
public:
	int hIndex(vector<int>& citations) {
		if (citations.size() == 0)  //边界检测
			return 0;
		
		int n = citations.size();
		int low = 0, high = n - 1;
		
		while (low <= high) {
			int mid = low + (high - low) / 2;
			
			if (citations[mid] == n - mid)
				return n - mid;
			else if (citations[mid] < n - mid)
				low = mid + 1;
			else
				high = mid - 1;
		}

		return n - low;        //关键
	}
};
