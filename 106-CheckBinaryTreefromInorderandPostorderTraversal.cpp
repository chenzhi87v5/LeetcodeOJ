//判断二叉树中序和后序遍历是否正确
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	bool checkTree(vector<int>& inorder, vector<int>& postorder) {
		if (inorder.size() != postorder.size())
			return false;
		return checkTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
	}
	
	bool checkTree(vector<int> &inorder, int iLeft, int iRight, vector<int> &postorder, int pLeft, int pRight) {
		if (iLeft > iRight || pLeft > pRight) return true;
		int cur = postorder[pRight];
		
		int i = 0;
		for (i = iLeft; i <= iRight; ++i) {
			if (inorder[i] == cur) break;
		}
		if (i > iRight )
			return false;
		
		return  checkTree(inorder, iLeft, i - 1, postorder, pLeft, pLeft + i - iLeft - 1)
			&& checkTree(inorder, i + 1, iRight, postorder, pLeft + i - iLeft, pRight - 1);
	}
};

int main() {
	Solution A;
	vector<int> inorder = {2, 2, 4, 7, 3, 5, 6, 8};
	vector<int> postorder = {7, 4, 2, 5, 8, 6, 3, 1};
	
	cout << A.checkTree(inorder, postorder) << endl;
	return 0;
}


