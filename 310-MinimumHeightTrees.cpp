//Minimum Height Trees 最小高度树
/*
For a undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and return a list of their root labels.

Format
The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of undirected edges (each edge is a pair of labels).
You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

Example 1:
Given n = 4, edges = [[1, 0], [1, 2], [1, 3]]

        0
	|
	1
       / \
      2   3
      
return [1]

Example 2:
Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

	0  1  2
	 \ | /
	   3
	   |
	   4
	   |
	   5

return [3, 4]

Hint:
	How many MHTs can a graph have at most?
Note:
(1) According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.”
(2) The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.
*/

/*
由于LeetCode中的树的题目主要都是针对于二叉树的，而这道题虽说是树但其实本质是想考察图的知识，这道题刚开始在拿到的时候，我最先想到的解法是遍历的点，以每个点都当做根节点，算出高度，然后找出最小的，但是一时半会又写不出程序来，于是上网看看大家的解法，发现大家推崇的方法是一个类似剥洋葱的方法，就是一层一层的褪去叶节点，最后剩下的一个或两个节点就是我们要求的最小高度树的根节点，这种思路非常的巧妙，而且实现起来也不难，跟之前那到课程清单的题一样，我们需要建立一个图g，是一个二维数组，其中g[i]是一个一维数组，保存了i节点可以到达的所有节点。还需要一个一维数组d用来保存各个节点的入度信息，其中d[i]表示i节点的入度数。我们的目标是删除所有的叶节点，叶节点的入度为1，所以我们开始将所有入度为1的节点(叶节点)都存入到一个队列queue中，然后我们遍历每一个叶节点，通过图来找到和其相连的节点，将该节点的入度减1，如果该节点的入度减到1了，说明此节点也也变成一个叶节点了，加入队列中，再下一轮删除。那么我们删到什么时候呢，当节点数小于等于2时候停止，此时剩下的一个或两个节点就是我们要求的最小高度树的根节点啦，参见代码如下： 
*/
//剥洋葱法
class Solution {
public:
	vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
		//参数检查
		if (n == 0)
			return {};
		if (n == 1)         
			return {0};

		vector<int> res;    				//存储结果集
		vector<int> d(n, 0);  				//入度表 d
		vector<vector<int>> g(n, vector<int>()); 	//图g
		queue<int> q; 					//队列
		
		for(auto a : edges) {                            //图g 与入度表d 初始化
			g[a.first].push_back(a.second);          //pair<int, int> 访问a.fisrt、a.second
			d[a.first]++;
			g[a.second].push_back(a.first);
			d[a.second]++;
		}

		for (int i = 0; i < n; i++) {      //叶节点入度
			if (d[i] == 1)
				q.push(i);
		}

		while (n > 2) {                   //剥洋葱 删除叶节点
			int sz = q.size();
			for (int i = 0; i < sz; i++) {
				int t = q.front();
				q.pop();
				n--;
				for (int j : g[t]) {
					d[j]--;
					if (d[j] == 1) q.push(j);
				}
			}
		}

		while (!q.empty()) {
			res.push_back(q.front());
			q.pop();
		}

		return res;
	}
};
