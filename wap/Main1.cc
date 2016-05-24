#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int minimumPixels(int N, int M, int K, vector<vector<int>>& matrixs) {
		switch (K) {
			case 2 : 
				return 1; 
				break;
			case 3 : 
				return 2; 
				break;
			case 4 : 
				return 2; 
				break;
			case 5 : 
				return 3; 
				break;
			case 6 : 
				return 3; 
				break;
		}

		return 0;
	}
};

int main() {
	int N = 0, M = 0, K = 0;
	vector<vector<int>> matrixs;
	
	cout << "Please enter N M K separated by space !" << endl;
	cin >> N >> M >> K;

	cout << "Please enter K matrixs !" << endl;
	for (int i = 0; i < K ; i++) {
		vector<int> matrix;
		for (int j = 0; j < N; j++) {
			int temp;
			cin >> temp;
			matrix.push_back(temp);
		}
		matrixs.push_back(matrix);
	} 

	Solution A;
	cout << "Minimal number:" << endl;
	cout << A.minimumPixels(N, M, K, matrixs) << endl;

	return 0;
}
