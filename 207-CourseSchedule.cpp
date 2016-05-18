/* 
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.

click to show more hints.

Hints:
This problem is equivalent to finding if a cycle exists in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
Topological sort could also be done via BFS.
*/

//课程安排：有向图里面找环，拓扑排序
//有点难
/*
 拓扑排序。用一个队列存入度为0的节点，依次出队，将与出队节点相连的节点的入度减1，如果入度减为0，将其放入队列中，直到队列为空。如里最后还有入度不为0的节点的话，说明有环，否则无环。
 */
class Solution {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
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
				return false;
		}

		return true;
	}
};
