#include<iostream>
#include<vector>

using namespace std;

//Time Complexity is O(n^2)
class Solution {
public:
	int maximumXor(int n, vector<int>& nums) {
		// parameter checking
		if (n == 0 || nums.size() == 0 || n != (int)nums.size())
			return 0;
		if (nums.size() == 1)
			return nums[0];
		
		int right = 0, left = n - 1;
		int ans = 0;   		
		int curr_r = 0, curr_l = 0, curr_m = 0;
		for (; right < n - 1; right++) {
			curr_r ^= nums[right];
			
			for (left = n - 1; left > 0 && right < left; left--) {
				curr_l ^= nums[left];
				curr_m  = curr_r ^ curr_l;
				ans = max(ans, max(curr_m, max(curr_r, curr_l)));
			}
		}

		return ans;
	}
};

//Main function 
int main() {
	//vector<int> nums = {0, 1, 2, 12, 7, 6};
	int n = 0;
	vector<int> nums;
	cout << "Please enter a number n :" << endl;
	cin >> n;
	cout << "Please enter n numbers separated by space:" << endl;
	for (int i = 0 ; i < n; i++) {
		int temp;
		cin >> temp;
		nums.push_back(temp);
	}
	
	Solution A;
	int ans = A.maximumXor(n, nums);
	cout << "Answer:" << ans << endl;

	return 0;
}
