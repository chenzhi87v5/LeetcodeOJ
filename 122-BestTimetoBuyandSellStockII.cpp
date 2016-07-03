//Best Time to Buy and Sell Stock II 买股票的最佳时间之二
/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

//1-:贪心法，低进高出，把所有正的价格差价相加起来。
/*
这道跟之前那道Best Time to Buy and Sell Stock 买卖股票的最佳时间很类似，但都比较容易解答。这道题由于可以无限次买入和卖出。我们都知道炒股想挣钱当然是低价买入高价抛出，那么这里我们只需要从第二天开始，如果当前价格比之前价格高，则把差值加入利润中，因为我们可以昨天买入，今日卖出，若明日价更高的话，还可以今日买入，明日再抛出。以此类推，遍历完整个数组后即可求得最大利润。代码如下： 
*/
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
