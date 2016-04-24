/*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
	The solution is guaranteed to be unique.
*/

//1-:mySolution 首先想到的是n^2 的解法，对每个点进行模拟
//2-:时间复杂度为n的解法 空间复杂度 1
	//设置两个变量，sum判断当前有效性 total判断整个数组是否有解，有就返回通过sum 得到的下标，没有则返回-1。

class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int total = 0;
		int j = -1;
		for (int i = 0, sum = 0; i < gas.size(); i++) {
			sum += gas[i] - cost[i];
			total += gas[i] - cost[i];
			//判断当前有效性
			if (sum < 0) {
				j = i;
				sum = 0;
			}
		}

		//判断全局有效性
		return total >= 0 ? j + 1: -1;
	}
};
