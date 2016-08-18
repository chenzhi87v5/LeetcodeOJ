/*
struct Node{
	int value;
	Node *left;
	Node *right;
	Node *leaf;	//大多数情况为NULL，少数情况指向任意节点
}
实现这样的“树”的拷贝 使用map结构
*/

Node* cloneTree(Node* root, Node *copy, map<Node*, Node*> &cmap, map<Node*, Node*> &nmap) {
	if (!root)
		return NULL;
	copy = new Node(root->value);
	
	
	if (root->left)
		copy->left = clone(root->left, copy->left);
	if (root->right)
		coyt->right = clone(root->right, copy->right);
	
	nmap[root] = copy;
	if (root->leaf)
		cmap[root] = copy;
	return copy;
}

int cloneLeaf(map<Node*, Node*> &cmap, map<Node*, Node*> &nmap) {
	for (auto a : cmap) {
		a.second->leaf = nmap[a.first->leaf];
	}
	return 0;
}
