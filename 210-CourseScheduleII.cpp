//Course Schedule II 课程清单之二
/*  
There are a total of n courses you have to take, labeled from 0 to n - 1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, 
which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to 
finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, 
return an empty array.

For example:
2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order 
is [0,1]

4, [[1,0],[2,0],[3,1],[3,2]]
There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and
2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. Another correct ordering is
[0,2,1,3].

Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is 
represented.

Hints:

This problem is equivalent to finding the topological order in a directed graph. If a cycle exists, no topological order 
exists and therefore it will be impossible to take all courses.
Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological 
Sort.

Topological sort could also be done via BFS.
*/

//与207题类似 拓扑排序 有向图问题
class Solution {
public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		
		vector<int> result_1;  
		vector<int> result_2;

		vector<vector<int>> graph(numCourses, vector<int>(0)); //每个图节点下一个指向
		vector<int> inDegree(numCourses, 0);                   //每个节点的入度情况
	
		//graph存储每个节点指向的节点列表，inDegree表示每个节点入度情况
		for (auto u : prerequisites) {
			graph[u.second].push_back(u.first);
			++inDegree[u.first];
		}

		queue<int> que; //队列存储入度为0的节点
		for (int i =0; i < numCourses; i++) {
			if (inDegree[i] == 0)
				que.push(i);
		}

		while(!que.empty()) {
			int u = que.front();  //u入度为0 出度可能不为0节点
			
			result_1.push_back(u);  //入度为0的节点加入结果集
			
			que.pop();
			for (auto v : graph[u]) {  //访问每一个 由u 指向 v的节点，即v的入度为u的节点，v入度减一
				--inDegree[v];
				if (inDegree[v] == 0)
					que.push(v);
			}
		}

		//判断最后还有入度不为0的节点的话，说明有环，否则无环
		for (int i = 0; i< numCourses; i++) {
			if (inDegree[i] != 0)
				return result_2;
		}

		return result_1;
	}
};
