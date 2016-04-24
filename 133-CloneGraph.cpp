/*
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

	1.First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
	2.Second node is labeled as 1. Connect node 1 to node 2.
	3.Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
    	 / \
	 \_/
*/
/**
  * Definition for undirected graph.
  * struct UndirectedGraphNode {
  *     int label;
  *     vector<UndirectedGraphNode *> neighbors;
  *     UndirectedGraphNode(int x) : label(x) {};
  * };
  */

//1-:广度优先遍历或深度优先遍历均可
//DFS 时间复杂度n 空间复杂度n
//STL: unordered_map<*, *> 哈希map是一种关联容器，通过键值和映射值存储元素。允许根据键值快速检索各个元素

class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (node == NULL)
			return NULL;
		//键值是原始节点，映射值是复制节点
		unordered_map<const UndirectedGraphNode *, UndirectedGraphNode *> copied;
		clone(node, copied);

		return copied[node];	
	}
private:
	//DFS 注意unorder_map存储的是指针
	static UndirectedGraphNode* clone(const UndirectedGraphNode *node, 
			unordered_map<const UndirectedGraphNode *, UndirectedGraphNode *> &copied) {
		//复制节点已经存储hash map中
		if (copied.find(node) != copied.end())
			return copied[node];
		
		//复制节点
		UndirectedGraphNode *new_node = new UndirectedGraphNode(node->label);
		copied[node] = new_node;
		//复制node节点下neighbors节点元素
		for (auto nbr : node->neighbors)
			new_node->neighbors.push_back(clone(nbr, copied));
		
		return new_node;
	}
};

//BFS 时间复杂度n 空间复杂度n
//使用队列
class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (node == NULL)
			return NULL;
		unordered_map<const UndirectedGraphNode *, UndirectedGraphNode *> copied;
		//在队列q中节点已经复制，但是neighbors还没有
		queue<const UndirectedGraphNode *> q;
		q.push(node);
		copied[node] = new UndirectedGraphNode(node->label);
		while (!q.empty()) {
			const UndirectedGraphNode *cur = q.front();
			q.pop();
			for(auto nbr : cur->neighbors) {
				if (copied.find(nbr) != copied.end()) {
					copied[cur]->neighbors.push_back(copied[nbr]);
				} else {
					UndirectedGraphNode *new_node = new UndirectedGraphNode(nbr->label);
					copied[nbr] = new_node;
					copied[cur]->neighbors.push_back(new_node);
					q.push(nbr);
				}
			}
		}

		return copied[node];
	}
};
