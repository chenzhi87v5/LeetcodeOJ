//模仿矩阵输出 By chenzhi  百度云面试题

#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> > nnmatrix(int n) {
	vector<vector<int> > vec(n, vector<int>(n, 1));
	if (n == 1)
		return vec;
	int number = 2;
	bool tag = true;
	for (int i = 2; i <= n; i++ ) {
		if (tag) {
			for (int j = 0 ; j < i; j++ ) {
				vec[j][i - 1] = number++;
			}
			for (int j = i - 2; j >= 0; j-- ) {
				vec[i - 1][j] = number++;
			}
			tag = !tag;
		} else {
			for (int j = 0; j < i; j++) {
				vec[i - 1][j] = number++;
			}
			for (int j = i - 2; j >= 0; j--) {
				vec[j][i - 1] = number++;
			}
			tag = !tag;
		}
	}

	return vec;
}

int main() {
	
	int n = 2;
	vector<vector<int> > res = nnmatrix(n);
	
	for (int i = 0 ; i < n ; i++) {
		for (int j = 0; j < n; j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
}
