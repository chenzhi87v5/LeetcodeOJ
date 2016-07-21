//Climbing Stairs 爬梯子问题
/*
You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

/*
这个爬梯子问题最开始看的时候没搞懂是让干啥的，后来看了别人的分析后，才知道实际上跟斐波那契数列非常相似，假设梯子有n层，那么如何爬到第n层呢，因为每次只能怕1或2步，那么爬到第n层的方法要么是从第n-1层一步上来的，要不就是从n-2层2步上来的，所以递推公式非常容易的就得出了：dp[n] = dp[n-1] + dp[n-2]。 由于斐波那契额数列的求解可以用递归，所以我最先尝试了递归，代码如下： 
*/
//斐波那契数列 f(n) = f(n - 1) + f(n - 2)
class Solution {
public:
	int climbStairs(int n) {
		 vector<int> res(n+1);
		 res[0] = 1;
	         res[1] = 1;
		 for (int i = 2; i <= n; ++i) 
			 res[i] = res[i - 1] + res[i - 2];
		 return res[n];
	}
};
