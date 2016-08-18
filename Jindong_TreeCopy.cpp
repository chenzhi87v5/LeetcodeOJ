/*
struct Node{
	int value;
	Node *left;
	Node *right;
	Node *leaf;	//大多数情况为NULL，少数情况指向任意节点
}
实现这样的“树”的拷贝 使用map结构
*/

Node* cloneTree(Node* root, Node *copy) {
	if (!root)
		return NULL;
	copy = new Node(root->value);
	
	if (root->left)
		copy->left = clone(root->left, copy->left);
	if (root->right)
		coyt->right = clone(root->right, copy->right);
	//加上 map 复制叶节点
	return copy;
}
