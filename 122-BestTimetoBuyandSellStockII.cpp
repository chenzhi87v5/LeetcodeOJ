/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

//1-:贪心法，低进高出，把所有正的价格差价相加起来。

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int sum = 0;
		for (int i = 1; i < prices.size(); i++) {
			int diff = prices[i] - prices[i - 1];
			if (diff > 0)
				sum += diff;
		}
		return sum;
	}
};
