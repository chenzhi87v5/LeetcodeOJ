/*利用快排求无序数组的第K大的元素*/
#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> &nums, int start, int end) {
	int key = nums[start];
	while (start < end) {
		while (start < end && nums[end] > key)
			end--;
		if (start < end)
			nums[start++] = nums[end];
		while (start < end && nums[start] < key)
			start++;
		if (start < end)
			nums[end--] = nums[start];
	
	}
	nums[start] = key;
	return start;
}

int getKlargeast(vector<int> &nums, int k) {
	if (nums.empty() || k < 0 || k > nums.size())
		return -1;
	int start = 0;
	int end = nums.size() - 1;
	int index = partition(nums, start, end);
	while (index != k - 1) {
		if (index > k - 1) {
			end = index - 1;
			index = partition(nums, start, end);
		} else {
			start = index + 1;
			index = partition(nums, start, end);
		}
	}
}

/*测试程序*/
int main() {
	vector<int> nums = {7, 2, 5, 4, 3, 6, 1};
	int Idx = getKlargeast(nums, 7);
	cout << nums[Idx] << endl;
	
	return 0;
}
