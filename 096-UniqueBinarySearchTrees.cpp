//Unique Binary Search Trees 独一无二的二叉搜索树
/*Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/
/*数学规律，递推公式
    以i为根的树的个数，等于左子树的个数乘以右子树的个数
    基于以下原则构建的BST树具有唯一性，以i为根节点的树 :左子树由[1, i-1]构成  右子树由[i+1, n]构成
时间复杂度n^2 空间复杂度n
这道题实际上是 Catalan Number卡塔兰数的一个例子
            1                        n = 1

	    
	2        1                   n = 2
       /          \
      1            2
      
      1         3     3      2      1           n = 3
       \       /     /      / \      \
        3     2     1      1   3      2
       /     /       \                 \
      2     1         2                 3
就跟斐波那契数列一样，我们把n = 0 时赋为1，因为空树也算一种二叉搜索树，那么n = 1时的情况可以看做是其左子树个数乘以右子树
的个数，左右字数都是空树，所以1乘1还是1。那么n = 2时，由于1和2都可以为跟，分别算出来，再把它们加起来即可。n = 2的情况可
由下面式子算出：

dp[2] =  dp[0] * dp[1]　　　(1为根的情况)

　　　　+ dp[1] * dp[0]　　  (2为根的情况)

同理可写出 n = 3 的计算方法：

dp[3] =  dp[0] * dp[2]　　　(1为根的情况)

　　　　+ dp[1] * dp[1]　　  (2为根的情况)

 　　　  + dp[2] * dp[0]　　  (3为根的情况)
*/
class Solution {
piublic:
	int numTrees(int n) {
		vector<int> f(n + 1, 0);

		f[0] = 1; //无节点 空树，只有一种BST
		f[1] = 1; //一个节点，只有一种BST

		for (int i = 2; i <= n ; i++) {
			for (int k = 0; k < i; k++) {
				f[i] += f[k1] * f[i - k - 1];
			}
		}
		
		return f[n];
	}
};
