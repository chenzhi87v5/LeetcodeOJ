//Best Time to Buy and Sell Stock 买卖股票的最佳时间
/*
Say you have an array for which the ith element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an 
algorithm to find the maximum profit.
*/

/*
贪心法：分别找到价格最低和最高的一天，低进高出，注意最低的一天要在最高的一天之前。
时间复杂度 n 空间复杂度 1
*/
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() < 2)   //参数检测
			return 0;

		int profit = 0; 	 //差价，也就是利润
		int cur_min = prices[0]; //当前最小

		//一个循环
		for (int i = 1; i < prices.size(); i++) {
			profit = max(profit, prices[i] - cur_min); //当前最大利润
			cur_min = min(cur_min, prices[i]);         //价格最小
		}
	
		return profit;
	}
};
