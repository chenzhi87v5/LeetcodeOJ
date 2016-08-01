//Restore IP Addresses 复原IP地址
/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",
return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/
//一是只要遇到字符串的子序列或配准问题首先考虑动态规划DP，二是只要遇到需要求出所有可能情况首先考虑用递归。
class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> result;
		string ip;  		//中间结果

		dfs(s, 0, 0, ip, result);

		return result;
	}
private:
	void dfs(string s, size_t start, size_t step, string ip, vector<string> &result) {
		if (start == s.size() && step == 4) {  	//找到一个合法解
			ip.resize(ip.size() - 1);       //删除最后一点'.'
			result.push_back(ip);
			return;
		}

		if (s.size() - start > (4 - step) * 3)
			return; 			//剪枝，余下字符ip不能容下
		if (s.size() - start < (4 - step))
			return;  			//剪枝，余下字符不够ip书写
		
		int num = 0;
		for (size_t i = start; i < start + 3; i++) {
			num = num * 10 + (s[i] - '0');

			if (num <= 255) {    		//当前节点合法，可以继续往下递归
				ip += s[i];
				dfs(s, i + 1, step + 1, ip + '.', result);
			}
			if (num == 0)  			//不允许前缀为0,但是允许单个0
				break;
		}
	}
};
