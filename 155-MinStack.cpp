/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/

//1-:按题意 设置两个stack

class MinStack {
public:
	stack<int> stk, minstk;

	void push(int x) {
		stk.push(x);
		if (minstk.empty() || x <= minstk.top())
			minstk.push(x);
	}

	void pop() {
		int top = stk.top();
		stk.pop();
		if (top == minstk.top())
			minstk.pop();
	}

	int top() {
		return stk.top();
	}

	int getMin() {
		return minstk.top();
	}
};
