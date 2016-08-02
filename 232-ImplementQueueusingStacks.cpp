//Implement Queue using Stacks 用栈来实现队列

/*Implement the following operations of a queue using stacks.
	push(x) -- Push element x to the back of queue.
	pop() -- Removes the element from in front of queue.
	peek() -- Get the front element.
	empty() -- Return whether the queue is empty.
Notes:
	You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, 
and is empty operations are valid.
	Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or 
deque (double-ended queue), as long as you use only standard operations of a stack.
	You may assume that all operations are valid (for example, no pop or peek operations will be called on an 
empty queue).
*/
//两个栈实现队列 使其中一个栈一直保持队列的排列顺序     //类似 两个队列实现栈 
class Queue {
private:
	stack<int> s1;
	stack<int> s2;
public:
	Queue() {
	}
	// Push element x to the back of queue.
	void push(int x) {
		s1.push(x);
	}
	//调整函数
	void adjust() {
		if(s2.empty()) {
			while (!s1.empty()) {
				s2.push(s1.top());
				s1.pop();
			}
		}
	}
	// Removes the element from in front of queue.
	void pop(void) {
		adjust();
		s2.pop();
	}
	// Get the front element.
	int peek(void) {
		adjust();
		int tmp = s2.top();
		return tmp;
	}
	// Return whether the queue is empty.
	bool empty(void) {
		return s1.empty() && s2.empty();
	}
};
